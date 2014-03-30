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
��������4�������Ĵ�������ProcessA, ProcessB, ProcessC, ProcessD��
����Щ�������������ڲ�ͬ�ĳ����»����٣����Ȼ��
Ҫ�����ú���ָ����ģ�����������

1)����4����ѡ����
2)�û��ɴ���������ظ���ѡ����
3)��������û���ѡ������ʾִ��Ч����
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