#include <stdio.h>
#include <string.h>

#define     MAX     128

/*
Function: the normal way to figure out whether str1 contains str2
*/
int
isstrin_normal(char *str1, char *str2)
{
    size_t len1, len2, i;
    char *p = NULL;
    char *q = NULL;
    int iresult;

    iresult = 0;

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (p = str1, q = str2; 
         p <= str1 + len1 - len2;
         p++)
    {
         for (i = 0; i < len2; i++)
         {
             //equal, will not be in
             if (*(p + i) != *(q + i))
             {
                 break;
             }
         }

         if (len2 == i)
         {
             //all is the same, str1 contains str2
             iresult = 1;
             break;
         }
         else
         {
             //need to restart again
             q = str2;
         }
    }
    
    return iresult;
}

void
test_isstrin_normal(char *str1, char *str2)
{
    int iresult;

    iresult = isstrin_normal(str1, str2);

    if (1 == iresult)
    {
        printf("str2 is in str1\r\n");
    }
    else
    {
        printf("str2 is not in str1\r\n");
    }
}

void
getinput(char *szinput1, char *szinput2)
{
    printf("Please enter two strings u want to judge:\r\n");
    scanf("%127s%127s", szinput1, szinput2);
    fflush(stdin);
}

int
main(void)
{
    char szinput1[MAX];
    char szinput2[MAX];

    getinput(szinput1, szinput2);

    test_isstrin_normal(szinput1, szinput2);


    return 0;
}