#include <stdio.h>

#define MAX 4

void
showmenu(void)
{
    printf("This is the Process U can select:\r\n"
            "--------------------------------\r\n"
            "0. ProcessA                     \r\n"
            "1. ProcessB                     \r\n"
            "2. ProcessC                     \r\n"
            "3. ProcessD                     \r\n"
            );
}

/*
Function: store user input.

Param   : icount is used to count 
*/
void
getinput(int *aryselect, int *icount)
{
    int iselect;
    int i;

    showmenu();

    printf("Please select any of them , end with -1\r\n");

    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &iselect);

        if (-1 == iselect)
        {
            break;
        }

        if (iselect < 0 || iselect >= MAX)
        {
            //make sure this is right
            i--;
            continue;            
        }

        *(aryselect + i) = iselect;
    }
   
    *icount = i;
}

void
processA(void)
{
    printf("Within processA\r\n");
}

void
processB(void)
{
    printf("Within processB\r\n");
}

void
processC(void)
{
    printf("Within processC\r\n");
}

void
processD(void)
{
    printf("Within processD\r\n");
}

void
process(void (*pfnprocess[])(void), int *aryselect, int icount)
{
    int i;

    for (i = 0; i < icount; i++)
    {
        //pfnprocess[aryselect[i]]();
        //pfnprocess[*(aryselect + i)]();
        (*(pfnprocess + (*(aryselect + i))))();
    }
}

/*
    test for jump table
*/
int
main(void)
{
    int aryselect[MAX] = {0};
    void (*pfnprocess[])(void) = {
        processA, processB, processC, processD     //jump table
    };

    int icount;

#if 0

    int i;
    
    getinput(aryselect, &icount);

    for (i = 0; i < icount; i++)
    {
        //pfnprocess[aryselect[i]]();
        //pfnprocess[*(aryselect + i)]();
        (*(pfnprocess + (*(aryselect + i))))();
    }
#else

    getinput(aryselect, &icount);

    process(pfnprocess, aryselect, icount);

#endif

    return 0;
}