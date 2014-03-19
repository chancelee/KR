#include <stdio.h> 

#define IMAGE_BASE          0x00400000

#define MZ                  0x00905A4D

int g_var1 = 0x12345678;
int g_var2 = 0x11223344;

/*

  -------|---------|----------|---------|----
  0x00400000     0x3C        0x28       arry
  
*/

int
main(void)
{
    int ary[1];
    int addr;
    int mz;

    mz = ary[(IMAGE_BASE - (int)ary) / sizeof(int)];

    if (mz != MZ)
    {
        printf("Not the default ImageBase!\n");
        
        return -1;
    }


    addr = (int)(&g_var1);
    printf("offset of g_var1 in exe file is 0x%p\r\n", addr - 0x00400000);

    //now we can fopen exe file, seek to this address, read 4 bytes, compare with it.

    addr = (int)(&g_var2);    
    printf("offset of g_var1 in exe file is 0x%p\r\n", addr - 0x00400000);

    return 0;
}