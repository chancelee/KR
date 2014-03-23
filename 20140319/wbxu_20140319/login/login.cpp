// login.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#define MAX_TRY     3

#define UNICODE

/*deal with ANSI / UNICODE */
#ifdef  UNICODE 

#define _tprintf    wprintf
#define _tscanf     wscanf
#define _tcslen     wcslen

#define _TCHAR      wchar_t
#define _T(x)       L##x

#else   //not defined UNICODE

#define _tprintf    printf
#define _tscanf     scanf
#define _tcslen     strlen

#define _TCHAR      char
#define _T(x)       x

#endif  //

/*
Function: decipher key code at base with the help of szInput.
*/
void
decipher(_TCHAR szInput[], int base, DWORD dwSize)
{    
    DWORD oldProtect;   
    size_t length;
    unsigned long i;
    char ary[1]; 
    char code;  

    length = _tcslen(szInput) * sizeof(_TCHAR);

    VirtualProtect( 
        (void *)base, 
        dwSize, 
        PAGE_EXECUTE_READWRITE, 
        &oldProtect 
        );

    for (i = 0; i < dwSize; i++)
    {
        code = ary[(base + i - (int)ary)];
        ary[(base + i - (int)ary)] = algorithm((char *)szInput, length, code, i);
    }

    VirtualProtect( 
        (void *)base, 
        dwSize, 
        oldProtect, 
        &oldProtect 
        );

}

void
restore(char szCode[], int base, DWORD dwSize)
{
    DWORD oldProtect;
    unsigned long i;
    char ary[1]; 
    
    VirtualProtect( 
        (void *)base, 
        dwSize, 
        PAGE_EXECUTE_READWRITE, 
        &oldProtect 
        );
    
    for (i = 0; i < dwSize; i++)
    {
        ary[(base + i - (int)ary)] = szCode[i];
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
verify(int base, DWORD dwSize)
{
    unsigned long hash;

    hash = ror_hash((char *)base, dwSize, 14, 7);

    //compare with the hash of  right key code 
    if (0x9be7fee3 != hash)
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
    //code already ciphered.
    //No need to deal with code with UNICODE or ANSI
    unsigned char  szCode[117] = {
        0x5F, 0x13, 0x06, 0x0D, 0xB9, 0x55, 0xDB, 0x52, 0x85, 0x6F, 0x34, 0x00, 0x6C, 0x83, 0xF0, 0x04, 
            0x82, 0xE0, 0x3D, 0x8D, 0x70, 0x88, 0x3C, 0xE8, 0x97, 0xFA, 0xAC, 0xFF, 0xEE, 0xC4, 0x25, 0x3D, 
            0x01, 0x5D, 0xAF, 0xDA, 0x27, 0x26, 0x07, 0x13, 0x5F, 0x0D, 0xE1, 0x4D, 0xBC, 0x51, 0xBB, 0x49, 
            0x6C, 0x00, 0x35, 0x83, 0xA8, 0x04, 0xE5, 0xE0, 0x03, 0x8D, 0x38, 0x88, 0x67, 0xE8, 0x11, 0xFA, 
            0xCB, 0xFF, 0xD0, 0xC4, 0x7D, 0x3D, 0xAF, 0xB5, 0x05, 0xA9, 0x41, 0x02, 0xB8, 0x05, 0x84, 0x27, 
            0xCA, 0xFF, 0x93, 0x83, 0x49, 0x84, 0x50, 0x75, 0x62, 0x68, 0x79, 0x50, 0x2E, 0x00, 0xDC, 0x49, 
            0x56, 0x00, 0x6D, 0x83, 0xF1, 0x04, 0x87, 0x0D, 0x5C, 0x1C, 0x03, 0x42, 0x6D, 0xE8, 0x0F, 0x05, 
            0x6C, 0x00, 0xB7, 0xC4, 0x57
    };
    

    int base;
    DWORD dwSize;

    _TCHAR szInput[16];
    int i = 0;

    base = 0x00401611;
    dwSize = 0x84;
    
    _tprintf(_T("Please Enter the passwd, ")
           _T("you can only try %d times\r\n"), MAX_TRY);
    
    while (i < MAX_TRY)
    {
        _tprintf(_T("Trying the %d time: "), i + 1);
        
        //TODO
        _tscanf(_T("%15s"), szInput);
        fflush(stdin);

        //use szInput to decipher key code at base
        decipher(szInput, base, dwSize);

        //verify whether decipher ok
        if (0 == verify(base, dwSize))
        {
            //restore the key code for next try;
            restore((char *)szCode, base, dwSize);

            i++;

            continue;
        }
        else
        {
            //nothing, go on

        }

        if (0xDA9B5D6D == ror_hash((char *)szInput, _tcslen(szInput) * sizeof(_TCHAR), 13, 19)      //ANSI
            || 0xa969b59a == ror_hash((char *)szInput, _tcslen(szInput) * sizeof(_TCHAR), 13, 19)   //UNICODE
            )
        {
            //do what u want to do;
            break;
        }
    }
    
    if (MAX_TRY == i)
    {
        _tprintf(_T("Sorry!! U r under arrest\r\n"));
    }
    else
    {
        _tprintf(_T("Congratulations!!\r\n"));
    }
}


int
main(void)
{
    login();
 
    return 0;
}