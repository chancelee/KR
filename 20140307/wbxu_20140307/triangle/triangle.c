#include <stdio.h>

#define N   15

void
output(int array[])
{
    int i = 0;

    long sum = 0;

    while (array[i] && (i < N))
    {
        printf("%d ", array[i]);

        sum += array[i];

        i++;
    }

    printf("        sum = %ld\r\n\r\n", sum);
}

/*
Function: use one-dimension array to calculate triangle.
*/
void
method1(void)
{
    int i, j;
    int tmp1, tmp2;

    int array[N] = {1, 0};

    for (i = 0; i < N; i++ )
    {
        tmp1 = array[0];
        tmp2 = array[1];

        for (j = 1; j < i; j++)
        {
            array[j] = array[j] + tmp1;
            tmp1     = tmp2;
            tmp2     = array[j+1] ;          
            
        }

        //the last one must be set to 1
        array[i] = 1;

        output(array);
    }
}

/*
Function: use 2-dimension array to calculate triangle.
*/
void
method2(void)
{
    int array[N][N] = {1,0};

    int i, j;

    for (i = 0; i < N; i++)
    {
        array[i][0] = 1;

        for (j = 1; j < i; j++)
        {
            array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
        }

        array[i][i] = 1;

        output(array[i]);
    }

}

int
main(void)
{
    method1();

    method2();

    return 0;
}
