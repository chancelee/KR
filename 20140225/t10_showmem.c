#include <stdio.h>

/*
ʹ��ǿ������ת������ʺʹ�ӡ��ͬ���������ֽڱ�ʾ��

һ���ֽ�ָ������һ���ֽ����У�����ÿ���ֽڶ�����Ϊ��һ���Ǹ�����

*/

typedef unsigned char * byte_pointer;


/*
��ӡ��ÿ����ʮ�����Ʊ�ʾ���ֽڣ������������������ֵ�ʮ�����Ƹ�ʽ���
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
