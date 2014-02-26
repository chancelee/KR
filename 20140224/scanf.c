#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int x;
    int y;

    x = 111;	
    y = (int)&x;        //get addr of x, used for direct access

    printf("address(x) = %X\n", &x);
    printf("address(y) = %X\n", &y);

    system("pause");

    scanf("%d", &x);
    scanf("%d", y);     //direct access

    system("pause");

    printf("x = %d, y = %d\n", x, y);   

    return 0;
}