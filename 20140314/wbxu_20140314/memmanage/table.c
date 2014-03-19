#include <stdio.h>
#include "memmanage.h"
#include "table.h"

/*
Function: 将(size, start)记录有序的插入到table[*max]中
　　  
Param	: table[max]
　　        size, start
　　        
Return  :  None.

Effect   : 更新*max;
*/
void
insertintoaddtable(int table[], int *max,  int size, int start)
{
    int i, j;

    //find the proper position
    for (i = *max; i >= 2; i -= 2)
    {
        if (table[i - 1] <= start)
        {
            break;
        }
    }

    //now we need to move some data foreward
    for (j = *max; j >= i + 2; j -= 2)
    {
        table[j + 1] = table[j - 1];
        table[j] = table[j - 2];
    }

    //now insert (size, start)
    table[i]     = size;
    table[i + 1] = start;

    *max += 2;
}

/*
Function: 考虑del_table中，index与其前驱、后继是否为连续的空闲空间，进行整合，
           以获取更大的空闲空间，便于后续再分配
Param   : index

Return  : None

Effect  : 可能调用removefromtable，间接更新indexMAX_del

Attention: this function can only be called by insertintodeltable
*/
void
reorganize(int index)
{
    int indexpre, indexaft;
    int sizepre,  sizeaft;
    int startpre, startaft;

    int size, start;

    
    //now we need to consider the probable free space reorganize.
    
    size  = del_table[index];
    start = del_table[index + 1];
   
    
    //aft
    if ((index + 2) != indexMAX_del)
    {
        indexaft = index + 2;        
        sizeaft  = del_table[indexaft];
        startaft = del_table[indexaft + 1];

        if (startaft == start + size)
        {
            updatetable(del_table, index, size + sizeaft, start);
            removefromtable(del_table, &indexMAX_del, indexaft);
            
            printf("reorganize space aft happens\r\n");
        }
    }
    
    //pre
    if (index != 0)
    {
        indexpre = index - 2;          
        sizepre  = del_table[indexpre];
        startpre = del_table[indexpre + 1];
        
        if (start == startpre + sizepre)
        {
            //take care, may size already updated, we need to use del_table[index]
            updatetable(del_table, indexpre, sizepre + del_table[index], startpre);
            removefromtable(del_table, &indexMAX_del, index);
            
            printf("reorganize space pre happens\r\n");
        }   
    } 
}


/*
Function: 将(size, start)记录有序的插入到table[*max]中, 并对del_table指示连续空闲空间进行整合
　　  
Param	:  table[*max]
　　        size, start
　　        
Return  :  None.

Effect   : 更新*max, 对del_table指示的连续空闲空间进行整合，进行再分配
*/
void
insertintodeltable(int table[], int *max, int size, int start)
{
    int i, j;
    
    //find the proper position
    for (i = *max; i >= 2; i -= 2)
    {
        if (table[i - 1] <= start)
        {
            break;
        }
    }
    
    //now we need to move some data foreward
    for (j = *max; j >= i + 2; j -= 2)
    {
        table[j + 1] = table[j - 1];
        table[j] = table[j - 2];
    }
    
    //now insert (size, start)
    table[i]     = size;
    table[i + 1] = start;
    
    *max += 2; 

    //reorganize
    reorganize(i);
}


/*
Function: 将index 所标识的(size, start)从table[*max]中删除, 并保证table的有序性。
　　  
Param	: table[*max]
　　        
Return  :  None.

Effect  : 更新*max;
*/
void
removefromtable(int table[], int *max, int index)
{
    int i;
    for (i = index; i <= *max - 4; i += 2)
    {
        table[i]     = table[i + 2];
        table[i + 1] = table[i + 3];    
    }

    table[*max - 1] = 0;
    table[*max - 2] = 0;

    *max -= 2;
}

/*
Function: 将table[index]所标识的(size, start)更新为新传入的值。
　　  
Param	: 
　　        
Return  :  None.

Effect  :  更新table
*/
void
updatetable(int table[], int index, int size, int start)
{
    table[index]        = size;
    table[index + 1]    = start;
}


/*
Function: get the table that index belongs to, and set the max value of this range.
*/
int
gettable(int index, int *max)
{
    static int index_add = 0;
    static int index_del = 0;

    int table = -1;

    int size_add, start_add;
    int size_del, start_del;

    size_add    = -1;
    start_add   = -1;
    size_del    = -1;
    start_del   = -1;


    if (0 == index)
    {
        index_add = 0;
        index_del = 0;
    }

    if (0 != indexMAX_add)
    {
        size_add        = add_table[index_add];
        start_add       = add_table[index_add + 1];
    }
        
    if (0 != indexMAX_del)
    {
        size_del        = del_table[index_del];
        start_del       = del_table[index_del + 1];
    }
        
    if ((index >= start_add) && (index <= start_add + size_add))
    {
        *max = start_add + size_add;

        //now need to move toward
        index_add += 2;
        return ADD;
    }
    
    if ((index >= start_del) && (index <= start_del + size_del))
    {
        *max = start_del + size_del;

        //
        index_del += 2;
        return DEL;
    }

    //should not come to this point.
    return table;
}