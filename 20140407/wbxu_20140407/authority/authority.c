/************************************************************************/
/*
做个权限管理
        增    删    改    查
admin  1      1     1    1
user   1      0     0    1
guest  0      0     0    1
ban    0      0     0    0

  要求的功能：
  1>可以选用户组
  2>选好用户组可以选功能
  3>有给权限功能
  4>有删除权限功能
                                                            */
/************************************************************************/

#include <stdio.h>

#include "authority.h"
#include "ui.h"

//不同角色拥有的权限  (初始值)
unsigned char g_rule_authority[] = {
    ADD + DEL + EDIT + QUERY,   //for admin 
    ADD +  0  +    0 + QUERY,   //for user
    0   +  0  +    0 + QUERY,   //for guest
    0                           //for ban
};

//不同的权限  (初始值)
unsigned char g_authority[] = {
    ADD,
    DEL,
    EDIT,
    QUERY
};

void
addauthority(char *authority, int adjust)
{
    *authority = *authority | (1 << (adjust - 1));
}

void
delauthority(char *authority, int adjust)
{
    *authority = *authority & (~(1 << (adjust - 1)));
}

void
adjustauthority(int func, char *authority, int adjust)
{
    switch (func)
    {
    case 1:
        {
            addauthority(authority, adjust);
            break;
        }

    case 2:
        {
            delauthority(authority, adjust);
            break;
        }
        
    default:
        {
            break;
        }
    }
}

int
main(void)
{
    int rule = 0;       //用户角色
    int func = 0;       //选择功能
    char authority = 0;  //用户权限
    int adjust = 0;      //要更改的权限
    
    selectrule(&rule);
    authority = g_rule_authority[rule - 1];
    showauthority(authority);

    while (1)
    {
        selectfunction(&func, &adjust);
        adjustauthority(func, &authority, adjust);
        showauthority(authority);
    }   
    
    return 0;
}