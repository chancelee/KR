#include <stdio.h>
#include "show_bytes.h"


void
show_bytes(byte_pointer start, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
    {
        printf("%.2X", start[i]);
    }
    
    printf("\n");
}