#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memmanage.h"
#include "fit.h"
#include "table.h"
#include "ui.h"

/*storage for your input. can only be dealed within file*/
#if defined(NO_USE_MALLOC) 
    static char g_chBuf[MAX_SPACE];
    static int g_indexMAX_buf;  //how many strings already stored into this buf. 
#endif

#if defined(USE_MALLOC_V1) 
    static char *g_chBuf = NULL;
    static int g_indexMAX_buf;
#endif
 

/*used for maintain*/
struct tag_table g_add_table;
struct tag_table g_del_table;

/*char statistics ( those printable but not space) can only be dealed within file*/
static int g_char_table[MAX_CHAR];
static int g_totalchar;


int 
string_query(char *szinput, int *index)
{
    int i;
    int size;
    int result;

    result = NOT_EXIST;

    size = strlen(szinput) + 1;

    for (i = 0; i < g_add_table.nrecords; i++)
    {
        if (size != g_add_table.records[i].size)
        {
            continue;
        }

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        //both NO_USE_MALLOC and USE_MALLOC_V1 use g_chBuf to store
        if (0 == strcmp(&g_chBuf[g_add_table.records[i].start], szinput))
#else
        //USE_MALLOC_V2 and USE_MALLOC_V3 use the malloced space to store.            
        if (0 == strcmp((char *)(g_add_table.records[i].start), szinput))
#endif
        {
            *index = i;
            result = SUCCESS;

            break;
        }
    }

    return result;
}

int
string_query_about(char *szinput, int *indexary, int *num)
{
    int i;
    int size;
    int result;
    
    result = NOT_EXIST;
    
    size = strlen(szinput) + 1;
    *num = 0;
    
    for (i = 0; i < g_add_table.nrecords; i++)
    {
        if (size > g_add_table.records[i].size)
        {
            continue;
        }
 
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        //both NO_USE_MALLOC and USE_MALLOC_V1 use g_chBuf to store
        if (NULL != strstr(&g_chBuf[g_add_table.records[i].start], szinput))
#else
        //USE_MALLOC_V2 and USE_MALLOC_V3 use the malloced space to store. 
        if (NULL != strstr((char *)(g_add_table.records[i].start), szinput))
#endif
        {
            //
            *indexary = i;
            indexary++;

            //
            *num += 1;
         }
    }

    if (0 != *num)
    {
        result = SUCCESS;
    }
    
    return result;
}


int
store_by_malloc(char *szinput, char **ppszstart)
{
    char *pszstart = NULL;
    size_t len = 0;
    int result = SUCCESS;

    len = strlen(szinput);
    
    pszstart = (char *)malloc(len + 1);
    if (NULL == pszstart)
    {
        result = NO_SPACE;
        return result;
    }
    else
    {
        strcpy(pszstart, szinput);
        *(pszstart + len) = '\0';

        *ppszstart = pszstart;

        return result;
    }
}

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
int
store(char *chBuf, int start, char *szinput, int requestsize)
{
    int result = SUCCESS;

    //make sure g_indexMAX_buf updated
    if (start == g_indexMAX_buf)
    {
        if (MAX_SPACE == g_indexMAX_buf)
        {
            result = NO_SPACE;
            return result;
            
        }
        g_indexMAX_buf += requestsize;
    }

    strcpy(&chBuf[start], szinput);
    chBuf[start + requestsize - 1] = '\0'; 

    return result;
} 
#endif


