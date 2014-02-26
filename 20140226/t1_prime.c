#include <stdio.h>
#include <math.h>

int
isPrime(int x)
{
    int i;
    int ilimit;

    ilimit = (int)sqrt(x);

    //if x can be divided by number between 2 and sqrt(x), then it is not a prime.
    for (i = 2; i <= ilimit; i++)
    {
        if(0 == (x % i))
        {
            break;
        }
    }

    if (i > ilimit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int
main(void)
{
    int i;
    int iResult;
 
    printf("Please enter one int num: ");
    scanf("%d", &i);

    //
    iResult = isPrime(i);

    if(1 == iResult)
    {
        printf("%d is a prime\n");
    }
    else if(0 == iResult)
    {
        printf("%d is not a prime\n");
    }

    
    return 0;
}