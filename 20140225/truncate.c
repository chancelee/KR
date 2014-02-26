#include <stdio.h>

typedef unsigned char * byte_pointer;

void
show_bytes(byte_pointer start, int len)
{
    int i;

    printf("address 0x%X:",start);
    
    for (i = 0; i < len; i++)
    {
        printf("%.2X ", start[i]);
    }
    
    printf("\n");
}

int
main()
{
    int x = 53191;    // 0x0000CFC7
    short sx;

    //
    printf("x   = %d  ", x);
    show_bytes((byte_pointer)&x, sizeof(int));

    // int --> short
    sx = x;
    printf("sx  = %hd ", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));

    return 0; 

}