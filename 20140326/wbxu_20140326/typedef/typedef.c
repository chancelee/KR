#include <stdio.h>

typedef int (*PFNJUST4FUN)(int, float, double, char, unsigned short);

int
just4fun(int i, float j, double k, char c, unsigned short s)
{
    return 0;
}

/*
    Test for typedef
*/
int
main(void)
{
#if 0
    int (*pfnjust4fun)(int, float, double, char, unsigned short) = NULL;

    pfnjust4fun = just4fun;

    pfnjust4fun(0, 0, 0, 0, 0);

#else
    PFNJUST4FUN pfn = NULL;

    pfn = just4fun;

    pfn(0, 0, 0, 0, 0);

    just4fun(0, 0, 0, 0, 0);

    (*pfn)(0, 0, 0, 0, 0);

#endif

    return 0;
}