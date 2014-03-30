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
1)���������ַ���
2)�û���������ѯ�ַ���
3)�������з��ϵĽ��

  �ַ����Ķ����洢��䳤�洢
  ģ����ѯ

  ��֪ѧ����char *name[6] = {"Join", "Mary","Lily","Bob","Williams","White"};
  Ҫ���������ѧ���������Ҹ�ѧ���ǵڼ�����
*/
int
main(void)
{
    //������ַ���������Ҳ�ɿ����ö����洢
    char *name[] = {"Join", "Mary", "Lily", "Bob", "Williams", "White", NULL};
    char szkeyword[MAX_INPUT];    
    int aryindex[6];       //�洢��ѯƥ������name�е��±�
    int  num;           //��ѯƥ��������Ŀ
    int  result;        //�Ƿ��ѯ��
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