#include <stdio.h>

int
main(void)
{
    int i;
 
    for (i = 0; i < 128; i++)
    {
        printf("%c  ", i);
        if (0 == ((i + 1) % 4))
        {
            printf("\n");
        }

    }

    return 0;
}