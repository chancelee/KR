#include <stdio.h>

#define MAX 128

void
init(char *ary)
{
    char *p;
    int i;

    for (p = ary, i = 0; p < ary + MAX; p++, i++)
    {
        *p = i;
    }
}

void
getinput(int *iROW, int *iCOL)
{
    printf("Please enter the ROW, COL u want to define:\r\n");
    scanf("%d%d", iROW, iCOL);
    fflush(stdin);
}

char 
getaryelmt(char *ary, int nsize, int i, int j)
{
    /*
    type ary[M][N];
    type *p = &ary[0][0]

    addr(ary[i][j]) = (int)ary + sizeof(type[N]) * i + sizeof(type) * j
                    = (int)ary + sizeof(type) * ( N * i + j)
                    = (int)p + sizeof(type) * (N * i + j) 
    
    ary[i][j] = *(p + N * i + j)

    */

    return *(ary + nsize * i + j );
}

void
test_getaryelmt(char *ary, int iROW, int iCOL)
{
    int i, j;

    for (i = 0; i < iROW; i++)
    {
        for (j = 0; j < iCOL; j++)
        {
            printf("%2X ", getaryelmt(ary, iCOL, i, j));
        }
        printf("\r\n");
    }
    
}

int
main(void)
{
    char arybase[MAX] = {0}; /*Used as base, can be splitted into e.g ary[M][N]*/
    int iROW, iCOL;

    init(&arybase[0]);

    getinput(&iROW, &iCOL);

    test_getaryelmt(&arybase[0], iROW, iCOL);

    return 0;
}