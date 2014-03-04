#include <stdio.h>
#include <math.h>

int SPLIT =  3;     //how many parts you want to split the edge into
int BLOCK =  4;     //how many space within each part


/*
*/
void
printBlock(char *block)
{
    int i;

    i = 0;

    while ( i++ < BLOCK)
    {
        printf("%s", block);
    }
}

int
main(vodi)
{
    int i, j;
    int flag;

    printf("How many parts you want to split ? ");
    scanf("%d", &SPLIT);

    printf("How many spaces you want every part to be ? ");
    scanf("%d", &BLOCK);


    flag = 0;

    for (i = 0; i < (2 * SPLIT + 1); i++)
    {
        for (j = 0; j < abs(SPLIT - i); j++)
        {
            printBlock(" ");
        }
        printf("*");

        for (j = 0; j < (2 * abs(SPLIT - abs(SPLIT -i))); j++)
        {
            printBlock(" ");

            flag = 1;
        }
       
        if (1 == flag)
        {
            printf("*");
            
            flag = 0;
        }

        printf("\r\n");
    }    
   
    return 0;
}
