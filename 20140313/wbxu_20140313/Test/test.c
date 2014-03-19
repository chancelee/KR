#include <stdio.h>
#include <string.h>

void
test_scope(void)
{
    int i, j;
    
    i = 10;
    
    {
        int a = i;
        int b = a;
    }
    
    j = (&i)[-2]; //can locate to a
    
    {
        int a = j;
        int b = a;
    }
}

void
test_fgets(void)
{
    //char *fgets( char *string, int n, FILE *stream );   

    char szInput[8];

    //fgets(szInput, sizeof(szInput), stdin);
    //gets(szInput);

    char ch;
    int *p;

    if (NULL == fgets(szInput, sizeof(szInput), stdin))
    {
        //fgets failed, do sth here
    }
    else
    {
        //scan for \n
        p = strchr(szInput, '\n');

        if (p != NULL)
        {
            *p = '\0';
        }
        else
        {
            //no \n found, flush stdin to end of file
            while ((ch = getchar()) != '\n'
                    &&(!feof(stdin))
                    &&(!ferror(stdin))
                  )
            {
                //nothing
            }            
        }
    }//end for fgets succeed
}

void
test_scanf(void)
{
    char szInput[8];

    scanf("%7s", szInput);
}

int
main(void)
{
    test_scope();

    test_fgets();
    
    //test_scanf();

    
    return 0;
}