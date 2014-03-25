#include <stdio.h>

#define X   3
#define Y   2
#define Z   4

void
output(int (*array)[Z])
{
    int i,j;

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Z; j++)
        {
            printf("%d ", *(*(array + i) + j));
        }

        printf("\n");
    }
}

/*
Function; arryA[X][Y] * arryB[Y][Z] = arryC[X][Z]
*/
void
matrix_ary(int arrayA[][Y], int arrayB[][Z], int arrayC[][Z])
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

void
test_matrix_ary(int arrayA[][Y], int arrayB[][Z])
{
    int arrayC[X][Z] = {0};

    matrix_ary(arrayA, arrayB, arrayC);

    output(arrayC);

}

/*
Function; arryA[X][Y] * arryB[Y][Z] = arryC[X][Z]
*/
void
matrix_pointer(int (*arrayA)[Y], int (*arrayB)[Z], int (*arrayC)[Z])
{
    int i, j, k;
    
    //C[i][j] = ADD(A[i][k],B[k][j])
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Z; j++)
        {
            for (k = 0; k < Y; k++)
            {
                *(*(arrayC + i) + j) += (*(*(arrayA + i) + k)) * (*(*(arrayB + k) + j));
            }
        }
    }

}

void
test_matrix_pointer(int (*arrayA)[Y], int (*arrayB)[Z])
{
    int arrayC[X][Z] = {0};

    matrix_pointer(arrayA, arrayB, arrayC);

    output(arrayC);

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

    //test_matrix_ary(arrayA, arrayB);

    test_matrix_pointer(arrayA, arrayB);


    return 0;
}