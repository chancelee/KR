#include <stdio.h>

size_t
mystrlen(char const szsrc[])
{
    size_t i = 0;

    while (szsrc[i] != '\0')
    {
        i++;
    }

    return i;
}

void
mystrcpy(char szdst[], char const szsrc[])
{
    int i = 0;

    while (szsrc[i] != '\0')
    {
        szdst[i] = szsrc[i];
        i++;
    }

    szdst[i] = '\0';
}

void
mystrcat(char szdst[], char const szsrc[])
{
    size_t i, j;

    i = mystrlen(szdst);
    j = 0;

    mystrcpy(&szdst[i], szsrc);
}

int
mystrcmp(char const szdst[], char const szsrc[])
{
    int i = 0;

    while ((szdst[i] == szsrc[i]))
    {
        if ('\0' == szsrc[i])
        {
            break;
        }

        i++;
    }

    return (szdst[i] - szsrc[i]);
}

void
mystrlwr(char szsrc[])
{
    int i;

    for (i = 0; szsrc[i] != '\0'; i++)
    {
        if (szsrc[i] >= 'A' && szsrc[i] <= 'Z')
        {
            szsrc[i] = 'a' + szsrc[i] - 'A';
        }
    }
}

void
mystrupr(char szsrc[])
{
    int i;

    for (i = 0; szsrc[i] != '\0'; i++)
    {
        if (szsrc[i] >= 'a' && szsrc[i] <= 'z')
        {
            szsrc[i] = 'A' + szsrc[i] - 'a';
        }
    }
}

void
test_mystrcpy(void)
{
    char szdst[32];
    char szsrc[32] = "Test for mystrcpy";

    mystrcpy(szdst, szsrc);

    printf("%s\r\n", szdst);
}

void
test_mystrcat(void)
{
    char szdst[32] = "Dst +";
    char szsrc[32] = "Test for mystrcat";
    
    mystrcat(szdst, szsrc);
    
    printf("%s\r\n", szdst);
}

void
test_mystrlen(void)
{
    char szsrc[32] = "12345";

    size_t len;

    len = mystrlen(szsrc);

    printf("length of \"%s\" is %d\r\n", szsrc, len);    
}

void
test_mystrcmp(void)
{
    char szdst[32] = "Test for mystrcpy";
    char szsrc[32] = "Test for mystrcpy";

    int i;

    i = mystrcmp(szdst, szsrc);

    printf("\"%s\" ", szdst);

    if (i > 0)
    {
        printf(" > ");
    }
    else if (0 == i)
    {
        printf(" == ");
    }
    else
    {
        printf(" < ");
    }

    printf("\"%s\"\r\n", szsrc);
}

void
test_mystrlwr()
{
    char szsrc[32] = "Test for STRLWR";

    printf("%s ===> ", szsrc);

    mystrlwr(szsrc);

    printf("%s\r\n", szsrc);
}

void
test_mystrupr()
{
    char szsrc[32] = "test for strUPR";

    printf("%s ===> ", szsrc);
    
    mystrupr(szsrc);
    
    printf("%s\r\n", szsrc);
    
}

int
main(void)
{
    test_mystrlen();

    test_mystrcpy();

    test_mystrcat();

    test_mystrcmp();

    test_mystrlwr();

    test_mystrupr();

    return 0;
}