int
string_add(char *szinput)
{
    struct tag_record record;
    char *pszstart = NULL;
    int requestsize = 0;
    int index = -1;  //index of (size, start) within g_del_table
    int start = -1;
    int size = -1;

    int result;
    result = NO_SPACE;
        
    //we also store the '\0'
    requestsize = strlen(szinput) + 1;

#if defined(USE_MALLOC_V3) 
    //USE_MALLOC_V3, 不使用g_del_table,不对已删除空间再利用，直接malloc
    result = NOT_EXIST;    
#else
    //NO_USE_MALLOC,
    //USE_MALLOC_V1
    //USE_MALLOC_V2  均使用g_del_table, 对已删除空间再利用，所以优先查询g_del_table
    result = getsize(requestsize, &index);  
#endif  

    //no suitable size, we just store into g_chBuf[g_indexMAX_buf]
    if (NOT_EXIST == result)
    {
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        //NO_USE_MALLOC and USE_MALLOC_V1 store into g_chBuf

        result = store(g_chBuf, g_indexMAX_buf, szinput, requestsize);

        if (NO_SPACE == result)
        {
            //failed, no space
            return result;
        }
        
        //bkz g_indexMAX_buf already updated
        start = g_indexMAX_buf - requestsize;
        
        record.size  = requestsize;
        record.start = start;
        
        updatetable(&g_add_table, g_add_table.nrecords, &record);
        
        g_add_table.nrecords++;
#else
        //USE_MALLOC_V2 USE_MALLOC_V3 store into the malloc space
        result = store_by_malloc(szinput, &pszstart);

        record.size  = requestsize;
        record.start = (int)pszstart;

        insertintoaddtable(&g_add_table, &record);
#endif
    }//end for if(NOT_EXIST == result)
    else
    {
        size  = g_del_table.records[index].size;
        start = g_del_table.records[index].start;

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        
        //both the NO_USE_MALLOC and USE_MALLOC_V1 use the g_chBuf
        result = store(g_chBuf, start, szinput, requestsize);
#endif
        
#if defined(USE_MALLOC_V2)

        //directly copy into the heap stack indicated by start
        strcpy((char *)start, szinput);
        
        //will success always, bkz we didn't free the space
        result = SUCCESS;       
#endif

#if defined(USE_MALLOC_V3)
        //USE_MALLOC_V3 don't use g_del_table, no freed space to use.
        //and directly call malloc and free.
        
        //should never come to this point.
#endif

        if (NO_SPACE == result)
        {
            //failed
            return result;
        }

        if (requestsize == size)
        {
            record.size  = size;
            record.start = start;

            removefromtable(&g_del_table, index);
            insertintoaddtable(&g_add_table, &record);
        }
        else
        {
            record.size  = size - requestsize;
            record.start = start + requestsize;
            updatetable(&g_del_table, index, &record);

            record.size  = requestsize;
            record.start = start;
            insertintoaddtable(&g_add_table, &record);
        }
    }//end for NOT_EXIST != result

    //This is not a good idea using a var to represent more than one meaning.
    result = record.start;

    return result;
}

int
string_del(char *szinput)
{
    struct tag_record record;
    int index;
    int size;
    int start;
    int result;

    result = string_query(szinput, &index);

    if (NOT_EXIST == result)
    {
        //failed; not exist
        return result;
    }
    else
    {
        size  = g_add_table.records[index].size;
        start = g_add_table.records[index].start;

        record.size  = size;
        record.start = start;

        insertintodeltable(&g_del_table, &record);
        removefromtable(&g_add_table, index);  
    }//end for result != NOT_EXIST

    return result;
}


int
string_modify(char *origin, char *newinput)
{
    struct tag_record record;
    int index;
    int oldsize, newsize;
    int start;

    int result;

    result = string_query(origin, &index);

    if (NOT_EXIST == result)
    {
        //not exist
        return result;
    }
    else    
    {
        oldsize = strlen(origin) + 1;
        newsize = strlen(newinput) + 1;

        start = g_add_table.records[index].start;
       
        if (newsize < oldsize)
        {
            // this will generate unused space, we need to update g_add_table and g_del_table;
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
            result = store(g_chBuf, start, newinput, newsize);
#else
            //directly copy into the heap stack indicated by start
            strcpy((char *)start, newinput);
            result = SUCCESS;
#endif      
            if (NO_SPACE == result)
            {
                //failed, no more space
                return result;
            }

            record.size  = newsize;
            record.start = start;
            updatetable(&g_add_table, index, &record);

            record.size  = oldsize - newsize;
            record.start = start + newsize;
            insertintodeltable(&g_del_table, &record);
        }
        else if (newsize == oldsize)
        {
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
            //just replace directly
            result = store(g_chBuf, start, newinput, newsize);
#else   
            //directly copy into the heap stack indicated by start
            strcpy((char *)start, newinput);
            result = SUCCESS;
#endif
            if (NO_SPACE == result)
            {
                //failed, no space.
                return result;
            }

        }
        else
        {
            string_del(origin);
            result = string_add(newinput);
        }
    }//end for result != NOT_EXIST

    return result;
}

void
display(void)
{
    int i;
    int size;
    int start;
    char szhitinfo[MAX_INPUT] = {0};

    for (i = 0; i < g_add_table.nrecords; i++)
    {
        size  = g_add_table.records[i].size;
        start = g_add_table.records[i].start;
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        sprintf(szhitinfo, "%s  start: %d, size: %d\r\n", &g_chBuf[start], start, size);       
#else
        sprintf(szhitinfo, "%s  start: %p, size: %d\r\n", (char *)start, start, size);
#endif
        showinfo(szhitinfo);
    }
}



