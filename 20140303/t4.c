#include <stdio.h>

int
main(void)
{
    char ch;

    printf("      ���˵�                 \n"
        "================================\n"
        "1. ���빦��                     \n"
        "2. ��ѧ�Ų���                   \n"
        "3. ��ӡ���                     \n"
        "0. �˳�                         \n"
        "================================\n"
 	    "��ѡ�� (0~3):");

    scanf("%c", &ch);

    switch (ch)
    {
    case '1':
        printf("������\n");
        break;
    
    case '2':
        printf("���������ѧ��ѧ��\n");
        break;

    case '3':
        printf("�������\n");
        break;

    case '0':
        printf("ллʹ��\n");
        break;

    default:
        printf("�������\n");
        break;
    }

    return 0;
}