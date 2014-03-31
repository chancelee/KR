#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "sort.h"

#define MAX 3

struct tag_user
{
    char szname[32];
    char szphone[32];
};


/*
Function: compare two struct's keywords

Return  : 1 for *x > *y, 0 for equal, -1 for *x < *y
*/
int
compare_struct(void const *x, void const *y)
{
    int result;

    result = strcmp(((struct tag_user *)x)->szname,
                     ((struct tag_user *)y)->szname);
   
    return result;

}

void
output(struct tag_user *user)
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("%d: %s  %s\r\n", i, user[i].szname, user[i].szphone);
    }
}

void
getinput(struct tag_user *user)
{
    int i;

    printf("Please enter user's name and phone number:\r\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d:\r\n", i);

        scanf("%31s", user[i].szname);
        fflush(stdin);

        scanf("%31s", user[i].szphone);
        fflush(stdin);
    }
}

/*
    Test for callback with selectsort, can deal with int, strings

    1)给定若干字符串
    2)对它们进行排序
    
      自测点：
      指针数组
      交换字符串or 交换指针
      如果换成其他类型呢？能否进行通用性的处理？

  从键盘输入5个用户的数据，包括：姓名和电话号码
  要求按姓名排序后，输出用户的全部数据。
*/
int
main(void)
{
    struct tag_user user[MAX];
    
    getinput(user);

    selectsort((void *)user, sizeof(user) / sizeof(user[0]), sizeof(user[0]), compare_struct);

    output(user);


    return 0;
}