#include <stdio.h>

/*
Function: swap two data
          we need to take pointers to thz ints as params.
*/
void
swap_data(int *pa, int *pb)
{
    int tmp;

    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

/*
Function: swap two pointers.
          we need to take pointers to thz pointers as params.

          if we want to swap two TYPE.
          then we need to take pointers to thz TYPE as params.
*/
void
swap_ptr(int **ppa, int **ppb)
{
    int *ptmp;

    ptmp = *ppa;
    *ppa = *ppb;
    *ppb = ptmp;
}

void
test_swap_data(void)
{
    int ia = 5;
    int ib = 3;
    
    if (ia > ib)
    {
        swap_data(&ia, &ib);
    }    
}

void
test_swap_ptr(void)
{
    int ia = 5;
    int ib = 3;
    int *pa = &ia;
    int *pb = &ib;

    if (ia > ib)
    {
        swap_ptr(&pa, &pb);
    }
}

int
main(void)
{

    /*We do not print out, keep an eye on the stack space by yourself.*/

    test_swap_data();

    test_swap_ptr();

    return 0;
}