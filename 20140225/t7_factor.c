#include <stdio.h>

long
factor(int input)
{
    long tmp = 1;
    while(input)
    {
        tmp *= input--;
    }

    return tmp;
}

int
main(void)
{
    printf("5! = %ld, 10! = %ld\n", factor(5), factor(10));
    
    return 0;
}