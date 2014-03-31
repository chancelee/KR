#include <stdio.h>
#include <stddef.h>

#define NUM  3

struct tag_student
{
    int id;
    int age;
    char name[10];
};

void
walk_by_struct(struct tag_student *student)
{
    int i;

    printf("\r\nWalking in by struct:\r\n");

    for (i = 0; i < NUM; i++)
    {
        printf("%d %d %s\r\n", student[i].id, student[i].age, student[i].name);
    }
}

void
walk_by_ptr(struct tag_student *student)
{
    int i;
    
    printf("\r\nWalking in by prt:\r\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%d ",  *(int *)((int)(student + i) + offsetof(struct tag_student, id)));
        printf("%d ",  *(int *)((int)(student + i) + offsetof(struct tag_student, age)));
        printf("%s\r\n",  (char *)((int)(student + i) + offsetof(struct tag_student, name)));
    }
}

/*
分别用指针和结构体本身，来遍历输出结构体数组
*/
int
main(void)
{
    struct tag_student student[NUM] = {
        {1, 2, "test1"},
        {2, 3, "test2"},
        {3, 4, "test3"}
    };

    walk_by_struct(student);

    walk_by_ptr(student);

    return 0;
}