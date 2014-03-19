#include <stdio.h>
#include "memmanage.h"
#include "fit.h"

/*
Function: 从del_table中找到一个(size, start)记录，使得size = requestsize
Param	: requestsize 是想申请的空间大小， 
　　      index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS成功，并设置index.
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
Function: 从del_table中找到一个(size, start)记录，使得size 刚好>= 
　　       requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS成功，并设置index.
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
Function: 从del_table中找到一个(size, start)记录，使得size 是第一个>= 
　　        requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS成功，并设置index.
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
Function: 根据fitWAY，从del_table中找到一个合适的(size, start)记录，
　　      是对上面fitxxx函数的封装。
　　 
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS 成功，并设置index.
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