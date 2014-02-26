#include <stdio.h>

/*解：

(float)(a + b) / 3 + (int) c
会优先计算a+b = 5
然后将其转换为float型 5.0
然后进行5.0/3 = 1.66666667

(int)c = 2

所以，最后结果为3.66666667

下面利用程序进行验证
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