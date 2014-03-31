#include <stdio.h>

#define  NUM 3

struct tag_student
{
    char szname[32];
    char szid[32];
    float fscore_a; //score of course a
    float fscore_b;
    float fscore_c;
};

void
getinput(struct tag_student *student)
{
    int i;

    printf("Please enter name, id, score A, score B, score C of %d students:\r\n", NUM);

    for (i = 0; i < NUM; i++)
    {
        printf("%d:\r\n", i+1);
        scanf("%31s", student[i].szname);
        fflush(stdin);

        scanf("%31s", student[i].szid);
        fflush(stdin);

        scanf("%f%f%f", &student[i].fscore_a, &student[i].fscore_b, &student[i].fscore_c);
        fflush(stdin);        
    }
}

void
calculate(struct tag_student *student, 
          float *average,
          float *max,
          int *index
          )
{
    float fmax = 0.0f;
    float ftotal = 0.0f;
    float ftmp;
    int i;


    for (i = 0; i < NUM; i++)
    {
        ftmp = student[i].fscore_a + student[i].fscore_b + student[i].fscore_c;

        if (fmax < ftmp)
        {
            fmax = ftmp;

            *index = i;
        }

        ftotal += ftmp;
    }

    *average = ftotal * 1.0f / (3 * NUM);
    *max = fmax * 1.0f / 3;
}


/*
从键盘输入10个学生的数据，包括:学号、姓名、三门
课的成绩。要求输出三门课总平均 成绩，及最高分学
     生的数据（学号、姓名、三门课成绩、平均分数）
*/
int
main(void)
{
    struct tag_student student[NUM];
    float faverage = 0.0f;   //average of all students's all course score
    float fmax = 0.0f;   //max average 
    int index;              //index of the highest score student.

    getinput(student);

    calculate(student, &faverage, &fmax, &index);

    printf("average = %f, max score is %d's : %f", faverage, index, fmax);

    return 0;
}