/*
we want to walk all the heap of this process. 
Enjoy yourself.

paddr = (type *) malloc (NUM);
paddr �ǿ��Ի�ȡ���ġ�

1)���ѿ�ʼ�ĵ�ַ����paddr - 0x20�ĵط���
2)paddr - 0x20 ��ʼ��4�ֽ�Ϊ��һ���ѵ���ʼ��ַ�� 
  Ϊ0ʱ��˵��ǰ����û�У� �ö�Ϊ��һ����
3)paddr - 0x20 + 4��ʼ��4�ֽ�Ϊ��һ���Ե���ʼ��ַ��
  ��Ϊ0ʱ��˵��������û�У��ö�Ϊ���һ���ѡ�
4)paddr - 0x10 ��ʼ��4�ֽ�Ϊ����ĳ���   ����һ�У�
5)paddr - 0x10 + 8 (paddr - 0x08) ��Ϊ�ý���Ŀǰ������ѵ��ܴ���  
  ע���������Ŀǰ�Ѵ�ѵ���Ŀ�������ѷ������ͷ�
6)paddr - 4 ~ paddr Ϊ������߽�
7)paddr ~ paddr + NUM Ϊ�û������뵽�Ŀɲ����Ķѿռ�, ���0XCD��
8)paddr + NUM ~ paddr + NUM + 4 Ϊ������߽�
9)�ÿռ��ڻ���һЩδ֪�ֶΣ�����paddr - 0x10 + 4��4�ֽڣ� �Լ�������߽���һЩ���ݣ� ���庬��δ֪��
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define OFFSET  0x20

struct tag_heap
{
    struct tag_heap *ppreheap;   //+0x00    
    struct tag_heap *pnextheap;  //+0x04
    int iunknown_1;              //+0x08
    int iunknown_2;              //+0x0c
    unsigned nsize;              //+0x10
    int iunknown_3;              //+0x14
    unsigned ncount;             //+0x18
    char upoverflow[4];          //+0x1c
    char chcontent[1];           //+0x20     
};

void
heapwalk(struct tag_heap *pcurrentheap)
{
    struct tag_heap *pheap      = NULL;
    struct tag_heap *ppreheap   = NULL;     
    //struct tag_heap *pnextheap  = NULL;  //not used
    unsigned nsize              = 0;               
    unsigned ncount             = 0;             
    char chcontent[1]           = {'\0'};    
    unsigned i                  = 0;
    unsigned j                  = 0;

    //find the 1st heap, need the help of ppreheap
    for (pheap = pcurrentheap, ppreheap = pcurrentheap; 
         ppreheap != NULL; 
         ppreheap = pheap->ppreheap)
    {
        //printf("%p\r\n", pheap);
        pheap = pheap->ppreheap;        
    }
    //now pheap already point to the 1st heap
    //printf("lst:%p\r\n", pheap);

    for ( ; 
         pheap != NULL;
         pheap = pheap->pnextheap)
    {
        //now we can decode the heap structure.
        printf("Info of %d heap---------\r\n", i++);
        printf("heap base  : %p\r\n", pheap);
        printf("pre heap   : %p\r\n", pheap->ppreheap);
        printf("next heap  : %p\r\n", pheap->pnextheap);
        printf("malloc size: %p\r\n", pheap->nsize);
        printf("malloc count: %p\r\n", pheap->ncount);
#if 0
        for (j = 0; j < pheap->nsize; j++)
        {
            printf("%c", pheap->chcontent[j]);
        }
#endif
        printf("\r\n");
        //system("pause");
    }   
}


int
main(void)
{
    struct tag_heap *pcurrentheap = NULL;
    char sztext[]                 = "Walking heap\r\n";
    size_t len                    = 0;
    char *psz                     = NULL;

    len = strlen(sztext);

    psz = (char *)malloc(len + 1);
    if (NULL == psz)
    {
        goto ERROR_PROCESS;
    }
    else
    {
        strcpy(psz, sztext);
    }

    heapwalk((struct tag_heap *)((int)psz - OFFSET));

ERROR_PROCESS:
    if (psz)
    {
        free(psz);
        psz = NULL;
    }

    return 0;
}