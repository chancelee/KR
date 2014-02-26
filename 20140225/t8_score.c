#include <stdio.h>

#define NUM 2

int
main(void)
{
    char szname[NUM][8] = {0};
    char id[NUM][8] = {0};
    float fscore[NUM][3] = {0.0f};

    int i;

    for (i = 0; i < NUM; i++)
    {
        printf("Please input student %d's Name ID English Math CS:\n", i);
        scanf("%s%s%f%f%f", szname[i], id[i], &fscore[i][0], &fscore[i][1], &fscore[i][2]);
    }

    for (i = 0 ; i < NUM; i++)
    {
        printf("The info of student %d is:\n", i);
        printf("%s %s %f\n", szname[i], id[i], (fscore[i][0] + fscore[i][1] + fscore[i][2])/3);
    }

    
    return 0;
}