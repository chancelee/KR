#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memmanage.h"

//storage for your input.
char chBuf[MAX_SPACE];

//
char chInput[MAX_INPUT];

//used for maintain
//seems a waste.
int add_table[MAX_SPACE];
int del_table[MAX_SPACE];

//how many (size, start) are stored into table;
int indexMAX_add;
int indexMAX_del;
int indexMAX_buf;

//the way you can get suitable size
int fitWAY;

/*
Function: 查询输入的字符串是否存在于chBuf中。 
　　
Param	: chInput 临时存放用户输入的字符串 
           index 用于接收该字符串对应的(size, start)在add_table中的下标
           
Return  :  -1 不存在， 0存在，并设置index.
*/
int 
query(char chInput[], int *index)
{
    int i;
    int size;
    int result;

    result = -1;

    size = strlen(chInput) + 1;

    for (i = 0; i < indexMAX_add; i += 2)
    {
        if (size != add_table[i])
        {
            continue;
        }

        if (0 == strcmp(&chBuf[add_table[i + 1]], chInput))
        {
            *index = i;
            result = 0;

            break;
        }
    }

    return result;
}

/*
Function: 从del_table中找到一个(size, start)记录，使得size = requestsize
Param	: requestsize 是想申请的空间大小， 
　　      index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitequal(int requestsize, int *index)
{
    int i;
    int result;

    result = -1;

    for (i = 0; i < indexMAX_del; i += 2)
    {
        if ( requestsize == del_table[i])
        {
            *index = i;
            result = 0;

            break;
        }
    }

    return result;
}

/*
Function: 从del_table中找到一个(size, start)记录，使得size 刚好>= 
　　       requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitenough(int requestsize, int *index)
{
    int i;
    int min;
    int result;

    result = -1;

    for (i = 0, min = -1; i < indexMAX_del; i += 2)
    {
        if (requestsize <= del_table[i])
        {
            
            if ((-1 == min) || (del_table[i] < del_table[min]))
            {
                min = i;
            }
        }
    }

    if (-1 != min)
    {
        *index = min;
        result = 0;
    }

    return result;
}

/*
Function: 从del_table中找到一个(size, start)记录，使得size 是第一个>= 
　　        requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitfirst(int requestsize, int *index)
{
    int i;
    int result;

    result = -1;

    for (i = 0; i < indexMAX_del; i += 2)
    {
        if (requestsize <= del_table[i])
        {
            *index = i;
            result = 0;

            break;
        }
    }

    return result;
}

/*
Function: 根据WAY，从del_table中找到一个合适的(size, start)记录，
　　      是对上面fitxxx函数的封装。
　　 
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
getsize(int requestsize, int *index)
{
    int result;

    result = -1;

    switch (fitWAY)
    {
    case FIT_EQUAL:
        result = fitequal(requestsize, index);
        break;

    case FIT_ENOUGH:
        result = fitenough(requestsize, index);
        break;

    case FIT_FIRST:
        result = fitfirst(requestsize, index);
        break;

    case FIT_EQUAL_ENOUGH:
        result = fitequal(requestsize, index);
        if (-1 == result)
        {
            result = fitenough(requestsize, index);
        }
        break;

    case FIT_EQUAL_FIRST:
        result = fitequal(requestsize, index);
        {
            result = fitfirst(requestsize, index);
        }
        break;

    default:
        //sth wrong ?
        break;
    }

    return result;
}

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
Function: 将chInput[]存储至chBuf[start]
　　  
Param	 : chBuf, start, chInput, requestsize          
　　        
Return  :  None

Effect   : 更新chBuf[],根据需要更新indexMAX_buf
*/
void
store(char chBuf[], int start, char chInput[], int requestsize)
{
    strcpy(&chBuf[start], chInput);
    chBuf[start + requestsize - 1] = '\0';
    
    //make sure indexMAX_buf updated
    if (start == indexMAX_buf)
    {
        if (indexMAX_buf == MAX_SPACE)
        {
            printf("Store: No more space!!!\r\n");
            getchar();

            exit(-1);
        }
        indexMAX_buf += requestsize;
    }
}

