/************************************************************************/
/* 用位运算将23的第15,16位提取出来                                                                     */
/************************************************************************/

#include <stdio.h>

/*
Function: 获得x的第n位(0-based)的值
*/
int
getbitvalue(int x, int n)
{
    int tmp = 0;

    tmp = x & (1 << n);
    if (tmp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
Function: 输出x的二进制表示
*/
void
printbinary(int x)
{
    if (x / 2)
    {
        printbinary(x / 2);
    }
    
    printf("%d ", x % 2);
}

int
main(void)
{
    int x = 0;
    int n = 0;

    while (1)
    {
        printf("Please enter the value and bit:\r\n");
        scanf("%d%d", &x, &n);

        printf("binary of %d is:\r\n", x);
        printbinary(x);

        printf("\r\n%dth bit is %d\r\n\r\b",
                n, 
                getbitvalue(x, n));
    }

    return 0;
}