#include <stdio.h>

void 
output(int array[], int len)
{
    int i;
    
    for (i = 0; i < len; i++)
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
change(int array[], int n)
{
    int i, j;

    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        exchange(&array[i], &array[j]);
    }

}



int
main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    output(array, 10);

    change(array, 10);

    output(array, 10);

    return 0;
}