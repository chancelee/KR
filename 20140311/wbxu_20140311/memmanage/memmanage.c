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
Function: ��ѯ������ַ����Ƿ������chBuf�С� 
����
Param	: chInput ��ʱ����û�������ַ��� 
           index ���ڽ��ո��ַ�����Ӧ��(size, start)��add_table�е��±�
           
Return  :  -1 �����ڣ� 0���ڣ�������index.
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
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size = requestsize
Param	: requestsize ��������Ŀռ��С�� 
����      index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
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
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size �պ�>= 
����       requestsize��
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
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
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size �ǵ�һ��>= 
����        requestsize��
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
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
Function: ����WAY����del_table���ҵ�һ�����ʵ�(size, start)��¼��
����      �Ƕ�����fitxxx�����ķ�װ��
���� 
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
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
Function: ��(size, start)��¼����Ĳ��뵽table[*max]��
����  
Param	: table[max]
����        size, start
����        
Return  :  None.

Effect   : ����*max;
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
Function: ����del_table�У�index����ǰ��������Ƿ�Ϊ�����Ŀ��пռ䣬�������ϣ�
           �Ի�ȡ����Ŀ��пռ䣬���ں����ٷ���
Param   : index

Return  : None

Effect  : ���ܵ���removefromtable����Ӹ���indexMAX_del

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
Function: ��(size, start)��¼����Ĳ��뵽table[*max]��, ����del_tableָʾ�������пռ��������
����  
Param	:  table[*max]
����        size, start
����        
Return  :  None.

Effect   : ����*max, ��del_tableָʾ���������пռ�������ϣ������ٷ���
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
Function: ��index ����ʶ��(size, start)��table[*max]��ɾ��, ����֤table�������ԡ�
����  
Param	: table[*max]
����        
Return  :  None.

Effect  : ����*max;
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
Function: ��table[index]����ʶ��(size, start)����Ϊ�´����ֵ��
����  
Param	: 
����        
Return  :  None.

Effect  :  ����table
*/
void
updatetable(int table[], int index, int size, int start)
{
    table[index]        = size;
    table[index + 1]    = start;
}

/*
Function: ��chInput[]�洢��chBuf[start]
����  
Param	 : chBuf, start, chInput, requestsize          
����        
Return  :  None

Effect   : ����chBuf[],������Ҫ����indexMAX_buf
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
Function: ���û�����chInput[]�洢��chBuf[]�С�
����  
Param	: chInput[]Ϊ�û��������ʱ�洢
����        
Return  :  -1 �洢ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, indexMAX_add, �����������
          del_table,indexMAX_buf


  add(string):
  ����sizereal = len(string)
  �������û�д�del_table�в�ѯ�����ʣ� �ں����������(size, start)��¼�������charBuf[10000]�������ѷ��������±�indexMax, ��indexMax������string, ����add_table��׷��(size, indexMax)��¼��
  ����
  ��������del_table�в�ѯ��һ�����ʵģ��ں������) size�ļ�¼(size, start)����string������charBuf[start]��ʼ��λ�á�����sizereal��size�Ĺ�ϵ�������¼��������
  ����sizereal = size, ��(size, start)��del_table��ɾ����ͬʱ��(size, start)����Ĳ��뵽add_table��
      sizereal < size, ��del_table�еĸ�(size, start)��Ϊ(size - sizereal, start + sizereal), ͬʱ����(sizereal, start)����Ĳ��뵽add_table�С�

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
Function: ��ͼ��chBuf[]��ɾ���û�����chInput[]��
����  
Param	: chInput[]Ϊ�û��������ʱ�洢
����        
Return  :  -1 ɾ��ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, 
           ����del_table�� ��������Կ��пռ�������ϣ�Ӱ��del_table

del(string):
����index = query(string)
����(size, start) = (add_table[index], add_table[index+1])
����
�������index == -1 ��ѯʧ�ܣ��򷵻�-1��ʾɾ��ʧ�ܡ�
����
�������index != -1, ��(size, start)��add_table��ɾ����ͬʱ���Ǹ��������del_table. ���ǵ����ܵ��������пռ�����ϣ���Ϊ���������
�������(size, start)�к��ʵ�ǰ��(size1, start1) ���� start1 + size1 = size, ������������пռ���������Ӧ��(size1, start1)����Ϊ(size1+size, start1)
�������(size,start)�к��ʵĺ��(size2, start2)���� start + size = start2, ��(size2, start2)Ӧ����Ϊ(size+size2, start)
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
Function: ��ͼ��chBuf[]�н�ԭ������origin����Ϊ����������new��
����  
Param	: originָ����޸�����
           newָ��������
����        
Return  :  -1 �޸�ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, 
           ����del_table�� ��������Կ��пռ�������ϣ�Ӱ��del_table

modify(origin, new):
����index = query(origin)
�������index == -1 ����������origin, �޸�ʧ�ܡ�
����oldsize = len(origin)
����newsize = len(new)
�������index != -1, ����ʾorigin��(size, start)��add_table�е��±꣬ȡ��start.
��������oldsize��newsize�Ĵ�С����Ϊ���������
������� newsize < oldsize, �����add_table�е�(size, start) Ϊ(newsize, start), ͬʱ��del_table������Ĳ���(oldsize - newsize, start + newsize)
������� newsize = oldsize, �򲻷������
�������newsize > oldsize, ���ʱ���Լ򵥵��õ�del(origin)��add(string), ��ɿռ���ͷź������ϣ��Լ��ٷ��䡣
����Ȼ��Ҳ���ܳ��ָ�startǰ�����ߺ�̱����Ѿ�Ϊ���е��������ô��ʱ���п��е���������õģ��������ǻ��ǽ�������һ������̽��д�����
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