#include <stdio.h>
#include <string.h>

#define MAX_INPUT   16

#define FAILED  -1
#define SUCCESS 0

void
getinput(char *szinput)
{
    printf("Please enter the keyword u want to search:\r\n");
    scanf("%15s", szinput);
    fflush(stdin);
}

int
locate(char const **name,       
       char const *szkeyword, 
       int *aryindex, int *num)
{
    char const **ptr;
    int index;
    int result = FAILED;    //no match
    int i = 0;              //num of matched
    

    for (ptr = name; *ptr != NULL; ptr++)
    {
        if (NULL != strstr(*ptr, szkeyword))
        {
            index = ptr - name;
            *(aryindex + i) = index;

            i++;
        }
    }

    *num = i;

    if (i != 0)
    {
        result = SUCCESS;
    }

    return result;
}

/*
1)给定若干字符串
2)用户输入欲查询字符串
3)给出所有符合的结果

  字符串的定长存储与变长存储
  模糊查询

  已知学生库char *name[6] = {"Join", "Mary","Lily","Bob","Williams","White"};
  要求根据输入学生姓名查找该学生是第几个。
*/
int
main(void)
{
    //这里各字符长度相差不大，也可考虑用定长存储
    char *name[] = {"Join", "Mary", "Lily", "Bob", "Williams", "White", NULL};
    char szkeyword[MAX_INPUT];    
    int aryindex[6];       //存储查询匹配结果在name中的下标
    int  num;           //查询匹配结果的数目
    int  result;        //是否查询到
    int i;

    getinput(szkeyword);

    result = locate(name, szkeyword, aryindex, &num);

    if (FAILED == result)
    {
        printf("No match\r\n");
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            printf("%d : %s\r\n", aryindex[i], name[aryindex[i]]);
        }
    }

    return 0;
}