#include <stdio.h>

#define X   3
#define Y   2
#define Z   4

void
output(int array[][Z])
{
    int i,j;

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Z; j++)
        {
            printf("%d ", array[i][j]);
        }

        printf("\n");
    }
}

void
matrixMultiply (int arrayA[][Y], int arrayB[][Z], int arrayC[][Z])
{
    int i, j, k;

    //C[i][j] = ADD(A[i][k],B[k][j])
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Z; j++)
        {
            for (k = 0; k < Y; k++)
            {
                arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
            }
        }
    }
}

int
main(void)
{
    int arrayA[X][Y] =  {
        {2, -6},
        {3, 5},
        {1, -1}
    };

    int arrayB[Y][Z] = {
        {4,  -2, -4, -5}, 
        {-7, -3, 6,  7}
    };

    int arrayC[X][Z] = {0};

    matrixMultiply(arrayA, arrayB, arrayC);

    output(arrayC);

    return 0;
}