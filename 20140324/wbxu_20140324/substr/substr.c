#include <stdio.h>
#include <string.h>
#include <assert.h>

#define     MAX     128

/*
Function:  substract src[m, m+1, m+2,...m+n-1] ,store into dst

Attention: the caller should make sure that src[m], src[m+n-1] not out of band.
*/
void
substr(char *src, char *dst, int m, int n)
{
    int i;

    for (i = m; i < m + n; i++)
    {
        *(dst + i - m) = *(src + i);
    }
    
    *(dst + i - m) = '\0';
}

void
getinput(char *szinput, int *start, int *size)
{
    printf("Please enter the strings:\r\n");    
    scanf("%127s", szinput);
    fflush(stdin);

    printf("Please enter the start and size you want to sub (0-BASED):\r\n");
    scanf("%d%d", start, size); 
    fflush(stdin);
}


int
main(void)
{
    char szinput[MAX];
    char szdst[MAX];
    int  istart, isize;

    getinput(szinput, &istart, &isize);

    substr(szinput, szdst, istart, isize);

    printf("dst: %s\r\n", szdst);
    

    return 0;
}