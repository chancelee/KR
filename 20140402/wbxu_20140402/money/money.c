/*
定义一个枚举变量，其枚举元素为人民币的面值。要求输出枚举元素字符串

第四套人民币共9种面值,分别为,壹角", "贰角", "伍角", "壹圆", "贰圆", "伍圆", "拾圆", "伍拾圆", "壹佰圆.
第五套人民币共6种面值,分别为,壹圆", "伍圆", "拾圆", "贰拾圆", "伍拾圆", "壹佰圆.
*/
#include <stdio.h>

char szmoney[9][8] = {
    "壹角", "贰角", "伍角", "壹圆", "贰圆", "伍圆", "拾圆", "伍拾圆", "壹佰圆"
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

