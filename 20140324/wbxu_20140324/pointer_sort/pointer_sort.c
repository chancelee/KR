#include <stdio.h>

/*
����3�����ͱ�����ָ�����ͱ�����ָ�����������3��ָ�����������ݵ����롢��С�������������
*/


/*
  this is used to exchange ia, ib and ic
  makes ia be the min, ic be the max
*/
void
exchange_value(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

/*
  this is used to exchange pa, pb, pc,
  makes pa points to the min, pc points the max
*/
void
exchange_pointer(int **x, int **y)
{
    *x = (int)*x ^ (int)*y;
    *y = (int)*x ^ (int)*y;
    *x = (int)*x ^ (int)*y;    
}


int
main(void)
{
    int ia, ib, ic;
    int *pa = &ia;
    int *pb = &ib;
    int *pc = &ic;

    printf("Please enter 3 int numbers:\r\n");
    scanf("%d%d%d", pa, pb, pc);

    if (*pa > *pb)
    {
#ifdef  VAULE
        exchange_value(pa, pb);  //exchange *pa, *pb, makes ia be the min,
#else
        exchange_pointer(&pa, &pb); //exchange pa, pb , makes pa points to the min
#endif
    }

    if (*pa > *pc)
    {
#ifdef VALUE
        exchange_value(pa, pc);  
#else
        exchange_pointer(&pa, &pc);
#endif
    }

    if (*pb > *pc)
    {
#ifdef  VALUE
        exchange_value(pb, pc);
#else
        exchange_pointer(&pb, &pc);
#endif
        
    }

    printf("%d %d %d\r\n", *pa, *pb, *pc);



    return 0;
}