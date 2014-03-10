#include <stdio.h>

#define COUNT 10


int
main(void)
{
    int min, max;

    int i, input;

    i = 0;

    printf("Please enter %d numbers: ", COUNT);

    while( i < COUNT
        && (1 == scanf("%d", &input))
        )
    {
        if ( 0 == i)
        {
            min = input;
            max = input;
        }

        if (min > input)
        {
            min = input;
        }

        if (max < input)
        {
            max = input;
        }

        i++;
    }

    printf("min = %d, max = %d\n", min, max);

    return 0;
}