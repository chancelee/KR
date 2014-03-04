#include <stdio.h>

#define IMAGE_BASE          0x00400000
#define OFFSET_E_LFANEW     0x3C
#define OFFSET_ENTRYPOINT   0x28

#define MZ    0x00905A4D
#define PE    0x00004550

/*

  -------|---------|----------|---------|----
 0x00400000     0x3C        0x28       arry

*/

int
main(void)
{
    int arry[8] = {0};

    int mz;

    int pe;
    int offset_PE;
    int addr_PE;

    int offset_ENTRYPOINT;
    int addr_ENTRYPOINT;
    

    mz = arry[(IMAGE_BASE - (int)arry) / (sizeof(int))];

    if ( MZ != mz)
    {
        printf("Not MZ\n");
        return -1;
    }

    offset_PE = arry[((IMAGE_BASE + OFFSET_E_LFANEW) - (int)arry) / (sizeof(int))];
    addr_PE   = IMAGE_BASE + offset_PE;
    pe        = arry[(addr_PE - (int)arry) / (sizeof(int))];

    if ( PE != pe)
    {   
        printf("Not PE\n");
        return -1;
    }

    offset_ENTRYPOINT = arry[((addr_PE + OFFSET_ENTRYPOINT) - (int)arry) / (sizeof(int))];
    addr_ENTRYPOINT  = IMAGE_BASE + offset_ENTRYPOINT;

    printf("entry point is %p\n", addr_ENTRYPOINT);

    

    return 0;
    
}