/*
Function: 将用户输入chInput[]存储至chBuf[]中。
　　  
Param	: chInput[]为用户输入的临时存储
　　        
Return  :  -1 存储失败， 0 成功.

Effect  : 更新add_table, indexMAX_add, 根据情况更新
          del_table,indexMAX_buf


  add(string):
  　　sizereal = len(string)
  　　如果没有从del_table中查询到合适（ 在后面阐述）的(size, start)记录，则根据charBuf[10000]数组中已分配的最大下标indexMax, 从indexMax处填入string, 并在add_table中追加(size, indexMax)记录。
  　　
  　　若从del_table中查询到一个合适的（在后面阐述) size的记录(size, start)，将string拷贝至charBuf[start]开始的位置。根据sizereal和size的关系，有以下几种情况：
  　　sizereal = size, 则将(size, start)从del_table中删除，同时将(size, start)有序的插入到add_table中
      sizereal < size, 则将del_table中的该(size, start)改为(size - sizereal, start + sizereal), 同时，将(sizereal, start)有序的插入到add_table中。

*/
int
add(char chInput[])
{
    int requestsize;
    int index;  //index of (size, start) within del_table
    int start;
    int size;

    int result;

    result = -1;
        
    requestsize = strlen(chInput) + 1;

    result = getsize(requestsize, &index);

    //no suitable size, we just store into chBuf[indexMAX_buf]
    if (-1 == result)
    {
        store(chBuf, indexMAX_buf, chInput, requestsize);
        updatetable(add_table, indexMAX_add, requestsize, indexMAX_buf - requestsize);

        indexMAX_add += 2;

        
    }
    else
    {
        size  = del_table[index];
        start = del_table[index + 1];
        store(chBuf, start, chInput, requestsize);

        printf("ADD: store into %d\r\n", start);

        if (requestsize == size)
        {
            removefromtable(del_table, &indexMAX_del, index);
            insertintoaddtable(add_table, &indexMAX_add, size, start);
        }
        else
        {
            updatetable(del_table, index, size - requestsize, start + requestsize);
            insertintoaddtable(add_table, &indexMAX_add, requestsize, start);
        }
    }//end for else

    return result;
}

/*
Function: 试图从chBuf[]中删除用户输入chInput[]。
　　  
Param	: chInput[]为用户输入的临时存储
　　        
Return  :  -1 删除失败， 0 成功.

Effect  : 更新add_table, 
           更新del_table， 根据情况对空闲空间进行整合，影响del_table

del(string):
　　index = query(string)
　　(size, start) = (add_table[index], add_table[index+1])
　　
　　如果index == -1 查询失败，则返回-1表示删除失败。
　　
　　如果index != -1, 则将(size, start)从add_table中删除，同时考虑更新有序表del_table. 考虑到可能的连续空闲空间的整合，分为以下情况：
　　如果(size, start)有合适的前驱(size1, start1) 满足 start1 + size1 = size, 表明该两块空闲空间连续，则应将(size1, start1)更新为(size1+size, start1)
　　如果(size,start)有合适的后继(size2, start2)满足 start + size = start2, 则(size2, start2)应更新为(size+size2, start)
*/
int
del(char chInput[])
{
    //indexpre(sizepre, startpre), index(size, start), indexaft(sizeaft, startaft)
    int index;
    int size;
    int start;
    int result;

    result = query(chInput, &index);

    if (-1 == result)
    {
        //failed; not exist
        printf("%s does not exist\r\n", chInput);
    }
    else
    {
        size  = add_table[index];
        start = add_table[index + 1];

        insertintodeltable(del_table, &indexMAX_del, size, start);
        removefromtable(add_table, &indexMAX_add, index); 
        

    }//end for result != -1

    return result;
}

/*
Function: 试图从chBuf[]中将原有输入origin更改为新输入内容new。
　　  
Param	: origin指向待修改内容
           new指向新内容
　　        
Return  :  -1 修改失败， 0 成功.

Effect  : 更新add_table, 
           更新del_table， 根据情况对空闲空间进行整合，影响del_table

modify(origin, new):
　　index = query(origin)
　　如果index == -1 表明不存在origin, 修改失败。
　　oldsize = len(origin)
　　newsize = len(new)
　　如果index != -1, 它表示origin的(size, start)在add_table中的下标，取得start.
　　根据oldsize和newsize的大小，分为以下情况：
　　如果 newsize < oldsize, 则更改add_table中的(size, start) 为(newsize, start), 同时在del_table中有序的插入(oldsize - newsize, start + newsize)
　　如果 newsize = oldsize, 则不发生变更
　　如果newsize > oldsize, 则此时可以简单调用的del(origin)和add(string), 完成空间的释放和再整合，以及再分配。
（当然，也可能出现该start前驱或者后继本来已经为空闲的情况，那么此时进行空闲的整合是最好的，但是我们还是将其纳入一般的流程进行处理）。
*/
int
modify(char origin[], char newinput[])
{
    int index;
    int oldsize, newsize;
    int start;

    int result;

    result = query(origin, &index);

    if (-1 == result)
    {
        //not exist
        printf("modify: %s not exist\r\n", origin);
    }
    else    
    {
        oldsize = strlen(origin) + 1;
        newsize = strlen(newinput) + 1;

        start = add_table[index + 1];

       
        if (newsize < oldsize)
        {
            // this will generate unused space, we need to update add_table and del_table;
            store(chBuf, start, newinput, newsize);
            updatetable(add_table, index, newsize, start);
            insertintodeltable(del_table, &indexMAX_del, oldsize - newsize, start + newsize);

            printf("Modify: newsize < oldsize\r\n");
        }
        else if (newsize == oldsize)
        {
            //just replace directly
            store(chBuf, start, newinput, newsize);

            printf("Modify: newsize == oldsize\r\n");
        }
        else
        {
            printf("Modify: newsize > oldsize\r\n");

            del(origin);
            add(newinput);
        }
    }//end for result != -1

    return result;
}

