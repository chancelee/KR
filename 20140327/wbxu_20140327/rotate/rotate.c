#include <stdio.h>

#define MAX 3

void
init(int (*ary)[MAX])
{
    int *p = NULL;
    int i;
    
    p = &ary[0][0];               
    
    for (i = 0; i < (MAX) * (MAX); i++)
    {
        *p = i;
        p++;
    }
}

void
output(int (*ary)[MAX])
{
    int *p = NULL;
    int i;
    
    p = &ary[0][0];               
    
    for (i = 0; i < (MAX) * (MAX); i++)
    {
        printf("%2d ", *p);

        if (0 == (i + 1) % MAX)
        {
            printf("\r\n");
        }

        p++;
    }

    printf("\r\n");

}


/*
    
*/
void
rotate(int (*ary)[MAX])
{
    int i, j;
    int tmp;

    //先按照对角线进行交换
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX - i; j++)
        {
            //swap ary[i][j], ary[MAX-1-j][MAX-1-i]
            tmp                     = ary[i][j];
            ary[i][j]               = ary[MAX-1-j][MAX-1-i];
            ary[MAX-1-j][MAX-1-i]   = tmp;
        }
    }

    //再将行对换
    for (i = 0; i < MAX / 2; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            //swap ary[i][j], ary[MAX-1-i][j]
            tmp               = ary[i][j];
            ary[i][j]         = ary[MAX-1-i][j];
            ary[MAX-1-i][j]   = tmp;                    
        }
    }
}

int
main(void)
{
    int iary[MAX][MAX];
    int i;
    

    init(iary);
    
    output(iary);

    for (i = 0; i < MAX; i++)
    {
        rotate(iary);

        output(iary);
    }  

    return 0;
}