#include <stdio.h>
#include "memmanage.h"
#include "table.h"

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