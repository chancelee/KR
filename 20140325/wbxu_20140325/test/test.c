#include <stdio.h>

void
test_string(void)
{
    char sztext[] = "Hello";
    char *psztext = "World";

    printf("%s\r\n", sztext);
    printf("%s\r\n", psztext);
    
}

char *
func1(void)
{
    int  ipad[100] = {0}; //used to protect sztext.
    char sztext[] = "test";

    return sztext;
}

void
func2(void)
{
    int ipad[500];  //used to destory the remained stack space of func1
}

/*
Function: used to check the change of stack
*/
void
test_stack(void)
{
    char *pchar = NULL;

    pchar = func1();

    func2();

    //printf("%s", pchar);
    puts(pchar);
}

int
main(void)
{
    //test_string();

    test_stack();

    return 0;
}