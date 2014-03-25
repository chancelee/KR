#include <stdio.h>
#include <string.h>

#define MAX     128

void 
output(char *szinput)
{
    int i;
    
    printf("Result is :\r\n");

    for (i = 0; szinput[i]; i++)
    {
        printf("%c", szinput[i]);
    }
    
    printf("\n");
}

/*
Function: cut off all ch with szinput[]
          pointer version

          we just found that the array version is ugly, not necessary.
*/
int 
strcut_pointer(char *szinput, char ch)
{
    size_t len;
    char *p = NULL;

    len = strlen(szinput);

    for (p = szinput + len - 1; p >= szinput; p--)
    {
        if (ch == *p)
        {
            *p = '\0';

            strcat(szinput, p + 1);
        }
    }

    return (int)szinput;
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

/*
Function: cut off all ch within szinput[]

          array version   ugly !!!
*/
void
strcut_ary(char szinput[], char ch)
{
    int i, j, k;

    int flag;  //whether swapped, 0 for not, 1 for yes

    //k is used to count how many already removed.
    k = 0;

    for (i = 0; szinput[i]; i++)
    {
        if (szinput[i] != ch)
        {
            continue;
        }       

        //now we need to do like buble sort
        flag = 0;

        for (j = i; szinput[j] && szinput[j+1]; j++)
        {
            exchange(&szinput[j], &szinput[j+1]);

            if ((szinput[j] != ch) || (szinput[j+1] != ch))
            {
                flag = 1;
            }
        }

        if (0 == flag)
        {
            //no swap happens, szinput[i,i+1,...end] all is the char need to be removed
            szinput[i] = '\0';
            break;
        }
        else
        {
            //remove the last 
            szinput[j] = '\0';

            i -= k;

            k++;            
        }
    }
}

void
getinput(char *szinput, char *ch)
{
    printf("Please enter the string:\r\n");
    scanf("%127s", szinput);
    fflush(stdin);

    printf("Please enter the char u want to cut:\r\n");
    scanf("%c", ch);
    fflush(stdin);
}

void
test_strcut_ary(char szinput[], char ch)
{
    char sztest[MAX];

    strcpy(sztest, szinput);

    strcut_ary(sztest, ch);

    output(sztest);
}

void
test_strcut_pointer(char *szinput, char ch)
{
    char sztest[MAX];
    int iresult;

    strcpy(sztest, szinput);

    iresult = strcut_pointer(sztest, ch);

    output(sztest);

}


int
main(void)
{
    char szinput[MAX] = "\0";
    char ch;

    getinput(szinput, &ch);    
    
    //test_strcut_ary(szinput, ch);

    test_strcut_pointer(szinput, ch);  
    
    return 0;
}