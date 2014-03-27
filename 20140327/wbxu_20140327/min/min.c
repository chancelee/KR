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
    ���һ����void fun(int tt[M][N],int pp[N])��
    ttָ��һ��M��N�еĶ�ά���飬�����ά����ÿ������СԪ�أ������η���pp��ָһά�����У�
    ��ά�����е��������������и��衣
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