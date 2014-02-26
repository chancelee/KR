#include <stdio.h>
#include <stdlib.h>

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
    short si = -12345;       //0xCFC7
    int i = 0;

    //see more than 2 bytes
    printf("si = %hd  ", si);
    show_bytes((byte_pointer)&si, sizeof(short) + 2); 

    printf("i  = %d  ", i);
    show_bytes((byte_pointer)&i, sizeof(int));

    scanf("%d", &si);
    show_bytes((byte_pointer)&si, sizeof(short) + 2);
    show_bytes((byte_pointer)&i, sizeof(int));

    scanf("%hd", &i);
    show_bytes((byte_pointer)&si, sizeof(short) + 2);
    show_bytes((byte_pointer)&i, sizeof(int));

    system("pause");

    return 0;
}