#include <stdio.h>

#include "ui.h"

//不同的角色 (初始值)
char  *g_rule[] = {
        "1. admin    1      1     1    1\r\n",
        "2. user     1      0     0    1\r\n",
        "3. guest    0      0     0    1\r\n",
        "4. ban      0      0     0    0\r\n",
        NULL
};

void 
showrule(void)
{
    char **psz;

    printf("            增    删    改    查\r\n");

    for (psz = g_rule; *psz; psz++ )
    {
        printf("%s", *psz);
    }
}

void
showauthority(char authority)
{
    int i = 0;

    printf("\r\nNow your authority is:\r\n");
    printf("增    删    改    查\r\n");

    for (i = 0; i < 4; i++ )
    {
        if (authority & (1 << i))
        {
            printf("1     ");
        }
        else
        {
            printf("0     ");
        }
    }
    printf("\r\n");    
}

void
selectrule(int *rule)
{
    showrule();

    printf("These are rules you can select, choose one:\r\n");
    scanf("%1d", rule);
    fflush(stdin);
}

void
selectfunction(int *func, int *adjust)
{
    printf("\r\n1. 增加权限\r\n"
        "2. 删除权限\r\n"
           );

    printf("These are functions you can select, choose one:\r\n");
    scanf("%1d", func);
    fflush(stdin);  
    
    printf("\r\n1.增\r\n"
           "2.删\r\n"
           "3.改\r\n"
           "4.查\r\n"
           );

    printf("These are authority you can choose, choose one:\r\n");
    scanf("%1d", adjust);
    fflush(stdin);  
}