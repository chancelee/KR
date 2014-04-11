#include <stdio.h>

struct tag_bitfield_1
{
    unsigned ch: 1;
    unsigned sh: 7;
    unsigned :20;
    unsigned :15;
    //float f: 23;
};                  //total 8byte

struct tag_bitfield_2
{
    char ch  :1;
    short sh :7;
    unsigned :20;
    signed   :15; 
    //float    :23;
};                  //total 12byte

struct tag_float
{   
    unsigned sign :1;
    unsigned exp  :8;
    unsigned data :23;
};

struct tag_bitfield_3
{
    unsigned data1: 23;
    unsigned      : 8;   //无名位段（保留字段）
    unsigned data2: 2;   //
    unsigned      : 0;   //跳过该存储单元中剩余的位，从下一个存储单元开始存储，这里为跳过32-2
};

int
main(void)
{
    struct tag_bitfield_1 test_1;
    struct tag_bitfield_2 test_2;
    struct tag_bitfield_3 test_3;

    printf("%d\r\n", sizeof(struct tag_bitfield_1));
    printf("%d\r\n", sizeof(struct tag_bitfield_2));

    test_3.data1 = 0;
    test_3.data2 = 4; //超过data2:2所能表示的范围，被截断位0
    test_3.data2 = 5; //
    test_3.data2 = 6; //

    return 0;
}