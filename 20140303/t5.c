#include <stdio.h>
#include <math.h>

int
main(void)
{
    int a, b, c;

    printf("Please enter a, b: ");

    scanf("%d%d", &a, &b);

    printf("%d\n", a + abs(b));
    
    return 0;
}