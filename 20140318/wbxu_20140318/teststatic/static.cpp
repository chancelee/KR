#include <stdio.h>

void
test_static(int x)
{
    static int si = x;
    static int sj = x;

    si++;
    sj++;

    {
        static int sk = 0x12345678;
    }
}

int
main(void)
{
    int i = 10;
    
    while (i++ < 13)
    {
        test_static(i);
    }

    return 0;    
}