#include <stdio.h>
#include <stdlib.h>

void
exchange(int *x, int *y)
{
    int tmp;

    printf("address(x) = %p, *x = %d ", &x, *x);
    printf("address(y) = %p, *y = %d ", &y, *y);

    system("pause");
    
    tmp = *x;
    *x   = *y;
    *y   = tmp;

    printf("address(x) = %p, *x = %d ", &x, *x);
    printf("address(y) = %p, *y = %d ", &y, *y);

    system("pause");
}

int
main(void)
{
    int a;
    int b;

    a = 3;
    b = 5;

    printf("address(a) = %p, a = %d ", &a, a);
    printf("address(b) = %p, b = %d ", &b, b);

    system("pause");

    exchange(&a, &b);

    printf("address(a) = %p, a = %d ", &a, a);
    printf("address(b) = %p, b = %d ", &b, b);

    system("pause");

    return 0;
}