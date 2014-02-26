#include <stdio.h>

long
factor(long input)
{
    long tmp = 1;
    while (input)
    {
        tmp *= input--;
    }

    return tmp;
}

long 
compoz(long m, long n)
{
    return (factor(m) / (factor(n) * factor(m - n)) );    
}


long
main(void)
{
    long iCount;

    iCount = compoz(10, 3);

    prlongf("compoz(10, 3) = %ld\n", iCount);

    return 0;
}