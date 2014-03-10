#include <stdio.h>
#include <stdlib.h>

int
charsearch(char str[], char c)
{
    int i = 0;

    int iresult = 0;

    while (str[i])
    {
        if (c == str[i])
        {
            iresult = 1;
            break;
        }

        i++;
    }

    return iresult;
}

int
main(void)
{
    char str[16] = "\0";
    char c;

    int i;
    int iresult;

    printf("Please enter no more than 15 char: ");

    //To deal with input safely.
    for (i = 0; i < 15 && ((c = getchar()) != EOF) && (c != '\n'); i++)
    {
        str[i] = c;
    }

    //str[15] = '\0';

    while (((c = getchar()) != EOF) && (c != '\n'))
    {
        //nothing, just to remove the remainning inputs last time
        ;
    }

    printf("Please enter one char you want to search: ");

    c = getchar();  
    
    
    iresult = charsearch(str, c);

    if (1 == iresult)
    {
        printf("Found\r\n");
    }
    else
    {
        printf("Not found\r\n");
    }


    system("pause");

    return 0;
}