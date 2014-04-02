#include <stdio.h>
#include <string.h>
#include "memmanage.h"
#include "table.h"
#include "ui.h"

void
insertintoaddtable(struct tag_table *table, struct tag_record *record)
{
    int i, j;

    //find the proper position
    for (i = table->nrecords; i >= 1; i--)
    {
        if (table->records[i - 1].start <= record->start)
        {
            break;
        }
    }

    //now we need to move some data foreward
    for (j = table->nrecords; j >= i + 1; j--)
    {
        memcpy(&table->records[j], &table->records[j - 1], sizeof(struct tag_record));      
    }

    //now insert this record.
    memcpy(&table->records[i], record, sizeof(struct tag_record));

    //
    table->nrecords++;
}

/*
Function: 考虑g_del_table中，index与其前驱、后继是否为连续的空闲空间，进行整合，
           以获取更大的空闲空间，便于后续再分配
Param   : index

Return  : None

Effect  : 可能调用removefromtable，间接更新g_indexMAX_del

Caller: this function can only be called by insertintodeltable
*/
static void
reorganize(int index)
{
    int indexpre, indexaft;
    int sizepre,  sizeaft;
    int startpre, startaft;
    int size, start;

    struct tag_record record;
    
    //now we need to consider the probable free space reorganize. 
    size  = g_del_table.records[index].size;
    start = g_del_table.records[index].start;   
    
    //aft
    if ((index + 1) != g_del_table.nrecords)
    {
        indexaft = index + 1;  

        sizeaft  = g_del_table.records[indexaft].size;
        startaft = g_del_table.records[indexaft].start;

        if (startaft == start + size)
        {
            record.size  = size + sizeaft;
            record.start = start;

            updatetable(&g_del_table, index, &record);
            removefromtable(&g_del_table, indexaft);
            
            showinfo("reorganize space aft happens\r\n");
        }
    }
    
    //pre
    if (index != 0)
    {
        indexpre = index - 1;   

        sizepre  = g_del_table.records[indexpre].size;
        startpre = g_del_table.records[indexpre].start;
        
        if (start == startpre + sizepre)
        {
            //take care, may size already updated, we need to use g_del_table[index]
            record.size  = sizepre + g_del_table.records[index].size;
            record.start = startpre;

            updatetable(&g_del_table, indexpre, &record);
            removefromtable(&g_del_table, index);
            
            showinfo("reorganize space pre happens\r\n");
        }   
    } 
}


/*
    Yes, you may say this seems the same with the insertintoaddtable.
    Yes, it is, apart from the reorganize(index)
    U can make it more beautiful
*/
void
insertintodeltable(struct tag_table *table, struct tag_record *record)
{
    int i, j;
    
    //find the proper position
    for (i = table->nrecords; i >= 1; i--)
    {
        if (table->records[i - 1].start <= record->start)
        {
            break;
        }
    }
    
    //now we need to move some data foreward
    for (j = table->nrecords; j >= i + 1; j--)
    {
        memcpy(&table->records[j], &table->records[j - 1], sizeof(struct tag_record));      
    }
    
    //now insert this record.
    memcpy(&table->records[i], record, sizeof(struct tag_record));
    
    //
    table->nrecords++;

    //reorganize
    reorganize(i);
}


void
removefromtable(struct tag_table *table, int index)
{
    int nrecords;
    int i;

    nrecords = table->nrecords;

    for (i = index; i < nrecords - 1; i++)
    {
        memcpy(&table->records[i], &table->records[i+1], sizeof(struct tag_record));
    }
   
    memset(&table->records[nrecords - 1], 0, sizeof(struct tag_record));

    table->nrecords--;
}


void
updatetable(struct tag_table *table, int index, struct tag_record *record)
{
    table->records[index].size  = record->size;
    table->records[index].start = record->start;
}


int
gettable(int index, int *max)
{
    static int s_index_add = 0;
    static int s_index_del = 0;

    int table = -1;

    int size_add, start_add;
    int size_del, start_del;

    size_add    = -1;
    start_add   = -1;
    size_del    = -1;
    start_del   = -1;


    if (0 == index)
    {
        s_index_add = 0;
        s_index_del = 0;
    }

    if (0 != g_add_table.nrecords)
    {
        size_add        = g_add_table.records[s_index_add].size;
        start_add       = g_add_table.records[s_index_add].start;
    }
        
    if (0 != g_del_table.nrecords)
    {
        size_del        = g_del_table.records[s_index_del].size;
        start_del       = g_del_table.records[s_index_del].start;
    }
        
    if ((index >= start_add) && (index <= start_add + size_add))
    {
        *max = start_add + size_add;

        //now need to move toward
        s_index_add += 1;
        return ADD;
    }
    
    if ((index >= start_del) && (index <= start_del + size_del))
    {
        *max = start_del + size_del;

        //
        s_index_del += 1;
        return DEL;
    }

    //should not come to this point.
    return table;
}