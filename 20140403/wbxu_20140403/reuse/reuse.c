#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Demonstrate the reuse of heap.
*/
int
main(void)
{
    char sztext[] = "reuse!!!";
    size_t len    = 0;
    char *psz     = NULL;

    len = strlen(sztext);

    psz = (char *)malloc(len + 1);
    if (NULL == psz)
    {
        goto ERROR_PROCESS;
    }
    
    strcpy(psz, sztext);

    if (psz)
    {
        free(psz);

        psz = (char *)malloc(0x14 + 1 + 0x0F + 1 + 0x0F + 1 + 0x0F + 1);  //change this to demonstrate
    }
    
ERROR_PROCESS:
    if (psz)
    {
        free(psz);
        psz = NULL;
    }

    return 0;
}