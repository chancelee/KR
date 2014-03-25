#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

void
init(int *iary)
{
    int *p;

    srand((unsigned)time(NULL));
    
    for (p = iary; p < iary + NUM; p++)
    {
        *p = rand() % 100;
    }

}

void 
output(int array[])
{
    int i;
    
    for (i = 0; i < NUM; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

/*
Function: exchange two int pointed by pi and pj
*/
void
exchange( int *pi, int *pj)
{
    int tmp;

    tmp = *pi;
    *pi   = *pj;
    *pj   = tmp;
}


void 
reverse_ary(int array[])
{
    int i, j;

    for (i = 0, j = NUM - 1; i < j; i++, j--)
    {
        exchange(&array[i], &array[j]);
    }

}

void
reverse_pointer(int *iary)
{
    int *p = NULL;
    int *q = NULL;

    for (p = iary, q = iary + NUM - 1;
         p < q;
         p++, q--)
    {
        exchange(p, q);
    }

}

int
main(void)
{
    int iary[NUM];

    init(iary);

    output(iary);

    //reverse_ary(iary);

    reverse_pointer(iary);

    output(iary);

    return 0;
}