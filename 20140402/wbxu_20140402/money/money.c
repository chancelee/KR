/*
����һ��ö�ٱ�������ö��Ԫ��Ϊ����ҵ���ֵ��Ҫ�����ö��Ԫ���ַ���

����������ҹ�9����ֵ,�ֱ�Ϊ,Ҽ��", "����", "���", "ҼԲ", "��Բ", "��Բ", "ʰԲ", "��ʰԲ", "Ҽ��Բ.
����������ҹ�6����ֵ,�ֱ�Ϊ,ҼԲ", "��Բ", "ʰԲ", "��ʰԲ", "��ʰԲ", "Ҽ��Բ.
*/
#include <stdio.h>

char szmoney[9][8] = {
    "Ҽ��", "����", "���", "ҼԲ", "��Բ", "��Բ", "ʰԲ", "��ʰԲ", "Ҽ��Բ"
};

float fmoney[9] = {
    0.1f, 0.2f, 0.5f, 1, 2, 5, 10, 50, 100
};

enum enu_money
{
    YI_JIAO,
    ER_JIAO,
    WU_JIAO,
    YI_YUAN,
    ER_YUAN,
    WU_YUAN,
    SHI_YUAN,
    WUSHI_YUAN,
    YIBAI_YUAN
};


int
main(void)
{
    enum enu_money money;
    int i;
    
    //just for test
    for (i = 0; i < 9; i++)
    {
        money = (enum enu_money)i;
        printf("%.1f %s\r\n", fmoney[money], szmoney[money]);
    }

    return 0;
}

