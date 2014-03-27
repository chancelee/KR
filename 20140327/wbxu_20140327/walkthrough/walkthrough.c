#include <stdio.h>

#define MAX 10

/*
    method 1: use int *p and index to init.
*/
void
init1(int (*ary)[MAX])
{
    int *p = NULL;
    int i;

    /* the key point */
    p = &ary[0][0];            
    //p = ary[0];
    //p = *(ary + 0);
    

    for (i = 0; i < (MAX) * (MAX); i++)
    {
        *p = i;
        p++;
    }
    
}

/*
  method 2: use int *p without index to init
*/
void
init2(int (*ary)[MAX])
{
    int *p = NULL;
    int i;
    
    //&ary[i][j] = &((*(ary + i))[j]) = &(*( (*(ary + i)) + j)) = (*(ary + i)) + j
    for (p = &ary[0][0], i = 0; p < &ary[MAX - 1][MAX]; p++, i++)
    {
        *p = i;
    }
}

/*
   method 3: use int (*p)[MAX] and index to init
*/
void
init3(int (*ary)[MAX])
{
    int (*p)[MAX] = NULL;
    int i, j;

    for (p = ary, i = 0; p < ary + MAX; p++, i++)
    {
        for (j = 0; j < MAX; j++)
        {
            (*p)[j] = i * (MAX) + j;
        }
    }
}

/*
  method 4: use int (*p)[MAX] and *q to init
*/
void
init4(int (*ary)[MAX])
{
    int (*p)[MAX] = NULL;
    int *q = NULL;
    int i = 0;

    for (p = ary; p < ary + MAX; p++)
    {
        for (q = *p; q < *p + MAX; q++)
        {
            *q = i;
            i++;
        }
    }
}



void
test_init1(void)
{
    int iary[MAX][MAX];

    init1(iary);
}

void
test_init2(void)
{
    int iary[MAX][MAX];

    init2(iary);

}

void
test_init3(void)
{
    int iary[MAX][MAX];

    init3(iary);
}

void
test_init4(void)
{
    int iary[MAX][MAX];
    
    init4(iary);  
}

/*
 Task: 用不同的方法实现一个二维数组的遍历
*/
int
main(void)
{
    test_init1();

    test_init2();

    test_init3();

    test_init4();

    return 0;
}