void
showbuf(char *buf, int index, int len)
{
    int i;
    char szhitinfo[8] = {0};

    if (index < 0)
    {
        index = 0;
    }

    for (i = index; i < index + len; i++)
    {
        if ('\0' == buf[i])
        {
            showinfo("\\0 ");
        }
        else
        {
            sprintf(szhitinfo, "%c ", buf[i]);            
            showinfo(szhitinfo);
        }
    }
}


void
space_stat_for_malloc()
{
    int nrecords_add = 0;
    int index_add = 0;
    int size_add = 0;
    int start_add = 0;

    int nrecords_del = 0;
    int index_del = 0;
    int size_del = 0;
    int start_del = 0;
    

    nrecords_add = g_add_table.nrecords;
    nrecords_del = g_del_table.nrecords;     

    for ( ; index_add < nrecords_add; index_add++ )
    {
        size_add  = g_add_table.records[index_add].size;
        start_add = g_add_table.records[index_add].start;

        space_stat((char *)start_add, size_add, index_add, index_del);

        if (index_del >= nrecords_del)
        {
            continue;
        }

        size_del  = g_del_table.records[index_del].size;
        start_del = g_del_table.records[index_del].start;
        if (start_del == start_add + size_add)
        {
            space_stat((char *)start_del, size_del, index_add, index_del);

            index_del++;
        }
    }

    //to make sure that not forgotten g_del_table
    for ( ; index_del < nrecords_del; index_del++)
    {
        size_del  = g_del_table.records[index_del].size;
        start_del = g_del_table.records[index_del].start;
        if (start_del == start_add + size_add)
        {
            space_stat((char *)start_del, size_del, index_add, index_del);
            
            index_del++;
        }       
    }
}

void
space_stat(char *buf, int size, int index_add, int index_del)
{
    int index_buf;
    int col;  
    int max;
    int table;
    int start;
    int len;
    int remain;
    int i;
    char szhitinfo[8] = {0};

    char flag;

    index_buf = 0;
    col       = 0;

    table     = ADD;
    max       = -1;

    showinfo("\r\n");

    for ( ; index_buf < size; index_buf++)
    {
        //this index belong to which one? g_add_table, g_del_table ?
        if (index_buf >= max )
        {
            table = gettable(buf, index_buf, &max, index_add, index_del);     
        }
        else
        {
            //that is to keep the table result last time unchanged.
            //so no need to gettable again.
        }        

        if (ADD == table)       //used
        {
            flag = 'U';
        }
        else if (DEL == table)  //free
        {
            flag = 'F';
        }
        else
        {
            //sth wrong?
            //printf("Sth wrong?");
            getchar();
        }

        if (0 == col % (SPLIT))
        {
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
            sprintf(szhitinfo, "%d: ", col);
#else
            sprintf(szhitinfo, "%p: ", col + (int)buf); //其实可以全部采用这个
#endif
            showinfo(szhitinfo);
        }
       
        sprintf(szhitinfo, "%c ", flag);
        showinfo(szhitinfo);
  
        if ((col != 0)
            &&(0 == (col + 1) % (SPLIT)) )
        {
            showinfo("    ");
            //
            start = col + 1 - (SPLIT);
            len   = SPLIT;

            showbuf(buf, start, len);
            showinfo("\r\n\r\n");
        }

        col += 1;
    } 
    
    //
    remain = (SPLIT) - col % (SPLIT);
    for (i = 0; i < remain; i++)
    {
        showinfo("  ");
    }
    showinfo("  ");
    
    len   = (SPLIT) - remain;
    start = col - len;
    
    showbuf(buf, start, len);    
}

