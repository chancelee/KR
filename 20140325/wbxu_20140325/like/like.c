#include <stdio.h>

/*
����main�������Զ�ȡ�����в����������ļ�like.c��
����������2������ʱ������like football �����Do you like football? 
����������3������ʱ������like  football  basketball ʱ�����Do you like football or basketball? 
����������4�����ϲ���ʱ������like C Vb Foxpro Java ʱ���Do you like C,Vb,Foxpro or Java?
*/
int
main(int argc, char **argv)
{
    char **p = &argv[0];

    if (argc < 2)
    {
        return 0;        
    }

    //this keeps all the same 
    printf("Do you %s %s", *p, *(p + 1));
   

    for (p = &argv[2]; p < argv + argc - 1; p++)
    {
        printf(",%s", *p);
    }

    
    if (argc >= 3)
    {
        printf(" or %s", *(argv + argc - 1));
    }

    //this keeps all the same
    printf("?");    


    return 0;
}