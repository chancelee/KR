#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NUM 32

int
main(void)
{
    char *pch = NULL;           //necessary

    pch = (char *)malloc(NUM);

#if 1
    //again
    //free(pch);
    pch = (char *)malloc(NUM);

    //again
    pch = (char *)malloc(NUM);
#endif

    if (NULL == pch)            //necessary
    {
        //can we printf sth here? will succeed?
        return -1;
    }
    else
    {
        //do sth
        strncpy(pch, "hello world\r\n", NUM - 1);
        *(pch + NUM - 1) = '\0';
        
        printf("%s", pch);
    }

    if (pch != NULL)            //had better
    {
        free(pch);
        pch = NULL;
    }    

    return 0;
}