/*
Function: used for debug, show detail info about g_add_table, g_del_table
*/
void
showtable(void)
{
    int i;
    char szhitinfo[64] = {0};
    
    showinfo("\r\n[ Debug ]showing g_add_table, g_del_table  (size, start) ......\r\n");
    
    showinfo("g_add_table:\r\n");
    for (i = 0; i < g_add_table.nrecords; i++)
    {
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        sprintf(szhitinfo, "(%d %d) ", g_add_table.records[i].size, 
                                       g_add_table.records[i].start);
#else
        sprintf(szhitinfo, "(%d %p) ", g_add_table.records[i].size, 
                                       g_add_table.records[i].start);        
#endif
        showinfo(szhitinfo);
    }
    showinfo("\r\n\r\n");
    
    showinfo("g_del_table:\r\n");
    for (i = 0; i < g_del_table.nrecords; i++)
    {
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
        sprintf(szhitinfo, "(%d %d) ", g_del_table.records[i].size, 
                                       g_del_table.records[i].start);
#else
        sprintf(szhitinfo, "(%d %p) ", g_del_table.records[i].size, 
                                       g_del_table.records[i].start);
#endif
        showinfo(szhitinfo);
    }
    showinfo("\r\n\r\n"); 
}

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
void
defrag(void)
{
    int size_del, start_del;
    int size_add, start_add;

    int i, j, k;

    i = g_del_table.nrecords; 
    j = g_add_table.nrecords;

    //walk through del_table
    for (; i >= 1; i--)
    {
        size_del  = g_del_table.records[i - 1].size;
        start_del = g_del_table.records[i - 1].start;        

        //find the proper index (size, start) in add_table
        for ( ; j >= 1; j--)
        {
            size_add  = g_add_table.records[j - 1].size;
            start_add = g_add_table.records[j - 1].start;
            
            if (start_add == start_del + size_del)
            {
                //we've already gotten the index
                break;
            }
        }

        //remove (size_del, start_del) from del_table, update g_indexMAX_del
        g_del_table.records[i - 1].size  = 0; //size
        g_del_table.records[i - 1].start = 0; //start

        g_del_table.nrecords--;


        //update (size, start) in add_table to (size, start - size_del)
        for (k = g_add_table.nrecords; (j >= 1) && (k >= j); k--)
        {
            g_add_table.records[k - 1].start = g_add_table.records[k - 1].start - size_del;            
        }

        //move char in g_chBuf[start_add,.. ,g_indexMAX_buf] forward
        // step is size_del
        for (k = start_add; (j >= 1) && (k < g_indexMAX_buf); k++)
        {
            g_chBuf[k - size_del] = g_chBuf[k];
        }

        //update g_indexMAX_buf
        g_indexMAX_buf -= size_del;                
    }
}
#endif

void
char_stat(void)
{
    double percent = 0.0;
    char ch;
    int  num;
    int i;
    char szhitinfo[64] = {0};

    showinfo("Show char info......\r\n");

    sprintf(szhitinfo, "Total: %d\r\n", g_totalchar);
    showinfo(szhitinfo);

    for (i = 0; i < (MAX_CHAR - MIN_CHAR + 1) ; i++ )
    {
        if (0 != g_char_table[i])       
        {
            //0x21 is the first printable(exclude space) within ascii
            ch  = i + 0x21;
            num = g_char_table[i];
            percent = num * 1.0 / g_totalchar;

            sprintf(szhitinfo, "%c %d %f\r\n", ch, num, percent);
            showinfo(szhitinfo);
        }
    }
}

static void
updatechar(char *szText, int action)
{
    int index;
    int contribute;
    size_t i;
    size_t length;

    length = strlen(szText);

    if (ADD == action)
    {
        contribute = 1;
    }
    else if (DEL == action)
    {
        contribute = -1;
    }
    else
    {
        //sth wrong??
    }

    for (i = 0; i < length; i++ )
    {
        index = szText[i] - MIN_CHAR;
        g_char_table[index] += contribute;
        g_totalchar += contribute;
    }
}

void
process_add(void)
{
    char szhitinfo[MAX_INPUT] = {0};    //输出的提示性信息
    char szinput[MAX_INPUT];
    int result;

    //Add
    getinput(szinput, "Add what ? ");
    
    result = string_add(szinput);
    if (NO_SPACE == result)
    {
        showinfo("Add failed, for No More Space\r\n");
    }
    else
    {
        sprintf(szhitinfo, "ADD: store into %p\r\n", result);
        showinfo(szhitinfo);
        
        //
        updatechar(szinput, ADD);
    }
}

