// login.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

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

/*
Function: restore the key code that has been deciphered but not right 
          for the next try.

*/
void
restore(_TCHAR szCode[], int base, DWORD dwSize)
{
#if 1
    //Actually, we can use decipher directly to gain restore

    decipher(szCode, base, dwSize);

#else

    //Not necessary to do like this if we can decipher again to gain restore.

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

#endif

}

/*
Function: verify whether decipher the key code ok,
          1 for ok, 0 for failed.
*/
int
verify(int base, DWORD dwSize)
{
    //compare with the hash of  right key code 
    if (HASH_VERIFY 
        != ror_hash((char *)base, dwSize, 14, 7))
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
    _TCHAR szInput[16];
    int i = 0;

    //for key code
    int base;
    DWORD dwSize;   

    base   = BASE;
    dwSize = SIZE;
    
    _tprintf(_T("Please Enter the passwd, ")
           _T("you can only try %d times\r\n"), MAX_TRY);
    
    while (i < MAX_TRY)
    {
        _tprintf(_T("Trying the %d time: "), i + 1);
        
        _tscanf(_T("%15s"), szInput);
        fflush(stdin);

        //use szInput to decipher key code at base
        decipher(szInput, base, dwSize);

        //verify whether decipher ok
        if (0 == verify(base, dwSize))
        {
            //restore the key code for next try;
            restore(szInput, base, dwSize);

            i++;

            continue;
        }
        else
        {
            //nothing, go on

        }

        if (HASH_PASSWD 
            == ror_hash((char *)szInput, _tcslen(szInput) * sizeof(_TCHAR), 13, 19)  
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
