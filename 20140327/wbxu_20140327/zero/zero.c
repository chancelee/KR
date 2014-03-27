#include <stdio.h>

#define  N  3

void
init(int (*ary)[N])
{
    int *p = NULL;
    int i;
    
    p = &ary[0][0];               
    
    for (i = 0; i < (N) * (N); i++)
    {
        *p = i;
        p++;
    }
}

void
fun(int (*ary)[N])
{
    int (*p)[N] = NULL;
    int i;

    //zero the highest and lowest rows
    for (p = ary; p < ary + N; p += (N - 1))
    {
        for (i = 0; i < N; i++)
        {
            (*p)[i] = 0;
        }
    }

    //zero the left and right cols
    for (p = ary + 1; p < ary + N - 1; p++)
    {
        for (i = 0; i < N; i += (N - 1))
        {
            (*p)[i] = 0;
        }
    }
}

/*
��������N*N�Ķ�ά���飬�����������и�ֵ��
���д����fun�������Ĺ����ǣ��������ܱ�Ԫ����0ֵ
*/
int
main(void)
{
    int iary[N][N];

    init(iary);

    fun(iary);


    return 0;
}