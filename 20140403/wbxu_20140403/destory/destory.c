#include <stdio.h>
#include <string.h>
#include <malloc.h>

int
main(void)
{
    char sztext[] = "hello world!\r\n";
    size_t len    = 0;
    char *psz     = NULL;

    len = strlen(sztext);
#if 0
    psz = (char *)malloc(len); // this will destory the heap, should be len + 1;
#else
    psz = (char *)malloc(len + 1);
#endif
    if (NULL == psz)
    {
        goto ERROR_PROCESS;
    }
    else
    {
        strcpy(psz, sztext);
    }

ERROR_PROCESS:
    if (psz)
    {
        free(psz);
        psz = NULL;
    }

    return 0;
}