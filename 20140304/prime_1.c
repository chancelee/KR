#include <stdio.h>
#include <math.h>

/*
How many primes between 2 and 1000

arry[512] is used to store those primes.

for a num N, is N can be dived by one within arry, then it cannot be a prime.

*/
int
main(void)
{
    int arry[512] = {2};

    int i, j;

    for ( i = 3; i <= 1000; i += 2 )
    {
        for ( j = 0; arry[j] != 0; j++ )
        {
            if ( 0 == i % arry[j] )
            {
                break;
            }
        }

        if ( 0 == arry[j])
        {
            arry[j] = i;
        }
    }

    for ( i = 0; arry[i] != 0; i++ )
    {
        printf("%d ", arry[i]);
    }
    
    printf("\nTotal: %d\n", i);

   
    return 0;
}