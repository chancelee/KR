#include <stdio.h>

int
main(void)
{
    char szInput[32];
    int i, ch;

    printf("Enter a line:");

    /*Read in single line from stdin*/
    for (i = 0; (i < 31) && ((ch = getchar()) != EOF)
                         && (ch != '\n'); i++)
    {
        szInput[i] = (char)ch;
    }

    /*Terminate string with null character*/
    szInput[i] = '\0';
    printf("%s\r\n", szInput);

    return 0;
}