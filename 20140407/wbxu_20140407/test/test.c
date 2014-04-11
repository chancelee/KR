#include <stdio.h>
#include <math.h>

int 
myabs(int n)
{
    int tmp = 0;

    tmp = n >> 31;  // 当n为正时，tmp为0；  为负时，tmp为-1 (0xfff...)
    n = n ^ tmp ;   // 当n为正时，保持不变；为负时，按位取反
    n = n - tmp;    // 当n为正时，保持不变；为负时，加1
                    //从而实现了，对abs(n)的功能。

    return n;
}

int
main(void)
{
    int i       = 15;
    int nresult = 0;

    nresult = (i);

    return 0;
}