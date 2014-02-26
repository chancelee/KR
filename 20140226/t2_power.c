#include <stdio.h>

double
power(double x, int n)
{
    double result = 1.0;

    while(n--)
    {
        result *= x;
    }
 
    return result;
}

int
main(void)
{
    double result = 0.0;

    result = power(1.5, 3);
    printf("1.5^3 = %f\n", result);

    return 0;
}