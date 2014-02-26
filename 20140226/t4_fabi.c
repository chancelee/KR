#include <stdio.h>

/*
In fact, we don't think this is a good idea to use recursive solution
we can use iteration instead
*/
long
fabi(int n)
{
    if( n <= 2 )
    {
        return 1;
    }
    else
    {
        return fabi(n - 1) + fabi(n - 2);
    }
}

int
main(void)
{
    int i;

    for (i = 1; i <= 20; i++)
    {
        printf("%ld ", fabi(i));
    }

    return 0;
}