#include <stdio.h>

/*�⣺

(float)(a + b) / 3 + (int) c
�����ȼ���a+b = 5
Ȼ����ת��Ϊfloat�� 5.0
Ȼ�����5.0/3 = 1.66666667

(int)c = 2

���ԣ������Ϊ3.66666667

�������ó��������֤
*/

int
main(void)
{
    int a = 3;
    int b = 2;
    double c = 2.5;

    printf("(float)(a + b) / 3 + (int)c \
           = %f\n", (float)(a + b) / 3 + (int)c);

    return 0;

}