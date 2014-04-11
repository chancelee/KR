/************************************************************************/
/* 用位运算一个win32平台上指针是多少位                                                                     */
/************************************************************************/

#include <stdio.h>

/*
Function: 通过左移，获得指针的长度
*/
int
getptrlen_left(void)
{
    void *p = (void *)1;
    int i = 0;  
     
    while (p = (void*)((unsigned)p << 1))
    {
        i++;
    }

    return i + 1;
}

/*
Function: 通过右移，获得指针的长度
*/
int
getptrlen_right(void)
{
    void *p = (void *)~0;
    int i = 0;
    
    while (p = (void *)((unsigned)p >> 1))
    {
        i++;
    }

    return i + 1;
}

int
main(void)
{
    printf("left: bit length of pointer on this machine is %d\r\n", 
        getptrlen_left());

    printf("right: bit length of pointer on this machine is %d\r\n", 
        getptrlen_right());



    return 0;
}