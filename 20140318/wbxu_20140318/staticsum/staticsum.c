#include <stdio.h>

unsigned long
staticsum(unsigned n)
{
    static unsigned long sum = 0;

    sum += n;

    return sum;
}

void
output(unsigned long sum)
{
    printf("sum = %ld\r\n", sum);
}


void
getinput(unsigned *n)
{
    printf("Please Enter n to calculate: 1+ 2 + 3 + ...+ n\r\n");
    scanf("%ud", n);
}

int
main(void)
{
    unsigned n;
    unsigned long sum;

    getinput(&n);

    while(n > 0)
    {
        sum = staticsum(n);
        
        n--;
    }

    output(sum);

    return 0;
}