#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

void
init(int *iary)
{
    int *p = NULL;

    srand((unsigned)time(NULL));

    for (p = iary; p < iary + NUM; p++)
    {
        *p = rand() % 100;
    }
}

void
output(int *iary, int *max, int *min)
{
    int *p;

    for (p = iary; p < iary + NUM; p++)
    {
        printf("%d ", *p);
    }
    printf("\r\n");

    printf("max = %d, min = %d\r\n", *max, *min);
}

/*
    Take care we need to change int *max, *min in caller, 
    so, we need to int **max, int **min in callee;
*/
void
getmaxmin(int *iary, int **max, int **min)
{
    int *p;

    for (p = iary; p < iary + NUM; p++)
    {
        if (*p > **max)
        {
            *max = p;
        }

        if (*p < **min)
        {
            *min = p;
        }
    }
}

int
main(void)
{
    int iary[NUM];
    int *max = NULL;
    int *min = NULL;

    init(iary);

    max = &iary[0];
    min = &iary[0];

    getmaxmin(iary, &max, &min);

    output(iary, max, min);

    return 0;
}