#include <stdio.h>
#include "show_bytes.h"

int
main(void)
{
    int i = -12345;
   
    show_bytes((byte_pointer)&i, sizeof(int));

    return 0;
}