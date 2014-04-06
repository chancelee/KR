#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
    This is used to demonstrate how to process error in a beautiful way.
*/
int
main(void)
{
    char sztext[] = "Hello world!\r\n";
    size_t len    = 0;
    char *psz     = NULL;
    int *pi       = NULL;

    len = strlen(sztext);

    psz = (char *)malloc(len + 1);
    if (NULL == psz)
    {
        //
        goto ERROR_PROCESS;
    }
    else
    {   
        //do whatever u want to
        strcpy(psz, sztext);
    }

    pi = (int *)malloc(32);
    if (NULL == pi)
    {
        goto ERROR_PROCESS;
    }
    else
    {
        //do sth
    }

ERROR_PROCESS:
    if (psz)
    {
        free(psz);
        psz = NULL;
    }

    if (pi)
    {
        free(pi);
        pi = NULL;
    }    

    return 0;
}