void
process_query(void)
{
    char szhitinfo[MAX_INPUT] = {0};    //输出的提示性信息
    char szinput[MAX_INPUT];
    char szqueryed[MAX_INPUT];          //模糊查询匹配的字符串
    int indexary[MAX_INPUT];            //用于接收模糊查询的结果
    int num;                            //模糊查收所得结果的数目
    int index;    
    int result;
    int i;

    //string_query
    getinput(szinput, "Query what ? ");
    
#ifdef ACCURATE_QUERY
    result = string_query(szinput, &index);
#else
    result = string_query_about(szinput, indexary, &num);
#endif
    
    
    if (NOT_EXIST == result)
    {
        showinfo("Query: not exist\r\n");
    }
    else
    {
#ifdef  ACCURATE_QUERY 
        sprintf(szhitinfo, "Query: at %p\r\n", g_add_table.records[index].start);
        showinfo(szhitinfo);
#else
        //模糊查询结果输出
        for (i = 0; i < num; i++)
        {
            //查询到的字符串的(size, start)记录在g_add_table中的下标
            index = indexary[i];  
#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
            strcpy(szqueryed, &g_chBuf[g_add_table.records[index].start]);
#else
            strcpy(szqueryed, (char *)(g_add_table.records[index].start));
#endif  
            sprintf(szhitinfo, "Query: %s at %p\r\n", 
                szqueryed,                   //查询到的字符串
                g_add_table.records[index].start       //查询到的字符串在g_chBuf中的下标
                );    
            
            showinfo(szhitinfo);
        }
#endif
    }
}

void
process_del(void)
{
    char szhitinfo[MAX_INPUT] = {0};    //输出的提示性信息
    char szinput[MAX_INPUT];
    int result;

    getinput(szinput, "Del what ? ");
    
    result = string_del(szinput);
    
    if (-1 == result)
    {
        sprintf(szhitinfo, "%s does not exist\r\n", szinput);
        showinfo(szhitinfo);
    }
    else
    {
        showinfo("Del ok\r\n");
        
        //
        updatechar(szinput, DEL);
    }
}

void
process_modify(void)
{
    char szhitinfo[MAX_INPUT] = {0};    //输出的提示性信息
    char szinput[MAX_INPUT];
    char newinput[MAX_INPUT];
    int result;
    
    //string_modify
    getinput(szinput, "Modify, origin ? ");
    
    getinput(newinput, "newinput ? ");
    
    result = string_modify(szinput, newinput);
    if (NOT_EXIST == result)
    {
        sprintf(szhitinfo, "Modify: %s not exist\r\n", szinput);
        showinfo(szhitinfo);
    }
    else if (NO_SPACE == result)
    {
        showinfo("Modify: no more space to store newinput\r\n");
    }
    else
    {
        showinfo("Modify ok\r\n");
        
        //
        updatechar(szinput, DEL);
        updatechar(newinput, ADD);
    }
}

void
process_fit(void)
{
    int select;

    //set fit
    showinfo("Please choose the fit way\r\n");
    
    showfit();
    
    getselect(&select);
    
    if (select < FIT_EQUAL || select > FIT_EQUAL_FIRST )
    {
        showinfo("Please make the right decision ^_^\r\n");
    }
    else
    {
        setfit(select);
    }
}

void
dispatch(int select)
{
    switch (select)
    {
    default:
        {
            showinfo("Please make the right decision ^_^\r\n");
            break;
        }

    case 1:
        {
            process_add();
            break;
        }
  
    case 2:
        {
            process_query();
            break;
        }

    case 3:
        {
            process_del();
            break;
        }

    case 4:
        {
            process_modify();
            break;
        }

    case 5:
        {
            //display:
            showinfo("Displaying......\r\n");
            
            display();            
            break;
        }

    case 6:
        {
            //statistics
            showinfo("Statisticsing......U for Used, F for Free\r\n\r\n");

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
            space_stat(g_chBuf, g_indexMAX_buf, 0, 0);
#else
            space_stat_for_malloc();
#endif
            break;
        }


    case 7:
        {
            process_fit();
            break;
        }

#if defined(NO_USE_MALLOC) || defined(USE_MALLOC_V1)
    case 8:
        {
            defrag();
            break;
        }
#endif

    case 9:
        {
            char_stat();
            break;
        }
    }//end for switch
}

int
main(void)
{
    int select;

#if defined(USE_MALLOC_V1) 
    g_chBuf = (char *)malloc(MAX_SPACE);
    if (NULL == g_chBuf)
    {
        showinfo("No enough memory to continue\r\n");
        return -1;
    }
#endif

    while (1)
    {
        showmenu();

        getselect(&select);
        
        if (0 == select)
        {
            break;
        }
        else if(select < 0 || select >= 10) //can be changed
        {
            showinfo("Please make the right decision ^_^\r\n");
            continue;
        }

        dispatch(select);

        //used for debug, can be removed
        showtable();
    }

#if defined(USE_MALLOC_V1) 
    if (g_chBuf)
    {
        free(g_chBuf);
        g_chBuf = NULL;
    }
#endif

    return 0;
}