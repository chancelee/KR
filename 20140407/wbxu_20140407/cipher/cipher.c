/************************************************************************/
/* 写程序实现输入字符串的加解密
   主要利用异或运算的可逆性进行                                                                     */
/************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_INPUT   32
#define MAX_KEY     8

void
removenewline(char *sztext)
{
    size_t len = strlen(sztext);

    if ('\n' == sztext[len - 1])
    {
        sztext[len - 1] = '\0';
    }
}

void
getinput(char *szinput, char *szkey)
{
    printf("Please enter the string u want to cipher:\r\n");
    //scanf("%31s", szinput);
    fgets(szinput, MAX_INPUT, stdin);    
    fflush(stdin);

    removenewline(szinput);

    printf("Please enter the key used to cipher:\r\n");
    //scanf("%7s", szkey);
    fgets(szkey, MAX_KEY, stdin);
    fflush(stdin);

    removenewline(szkey);
}

void
cipher(char *szinput, size_t inputlen, char *szkey, size_t keylen)
{
    char *psz = NULL;
    int i = 0;

    for (psz = szinput; psz < szinput + inputlen; psz++, i++)
    {
        *psz = *psz ^ *(szkey + i % keylen);
    }
    
}

int
main(void)
{
    char szinput[MAX_INPUT] = {0};
    char szkey[MAX_KEY] = {0};
    size_t inputlen = 0;
    size_t keylen = 0;

    getinput(szinput, szkey);

    inputlen = strlen(szinput);
    keylen   = strlen(szkey);

    cipher(szinput, inputlen, szkey, keylen);

    printf("after cipher: %s\r\n", szinput);

    cipher(szinput, inputlen, szkey, keylen);

    printf("after decipher: %s\r\n", szinput);

    return 0;
}