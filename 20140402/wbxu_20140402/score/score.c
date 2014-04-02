/*
����һ������stu���Է�ѧ����������ѧ�š�Ӣ��ɼ�
����Ӣ��ɼ��е���ʦ���ա��š��������������С���������
������������ȼ����ģ��е���ʦ���հٷ��Ƹ��ĳ�
      ����Ҫ������Ϳ�����ʵ��ӳѧ���������
*/

#include <stdio.h>
#include <string.h>

char szlevel[][10] = {
    "EXCELLENT",
    "GOOD",
    "WELL",
    "PASS"
};

enum enu_level
{
    EXCELLENT,
    GOOD,
    WELL,
    PASS
};

struct tag_score
{
    enum
    {
        LEVEL,
        GRADE
    }scoretype;

    union
    {
        int level;
        float grade;
    }score;
};

struct tag_stu
{
    char szname[32];
    char szid[32];
    struct tag_score engscore;
};

void
setscore(struct tag_stu *student)
{
    printf("Please enter the score type:\r\n"
           "%d. LEVEL\r\n"
           "%d. GRADE\r\n", 
           LEVEL, GRADE);
    scanf("%d", &(student->engscore.scoretype));

    if (LEVEL == student->engscore.scoretype)
    {
        printf("Please enter the level u want to set:\r\n"
               "%d. %s\r\n"
               "%d. %s\r\n"
               "%d. %s\r\n"
               "%d. %s\r\n",
               EXCELLENT, szlevel[EXCELLENT],
               GOOD, szlevel[GOOD],
               WELL, szlevel[WELL],
               PASS, szlevel[PASS]);

        scanf("%d", &(student->engscore.score.level));  //score level
    }
    else if(GRADE ==  student->engscore.scoretype)
    {
        printf("Please enter the detailed score, like 63.5\r\n");
        scanf("%f", &(student->engscore.score.grade));  //score grade
    }
    else
    {
        printf("Please make the right decision ^_^\r\n");
    }
}

void
showinfo(struct tag_stu *student)
{
    printf("name: %s\r\nid: %s\r\n", student->szname, student->szid);

    if (LEVEL == student->engscore.scoretype)
    {
        printf("score: %s\r\n", szlevel[student->engscore.score.level]);    //score level
    }
    else if(GRADE ==  student->engscore.scoretype)
    {
        printf("score: %f\r\n", student->engscore.score.grade); //score grade
    }
    printf("\r\n");
}

int
main(void)
{
    struct tag_stu student1;
    float f = 0.0f;
    int i;

    for (i = 0; i < 2; i++)
    {
        strcpy(student1.szname, "student1");
        strcpy(student1.szid, "No.1");
        setscore(&student1);
        showinfo(&student1);
    }
   
    return 0;
}