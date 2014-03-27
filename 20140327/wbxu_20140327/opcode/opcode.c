#include <stdio.h>

void
getopcode(unsigned char *pbegin, unsigned char *pend, unsigned char *strresult, int *icount)
{
    unsigned char *p;
    int i;

    for (p = pbegin, i = 0; p < pend; p++, i++)
    {
        *(strresult + i) = *p;
    }

    *icount = i;
}

void
output(unsigned char *strresult, int icount)
{
    int i;
    
    for (i = 0; i < icount; i++)
    {
        printf("%02X ", strresult[i]);

        if (0 == (i + 1) % 8)
        {
            printf("\r\n");
        }
    }
}


int
funtest()
{
    printf("Hello world\r\n");
    return 0;
}
/*
将
int funtest()
{
printf("Hello world\r\n");
return 0;
}
在本机的机器码用十六进制输出来
*/
int
main(void)
{
    unsigned char strresult[1024] = {0};
    int icount;

    unsigned char *pbegin = (unsigned char *)0x0040B800;
    unsigned char *pend   = (unsigned char *)0x0040B838;

    //funtest();

    getopcode(pbegin, pend, strresult, &icount);
    
    output(strresult, icount);

    return 0;
}