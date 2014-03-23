#include "stdafx.h"

unsigned long 
ror_hash(const char string[], size_t length, int m, int n)
{
    unsigned long hash;
    unsigned long tmp;
    size_t i, j;
    
    for (i = 0, hash = 0; i < length; i++)
    {
        tmp  = (unsigned long) string[i];

        //
        j = i;
        while(0x00 == tmp)
        {
            tmp = (unsigned long) string[++j];            
        }

        hash = (hash >> m) | (hash << n);  // 
        hash = hash + tmp;
    }
    
    return hash;
}


/*
Function: decode the key code

  Param   : length = strlen(szInput);
*/
char
algorithm(char szIput[], int length, char code, int i)
{
    char result;
    
    result = szIput[(i % length)] ^ code;
    
    return result;
}