#include <stdio.h>

/*
palind('a') = a
palind(ch) = ch + palind(ch - 1) + ch
*/
void
palind(char ch)
{
    if( 'a' == ch)
    {
        printf("a");
    }
    else
    {
        printf("%c", ch);
        palind((char)(ch - 1));
        printf("%c", ch);
    }
}

int
main(void)
{
    char ch;

    printf("Please enter one char: ");
    scanf("%c", &ch);

    printf("palind(%c) = ");
    palind(ch);

    
  
    return 0;
}