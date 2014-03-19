#include <stdio.h>
#include "memmanage.h"
#include "fit.h"

/*
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size = requestsize
Param	: requestsize ��������Ŀռ��С�� 
����      index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  NOT_EXIST ʧ�ܣ� SUCCESS�ɹ���������index.
*/
int 
fitequal(int requestsize, int *index)
{
    int i;
    int result;

    result = NOT_EXIST;

    for (i = 0; i < indexMAX_del; i += 2)
    {
        if ( requestsize == del_table[i])
        {
            *index = i;
            result = SUCCESS;

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
Return  :  NOT_EXIST ʧ�ܣ� SUCCESS�ɹ���������index.
*/
int 
fitenough(int requestsize, int *index)
{
    int i;
    int min;
    int result;

    result = NOT_EXIST;

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
        result = SUCCESS;
    }

    return result;
}

/*
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size �ǵ�һ��>= 
����        requestsize��
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  NOT_EXIST ʧ�ܣ� SUCCESS�ɹ���������index.
*/
int 
fitfirst(int requestsize, int *index)
{
    int i;
    int result;

    result = NOT_EXIST;

    for (i = 0; i < indexMAX_del; i += 2)
    {
        if (requestsize <= del_table[i])
        {
            *index = i;
            result = SUCCESS;

            break;
        }
    }

    return result;
}

/*
Function: ����fitWAY����del_table���ҵ�һ�����ʵ�(size, start)��¼��
����      �Ƕ�����fitxxx�����ķ�װ��
���� 
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  NOT_EXIST ʧ�ܣ� SUCCESS �ɹ���������index.
*/
int 
getsize(int requestsize, int *index)
{
    int result;

    result = NOT_EXIST;

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
        if (NOT_EXIST == result)
        {
            result = fitenough(requestsize, index);
        }
        break;

    case FIT_EQUAL_FIRST:
        result = fitequal(requestsize, index);
        if (NOT_EXIST == result)
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

void
setfit(int select)
{
   fitWAY = select;
}