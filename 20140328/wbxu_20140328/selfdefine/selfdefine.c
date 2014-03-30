#include <stdio.h>

#define MAX 128

#define TYPE  short

#define GET_ELMT(ary, col, i, j)    (*(TYPE *)((int)ary + sizeof(TYPE) * ((col) * (i) + (j))))

void
output(char *ary, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            //just used for test, we print as int directly
            printf("%2d ", *(TYPE *)((int)ary + sizeof(TYPE) * (col * i + j)));
        }
        printf("\r\n");
    }
    printf("\r\n");
}

void
getinput(int *row, int *col)
{
    printf("Please enter the ROW, COL u want to define:\r\n");
    scanf("%2d%2d", row, col);
    fflush(stdin);
}

/*
Function: init a self-defined ary.
          different ways to achieve this.

          elmsize is not necessary here,
*/
void
init(char *ary, int row, int col)
{
    int i;

    for (i = 0; i < row * col; i++)
    {
        //just for test
        //*(TYPE *)((int)ary + sizeof(TYPE) * i) = i + 0x12345678;
        *(TYPE *)((int)ary + sizeof(TYPE) * i) = i;
    }
}

TYPE 
getaryelmt(char *ary, int col, int i, int j)
{
    /*
    type ary[M][N];

    addr(ary[i][j]) = (int)ary + sizeof(type[N]) * i + sizeof(type) * j
                    = (int)ary + sizeof(type) * ( N * i + j)
    */
    int addr;
    TYPE value;

    addr = (int)ary + sizeof(TYPE) * (col * i + j);
    value = *(TYPE *)addr;

    return value;
}

void
test_getaryelmt(char *ary, int row, int col)
{
    TYPE value;
    int i, j;

    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            value = getaryelmt(ary, col, i, j);
        }
    }
}

void
rotate(char *ary, int row, int col)
{    
    int i, j;
    int tmp;
    
    //先按照对角线进行交换
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < col - i; j++)
        {
#if 0
            //swap ary[i][j], ary[col-1-j][col-1-i]
            tmp                     = ary[i][j];
            ary[i][j]               = ary[col-1-j][col-1-i];
            ary[col-1-j][col-1-i]   = tmp;
#endif  
            tmp                                          = GET_ELMT(ary, col, i, j);
            GET_ELMT(ary, col, i, j)                     = GET_ELMT(ary, col, col - 1 - j, col - 1 - i);
            GET_ELMT(ary, col, col - 1 - j, col - 1 - i) = tmp;            
        }
    }
    
    //再将行对换
    for (i = 0; i < row / 2; i++)
    {
        for (j = 0; j < col; j++)
        {
#if 0
            //swap ary[i][j], ary[MAX-1-i][j]
            tmp               = ary[i][j];
            ary[i][j]         = ary[row-1-i][j];
            ary[row-1-i][j]   = tmp; 
#endif
            tmp                                = GET_ELMT(ary, col, i, j);
            GET_ELMT(ary, col, i, j)           = GET_ELMT(ary, col, row - 1 - i, j);
            GET_ELMT(ary, col, row - 1 - i, j) = tmp;
        }
    }
}

void
test_rotate(char *ary, int row, int col)
{
    int i;

    output(ary, row, col);

    for (i = 0; i < 4; i++)
    {
        rotate(ary, row, col);
        output(ary, row, col);
    }

}


/*
自定义数组
1)用户自定义数组的大小和类型  TYPE ary[ROW][COL] 
2)对该数组进行初始化
3)获取该数组某位置的特定元素 ary[i][j]
4)对该数组进行旋转
*/
int
main(void)
{
    char arybase[MAX] = {0}; /*Used as base, can be splitted into e.g ary[M][N]*/
    int elmsize = 0;         /*elmt size, we #define TYPE int, u can change it.*/
    int nrow    = 0;               
    int ncol    = 0;      
    

    getinput(&nrow, &ncol);  /*make sure nrow and ncol be the same, if you want to rotate*/
    
    elmsize = sizeof(TYPE);  /*not used, can be removed*/ 
    init(arybase, nrow, ncol);

    test_getaryelmt(arybase, nrow, ncol);

    test_rotate(arybase, nrow, ncol);

    return 0;
}