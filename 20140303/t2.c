#include <stdio.h>
#include <stdlib.h>

#define COUNT 3

int
main(void)
{
    int min;
    int max;
    int tmp;

    int input;

    int i;

    i = 0;

    printf("Please input %d numbers: ", COUNT);

    while (i++ < COUNT 
         && (scanf("%d", &input) == 1))
    {
        if (1 == i)
        {
            min = max = input;
        }
        else
        {
            if (max < input)
            {
                tmp = max;
                max = input;               
            }
            else if (min > input)
            {
                tmp = min;
                min = input;
            }
            else
            {
                tmp = input;
            }
        }
    }//end for while

    printf("%d %d %d\n", min, tmp, max);
    
    return 0;
}