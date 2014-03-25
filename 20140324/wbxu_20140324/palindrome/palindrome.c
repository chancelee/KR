#include <stdio.h>
#include <string.h>
#include <assert.h>

int 
palindrome(char *string)
{
    int iresult = 1;
    size_t len;
    char *pbegin = NULL;
    char *pend = NULL;

    len = strlen(string);

    for (pbegin = string, pend = string + len - 1;
         pbegin < pend;
         pbegin++, pend--)
    {
        assert(pbegin != NULL);
        assert(pend != NULL);

        if (*pbegin != *pend)
        {
            iresult = 0;
            break;
        }
    }
        
    return iresult;
}

void
getinput(char *szinput)
{
    printf("Please enter the strings u want to judge:\r\n");

    scanf("%127s", szinput);
    fflush(stdin);

}

int
main(void)
{
    char szinput[128] = {0};
    int iresult;

    getinput(szinput);

    iresult = palindrome(szinput);

    if (1 == iresult)
    {
        printf("Yes, it is\r\n");
    }
    else
    {
        printf("Nope\r\n");
    }
    

    return 0;
}