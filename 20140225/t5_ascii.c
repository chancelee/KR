#include <stdio.h>

int
main(void)
{
    char ch;

    printf("Please input one character: ");
   
    scanf("%c", &ch);
    printf("Output: %d\n", ch - '0');
    

    return 0;
}