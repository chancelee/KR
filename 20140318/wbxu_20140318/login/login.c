#include <stdio.h>
#include <windows.h>

#include "hash.h"

#define MAX_TRY     3
#define RIGHT       0  //TODO

/*
Function: restore the key code with the help of szInput[]

*/
void
decipher(char szInput[])
{
    DWORD dwSize;
    DWORD oldProtect;
    int base;
    int i;
    int length;
    char ary[1]; 
    char code;  

    base = 0x0040155F;
    dwSize = 0x53;

    length = strlen(szInput);

    VirtualProtect( 
        (void *)base, 
        dwSize, 
        PAGE_EXECUTE_READWRITE, 
        &oldProtect 
        );

    for (i = 0; i < dwSize; i++)
    {
        code = ary[(base + i - (int)ary)];
        ary[(base + i - (int)ary)] = algorithm(szInput, length, code, i);
    }

    VirtualProtect( 
        (void *)base, 
        dwSize, 
        oldProtect, 
        &oldProtect 
        );

}

void
restore(char szCode)
{

    DWORD dwSize;
    DWORD oldProtect;
    int base;
    int i;
    char ary[1]; 
    
    base = 0x0040155F;
    dwSize = 0x53;
    
    VirtualProtect( 
        (void *)base, 
        dwSize, 
        PAGE_EXECUTE_READWRITE, 
        &oldProtect 
        );
    
    for (i = 0; i < dwSize; i++)
    {
        //ary[(base + i - (int)ary)] = szCode[i];
    }

    VirtualProtect( 
        (void *)base, 
        dwSize, 
        oldProtect, 
        &oldProtect 
        );

}

/*
Function: verify whether decipher the key code ok,
          1 for ok, 0 for failed.
*/
int
verify(void)
{
    DWORD dwSize;
    int base; 

    unsigned long hash;
    
    base = 0x0040155F;
    dwSize = 0x53;

    hash = ror_hash(base, dwSize, 14, 7);

    //compare with the hash of  right key code 
    if (RIGHT != hash)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

void
login(void)
{
    char szCode[] = {
        0x5F, 0x7F, 0x5E, 0x5E, 0xE0, 0x70, 0x84, 0x64, 0xBB, 0x6C, 0x34, 0x6C, 0x34, 0xD0, 0xA9, 0x31, 0x3C, 0xB9, 0x1E, 0x85, 0x64, 0x84, 0x4C, 0xAE, 0x92, 0xCA, 0xEF, 0xF0, 0x43, 0x50, 0x58, 0x31, 0xAF, 0x89, 0x18, 0x37, 0x87, 0x3F, 0xD8, 0x38, 0xD1, 0xEF, 0xF6, 0x52, 0xE4, 0x60, 0x88, 0xDF, 0xD8, 0xEE, 0x48, 0x88, 0x37, 0x26, 0x62, 0x5D, 0x58, 0x14, 0x11, 0x6D, 0xDD, 0x21, 0x31, 0x53, 0x6D, 0xB6, 0xA8, 0x30, 0xB8, 0x60, 0x5D, 0x70, 0x14, 0x11, 0x6D, 0xDD, 0x52, 0x31, 0x53, 0x6D, 0xB6, 0xA8, 0x30
    };


    int nBase;
    size_t len;
    char szInput[16];
    int i = 0;
    
    printf("Please Enter the passwd, "
           "you can only try %d times\r\n", MAX_TRY);
    
    while (i < MAX_TRY)
    {
        printf("Trying the %d time: ", i + 1);
        
        scanf("%15s", szInput);
        fflush(stdin);

        //this is used to restore key code 
        decipher(szInput);

        //verify whether decipher ok
        if (0 == verify())
        {
            //restore the key code for next try;
            restore(szCode);
            continue;
        }
        else
        {
            //nothing, go on

        }

        if (0xDA9B5D6D == ror_hash(szInput, strlen(szInput), 13, 19))
        {
            //do what u want to do;
            break;
        }
        
        i++;
    }
    
    if (MAX_TRY == i)
    {
        printf("Sorry!! U r under arrest\r\n");
    }
    else
    {
        printf("Congratulations!!\r\n");
    }
}


int
main(void)
{
    login();
 
    return 0;
}