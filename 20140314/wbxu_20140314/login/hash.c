#include <stdio.h>

unsigned long 
ror13_hash(const char string[])
{
    unsigned long hash;
    unsigned long tmp;
    int i;
    
    for (i = 0, hash = 0; string[i] != '\0'; i++)
    {
        tmp  = (unsigned long) string[i];
        hash = (hash >> 13) | (hash << 19);  // ROR 13
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