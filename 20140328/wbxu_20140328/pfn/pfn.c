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
        pfnprocess[aryselect[i]]();
        //pfnprocess[*(aryselect + i)]();
        //(*(pfnprocess + (*(aryselect + i))))();
    }
}

/*
假设现有4个基本的处理流程ProcessA, ProcessB, ProcessC, ProcessD。
但这些基本处理流程在不同的场景下或多或少，或先或后。
要求利用函数指针来模拟这种情况。

1)给定4个可选流程
2)用户可从中随机不重复的选择多个
3)程序根据用户的选择来显示执行效果。
*/
int
main(void)
{
#define  ARY
#ifndef ARY
    void (*pfnprocess[])(void) = {
        processA, processB, processC, processD     //jump table
    };
#else
    typedef void (*PFNPROCESS)(void);

    PFNPROCESS pfnprocess[] = {
        processA, processB, processC, processD     //jump table
    };

#endif

    int aryselect[MAX] = {0};
    int icount;

    getinput(aryselect, &icount);

    process(pfnprocess, aryselect, icount);

    return 0;
}