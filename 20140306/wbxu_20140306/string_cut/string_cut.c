#include <stdio.h>

void 
output(char array[])
{
    int i;
    
    for (i = 0; array[i]; i++)
    {
        printf("%c", array[i]);
    }
    
    printf("\n");
}

/*
Function: exchange two int pointed by pi and pj
*/
void
exchange( char *pi, char *pj)
{
    char tmp;

    tmp = *pi;
    *pi   = *pj;
    *pj   = tmp;
}

void
stringcut(char array[], char c)
{
    int i, j, k;

    int flag;  //whether swapped, 0 for not, 1 for yes

    //k is used to count how many already removed.
    k = 0;

    for (i = 0; array[i]; i++)
    {
        if (array[i] != c)
        {
            continue;
        }       

        //now we need to do like buble sort
        flag = 0;

        for (j = i; array[j] && array[j+1]; j++)
        {
            exchange(&array[j], &array[j+1]);

            if ((array[j] != c) || (array[j+1] != c))
            {
                flag = 1;
            }
        }

        if (0 == flag)
        {
            //no swap happens, array[i,i+1,...end] all is the char need to be removed
            array[i] = '\0';
            break;
        }
        else
        {
            //remove the last 
            array[j] = '\0';

            i -= k;

            k++;            
        }
    }
}

int
main(void)
{
    char str[16] = "\0";
    char c;
    
    int i;
    
    printf("Please enter no more than 15 char: ");
    
    //To deal with input safely.
    for (i = 0; i < 15 && ((c = getchar()) != EOF) && (c != '\n'); i++)
    {
        str[i] = c;
    }

    //str[15] = '\0';
    
    while (((c = getchar()) != EOF) && (c != '\n'))
    {
        //nothing, just to remove the remainning inputs last time
        ;
    }
    
    printf("Please enter one char you want to cut: ");
    
    c = getchar();  
    
    
    stringcut(str, c);

    output(str);    
    
    return 0;
}