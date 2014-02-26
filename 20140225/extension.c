#include <stdio.h>
#include <stdlib.h>

/*
打印出每个以十六进制表示的字节，必须用至少两个数字的十六进制格式输出
*/

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
main(void)
{    
    short sx = -12345;          // 0xCFC7
    unsigned short usx;      
    int x;                              
    unsigned ux;  

    // the original
    printf("sx  = %hd   ", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));

    //signed short --> unsigned short
    usx = sx;
    printf("usx = %hu    ", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));

    // short ---> int
    x = sx;
    printf("x   = %d   ", x);
    show_bytes((byte_pointer)&x, sizeof(int));

    // unsigned short ---> unsigned int
    ux = usx;
    printf("ux  = %u    ", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned));

    // short ---> unsigned int
    ux = sx;
    printf("ux  = %u    ", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned));

    system("pause");

    return 0;
}