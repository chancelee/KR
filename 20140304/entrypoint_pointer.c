#include <stdio.h>

#define IMAGE_BASE          0x00400000
#define OFFSET_E_LFANEW     0x3C
#define OFFSET_ENTRYPOINT   0x28

#define MZ    0x00905A4D
#define PE    0x00004550



int
main(void)
{
    int addr;
    int addr_PE;
    int addr_ENTRYPOINT;

    addr = IMAGE_BASE;

    if ( MZ != *(int *)addr )
    {
        printf("Not MZ\n");
        return -1;
    }

    addr_PE = addr + *(int *)(addr + OFFSET_E_LFANEW);

    if ( PE != *(int *)addr_PE )
    {
        printf("Not PE\n");
        return -1;
    }

    addr_ENTRYPOINT = addr + *(int *)(addr_PE + OFFSET_ENTRYPOINT);

    printf("AddressofEntryPoint is %p\n", addr_ENTRYPOINT);

    return 0;
    
}