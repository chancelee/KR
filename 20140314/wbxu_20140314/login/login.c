#include <stdio.h>
#include <windows.h>

#include "hash.h"

#define MAX_TRY     3

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

    base = 0x00401282;
    dwSize = 0x42;

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

}

void
login(void)
{
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
        
        if (0xDA9B5D6D == ror13_hash(szInput))
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
    //ror13_hash("5l4Sm");

    login();
    
    return 0;
}