#include <stdio.h>

int
main(void)
{
    int a;
    int b;

    printf("Please enter 2 int numbers: ");
    
    scanf("%d%d", &a, &b);

    if ( a > b)
    {
        printf("%d > %d\n", a, b);
    }
    else if ( a == b )
    {
        printf("%d == %d\n", a, b);
    }
    else
    {
        printf("%d < %d\n", a, b);
    }
    
    return 0;
}