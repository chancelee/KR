/************************************************************************/
/* 解析浮点编码,要求使用两种方式做：
1>使用宏和位运算做
2>使用位段做    

  s  eee eeee  e   ddd dddd dddd dddd dddd dddd
  1  000 0000  0   000 0000 0000 0000 0000 0000     SIGN
  0  111 1111  1   000 0000 0000 0000 0000 0000     EXP  
  0  000 0000  0   111 1111 1111 1111 1111 1111     fraction
                                                                 */
/************************************************************************/
#include <stdio.h>

#define SIGN    0x80000000
#define EXP     0x7F800000
#define DATA    0x007FFFFF

struct tag_float
{   
    unsigned data :23;
    unsigned exp  :8;
    unsigned sign :1;
};

void
test_bitfield(void)
{
    struct tag_float test;
    
    int sign = 0;
    int exp  = 128;
    int data = 0x490FDA;
    
    test.sign = sign;
    test.exp  = exp;
    test.data = data;
}

void
showinfo(void *pvdata, int sign, int exp, int data)
{
    printf("sign part of %f is : dec(%d)\r\n", *(float *)pvdata, sign);
    printf("exp  part of %f is : dec(%d)\r\n", *(float *)pvdata, exp);
    printf("data part of %f is : hex(%p)\r\n", *(float *)pvdata, data);
}
  
void
decode_by_macro(void *pvdata)
{
    unsigned sign = 0;
    unsigned exp  = 0;
    unsigned data = 0;

    printf("%p\r\n", *(unsigned *)pvdata);
    sign = (*(unsigned *)pvdata & SIGN) >> 31;
    exp  = (*(unsigned *)pvdata & EXP)  >> 23;
    data = (*(unsigned *)pvdata & DATA);

    showinfo(pvdata, sign, exp, data);
}

void
decode_by_bitfield(void *pvdata)
{
    struct tag_float *ptagfloat = (struct tag_float *)pvdata;
    unsigned sign = 0;
    unsigned exp  = 0;
    unsigned data = 0;

    printf("%d\r\n", sizeof(struct tag_float));

    if (NULL == ptagfloat)
    {
        return;
    }

    sign = ptagfloat->sign;
    exp  = ptagfloat->exp;
    data = ptagfloat->data;

    showinfo(pvdata, sign, exp, data);
}

int
main(void)
{
    float ftest = 3.1415926f;

    decode_by_macro((void *)&ftest);

    decode_by_bitfield((void *)&ftest);

    test_bitfield();

    return 0;
}