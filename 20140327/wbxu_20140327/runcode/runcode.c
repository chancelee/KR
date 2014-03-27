#include <stdio.h>

/*
 This is very interesting.

 U need to store the code by yourself.
 and then run it.
 How?  function pointer!!

 Something like shellcode.
*/
int
main(void)
{
    //mov eax, 0x123;
    //ret
    unsigned char code[] = {0xB8, 0x23, 0x01, 0x00, 0x00, 0xC3};

    int (*pfn)(void) = (int (*)(void))(code);

    printf("%d\r\n", pfn());

    return 0;
}