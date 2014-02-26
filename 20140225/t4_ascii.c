#include <stdio.h>

int
main()
{
    char *pch = "09AZaz";
    
    while(*pch)
    {
        printf("'%c' = (%d)10 = (0%o)8 = (0x%X)16\n", *pch, *pch, *pch, *pch);
        pch++;
    }
    return 0;
}