#include <stdio.h>

/*
利用main函数可以读取命令行参数，建立文件like.c。
当命令行有2个参数时，例如like football ，输出Do you like football? 
当命令行有3个参数时，例如like  football  basketball 时，输出Do you like football or basketball? 
当命令行有4个以上参数时，例如like C Vb Foxpro Java 时输出Do you like C,Vb,Foxpro or Java?
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