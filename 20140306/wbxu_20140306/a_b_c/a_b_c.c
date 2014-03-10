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

int
main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {11,4, 2, 7, 9};

    int c[5];

    int i;

    for (i = 0; i < 5; i++)
    {
        c[i] = a[i] + b[i];
    }

    output(c, 5);


    return 0;
}