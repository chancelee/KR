/************************************************************************/
/*
����Ȩ�޹���
        ��    ɾ    ��    ��
admin  1      1     1    1
user   1      0     0    1
guest  0      0     0    1
ban    0      0     0    0

  Ҫ��Ĺ��ܣ�
  1>����ѡ�û���
  2>ѡ���û������ѡ����
  3>�и�Ȩ�޹���
  4>��ɾ��Ȩ�޹���
                                                            */
/************************************************************************/

#include <stdio.h>

#include "authority.h"
#include "ui.h"

//��ͬ��ɫӵ�е�Ȩ��  (��ʼֵ)
unsigned char g_rule_authority[] = {
    ADD + DEL + EDIT + QUERY,   //for admin 
    ADD +  0  +    0 + QUERY,   //for user
    0   +  0  +    0 + QUERY,   //for guest
    0                           //for ban
};

//��ͬ��Ȩ��  (��ʼֵ)
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
    int rule = 0;       //�û���ɫ
    int func = 0;       //ѡ����
    char authority = 0;  //�û�Ȩ��
    int adjust = 0;      //Ҫ���ĵ�Ȩ��
    
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