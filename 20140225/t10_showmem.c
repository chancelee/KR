#include <stdio.h>

/*
使用强制类型转换类访问和打印不同程序对象的字节表示。

一个字节指针引用一个字节序列，其中每个字节都被认为是一个非负整数

*/

typedef unsigned char * byte_pointer;


/*
打印出每个以十六进制表示的字节，必须用至少两个数字的十六进制格式输出
*/
void
show_bytes(byte_pointer start, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
    {
        printf("%.2X", start[i]);
    }
    
    printf("\n");
}


int
main(void)
{
    float fx = 58.25 ;
  
    show_bytes((byte_pointer)&fx, sizeof(float));

    return 0;
}