void
display(void)
{
    int i;
    int size;
    int start;

    for (i = 0; i < indexMAX_add; i +=2)
    {
        size  = add_table[i];
        start = add_table[i + 1];

        printf("%s  start: %d, size: %d\r\n", &chBuf[start], start, size);
    }
}

/*
Function: get the table that index belongs to, and set the max value of this range.
*/
int
gettable(int index, int *max)
{
    static int index_add = 0;
    static int index_del = 0;

    int size_add, start_add;
    //int sizeaft_add, startaft_add;

    int size_del, start_del;
    //int sizeaft_del, startaft_del;

    size_add        = add_table[index_add];
    start_add       = add_table[index_add + 1];    

    size_del        = del_table[index_del];
    start_del       = del_table[index_del + 1];
    

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

    /*

    if ((indexMAX_add == index_add)
        || (indexMAX_del == index_del))
    {
        //sth wrong?
        return -1;
    }
    

    sizeaft_add     = add_table[index_add + 2];
    startaft_add    = add_table[index_add + 3];
    
    sizeaft_del     = del_table[index_del + 2];
    startaft_del    = del_table[index_del + 3];

    if ((index >= startaft_add) && (index <= startaft_add + sizeaft_add))
    {
        *max = startaft_add + sizeaft_add;
        
        //now move index_add toward
        index_add += 2;
        return ADD;
    }

    if((index >= startaft_del) && (index <= startaft_del + sizeaft_del))    
    {
        *max = startaft_del + sizeaft_del;

        //
        index_del += 2;
        return DEL;
    }
    */
}

void
showbuf(int index, int len)
{
    int i;

    for (i = index; i < index + len; i++)
    {
        if ('\0' == chBuf[i])
        {
            printf("0 ");
        }
        else
        {
            printf("%c ", chBuf[i]); 
        }
    }
}

void
statistics(void)
{
    int index_buf;
    int col;  
    int max;
    int table;
    int remain;
    int i;

    char flag;

    index_buf = 0;
    col       = 0;

    table     = ADD;
    max       = -1;

    for ( ; index_buf < indexMAX_buf; index_buf++)
    {
        //this index belong to which one? add_table, del_table ?
        if (index_buf > max )
        {
            table = gettable(index_buf, &max);            
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
            printf("Sth wrong?");
            getchar();
        }

        if (0 == col % 8)
        {
            printf("%d: ", col);
        }
       
        printf("%c ", flag);
        

        if ((col != 0)
            &&(0 == (col + 1) % 8) )
        {
            printf("    ");
            //
            showbuf(col + 1 - 8, 8);

            printf("\r\n\r\n");

        }

        col += 1;
    } 
    
    //
    remain = 8 - col % 8;
    for (i = 0; i < remain; i++)
    {
        printf("  ");
    }
    printf("  ");
    
    showbuf(col + 1 - 8, 8 - remain );
    
}


void
showmenu(void)
{
    printf("This is the menu for memory management:\r\n"
           "---------------------------------------\r\n"
           "1. Add      : store your input         \r\n"
           "2. Query    : whether your input exists\r\n"
           "3. Del      : remove your input        \r\n"
           "4. Modify   : change origin to new     \r\n"
           "5. Display  : show all stored inputs   \r\n"
           "6. Statistics: show how space are used \r\n"
           "0. exit                                \r\n"
           "---------------------------------------\r\n"
           "Please enter one number to select:     \r\n");
}

void
process(int select)
{
    int index;
    char newinput[MAX_INPUT];
    int result;

    switch (select)
    {
    default:
        {
            printf("Please make the right decision ^_^\r\n");
            break;
        }

    case 1:
        {
            //Add
            printf("Add what ? ");
            scanf("%s", chInput);
        
            add(chInput);

            break;
        }

        
    case 2:
        {
            //query
            printf("Query what ? ");
            scanf("%s", chInput);

            result = query(chInput, &index);
            if (-1 == result)
            {
                printf("Query: not exist\r\n");
            }
            else
            {
                printf("Query: at %d\r\n", add_table[index + 1]);
            }

            break;
        }

        
    case 3:
        {
            //del
            printf("Del what ? ");
            scanf("%s", chInput);
            
            del(chInput);
            
            break;
        }
        

        
    case 4:
        {
            //modify
            printf("Modify, origin ? ");
            scanf("%s", chInput);
            
            printf("newinput ? ");
            scanf("%s", newinput);
            
            modify(chInput, newinput);
            
            break;
        }

        
    case 5:
        {
            //display:
            printf("Displaying......\r\n");
            
            display();
            
            break;
        }

        
    case 6:
        {
            //statistics
            printf("Statisticsing......\r\n");
            
            statistics();
            break;
        }

    }//end for switch
}

int
main(void)
{
    int select;

    while (1)
    {
        showmenu();

        scanf("%d", &select);

        if (0 == select)
        {
            break;
        }

        process(select);

        printf("\r\n\r\n");
    }

    return 0;
}