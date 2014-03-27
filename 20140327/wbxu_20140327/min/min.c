#include <stdio.h>

#define M   3
#define N   3


void
init(int (*ary)[N])
{
    int *p = NULL;
    int i;
    
    p = &ary[0][0];               
    
    for (i = (M) * (N) - 1; i >= 0; i--)
    {
        *p = i;
        p++;
    }
}

void
fun(int (*arysrc)[N], int *arydst)
{
    int row, col;
    int min;
    int tmp;

    for (col = 0; col < N; col++)
    {
        //min = arysrc[0][col];
        min = *(*arysrc + col);

        //get min of col
        for (row = 0; row < M; row++)
        {
            tmp = *(*(arysrc + row) + col);
            if (tmp < min)
            {
                min = tmp;
            }
        }

        *(arydst + col) = min;
    }
}

/*
    请编一函数void fun(int tt[M][N],int pp[N])，
    tt指向一个M行N列的二维数组，求出二维数组每列中最小元素，并依次放入pp所指一维数组中，
    二维数组中的数已在主函数中赋予。
*/
int
main(void)
{
    int iarysrc[M][N];
    int iarydst[N];

    init(iarysrc);

    fun(iarysrc, iarydst);   

    return 0;
}