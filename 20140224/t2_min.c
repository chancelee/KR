#include <stdio.h>
#include <stdlib.h>

#define COUNT 6

int
main(void)
{
    int input;
    int min;
    int i;

    i = 0;

    printf("Please input %d numbers: ", COUNT);

    while (i++ < COUNT 
         && (scanf("%d", &input) == 1))
    {
        if (1 == i       //first input
           || input < min)
        {
            min = input;
        }
    }

    printf("The minum is: %d\n", min);
    
    return 0;
}