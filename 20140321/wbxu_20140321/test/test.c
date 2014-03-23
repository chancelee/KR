#include <stdio.h>
#include <ctype.h>


int
main(void)
{
    int i;
    int total;

    for (i = 0, total = 0; i < 128; i++)
    {
        if (0 != isgraph(i))
        {
            printf("%X(%c) ", i, i);

            if (0 == (i % 10))
            {
                printf("\r\n");
            }

            total += 1;
        }
    }

    printf("total = %d\r\n", total);
}
