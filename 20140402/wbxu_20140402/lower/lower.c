/*
将一个字符串大写全部转换为小写

A: 0x41   + 0x20 ---> a: 0x61    
B: 0x42   + 0x20 ---> b: 0x62

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM 64

#define PART  0x20

int
main(void)
{
    char sztext[NUM] = "ThiS Is JuSt 4 FuN\r\n";
    size_t i;

    printf("%s\r\n", sztext);

    for (i = 0; i < strlen(sztext); i++)
    {
        if (isalpha(sztext[i]) 
            && (sztext[i] <= 'Z'))
        {
            sztext[i] |= PART;
        }
    }

    printf("%s\r\n", sztext);

    return 0;
}

