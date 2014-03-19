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
mymemcpy(char strdst[], char const strsrc[], size_t count)
{
    unsigned i;

    for (i = 0; i < count; i++)
    {
        strdst[i] = strsrc[i];
    }
}

/*
The memmove function copies count bytes of characters from src to dest. 
If some regions of the source area and the destination overlap, 
    memmove ensures that the original source bytes in the overlapping region are copied 
    before being overwritten.
  

  --|---------|-----|--------|------
  src        dst   src+n-1   dst+n-1

    src < dst <= src + n - 1  (overlapped)
*/
void
mymemmove(char strdst[], char strsrc[], size_t count)
{
    int i;

    if (((unsigned)strdst > (unsigned)strsrc)
        &&((unsigned)strdst < (unsigned)strsrc + count))
    {
        //overlap happens, we need to deal with specially
        for (i = count - 1; i >= 0; i--)
        {
            strdst[i] = strsrc[i];
        }
    }
    else
    {
        mymemcpy(strdst, strsrc, count);
    }

}

void
test_mymemcpy(void)
{
    //char szsrc[32] = "Test for mymemcpy";
    //char szdst[32];

    char string1[60] = "The quick brown dog jumps over the lazy fox";
    char string2[60] = "The quick brown fox jumps over the lazy dog";
    
    printf( "Function:\tmemcpy without overlap\n" );
    printf( "Source:\t\t%s\n", string1 + 40 );
    printf( "Destination:\t%s\n", string1 + 16 );
    
    mymemcpy( string1 + 16, string1 + 40, 3 );
    
    printf( "Result:\t\t%s\n", string1 );
    printf( "Length:\t\t%d characters\n\n", mystrlen( string1 ) );
}

void
test_mymemmove(void)
{
    char string1[60] = "The quick brown dog jumps over the lazy fox";
    char string2[60] = "The quick brown fox jumps over the lazy dog";
    
    printf( "Function:\tmemmove with overlap\n" );
    printf( "Source:\t\t%s\n", string2 + 4 );
    printf( "Destination:\t%s\n", string2 + 10 );

    mymemmove( string2 + 10, string2 + 4, 40 );

    printf( "Result:\t\t%s\n", string2 );
    printf( "Length:\t\t%d characters\n\n", mystrlen( string2 ) );

}

int
main(void)
{
    test_mymemcpy();

    test_mymemmove();

    return 0;
}