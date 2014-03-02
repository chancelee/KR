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
    int i;

    printf("Please enter one num: ");

    scanf("%d", &i);

    printf("factor(%d) = %ld\n", i,factor(i));
    
    return 0;
}