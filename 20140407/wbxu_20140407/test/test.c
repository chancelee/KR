#include <stdio.h>
#include <math.h>

int 
myabs(int n)
{
    int tmp = 0;

    tmp = n >> 31;  // ��nΪ��ʱ��tmpΪ0��  Ϊ��ʱ��tmpΪ-1 (0xfff...)
    n = n ^ tmp ;   // ��nΪ��ʱ�����ֲ��䣻Ϊ��ʱ����λȡ��
    n = n - tmp;    // ��nΪ��ʱ�����ֲ��䣻Ϊ��ʱ����1
                    //�Ӷ�ʵ���ˣ���abs(n)�Ĺ��ܡ�

    return n;
}

int
main(void)
{
    int i       = 15;
    int nresult = 0;

    nresult = (i);

    return 0;
}