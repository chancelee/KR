#include <stdio.h>
#include <string.h>

#define MAX_TRY     3

#define USER    "51asm"
#define PASSWD  "5l4Sm"

int
main(void)
{
    char szInput[16];
    int i = 0;

    printf("USER: %s  PASSWD: %s\r\n", USER, PASSWD);
    printf("Please Enter the PASSWD for %s,"
           "you can only try %d times\r\n", USER, MAX_TRY);

    while (i < MAX_TRY)
    {
        printf("Trying the %d time: ", i + 1);

        gets(szInput);
        if (0 == strcmp(PASSWD, szInput))
        {
            printf("Congratulations!!\r\n");
            break;
        }

        i++;
    }

    if (MAX_TRY == i)
    {
        printf("Sorry!! U r under arrest\r\n");
    }

    return 0;
}