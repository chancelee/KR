#include <stdio.h>

struct tag_record
{
    short shsize;
    char ch[1];
};

void
walk_by_ptr(unsigned char *data, unsigned size)
{
    short len;
    char *pchar = NULL;
    char *start = NULL;
    char *end   = NULL;
    
    for (pchar = data; pchar < data + size; )
    {
        //get the length
        len = *(short *)pchar;
        printf("len: %p ", len);
        
        start = pchar + sizeof(short);
        end   = start + len;
        
        for (pchar = start; pchar < end; pchar++)
        {
            printf("%c", *pchar);
        }
        printf("\r\n");        
    }
}

void
walk_by_ary(unsigned char *data, unsigned size)
{
    struct tag_record *precord = NULL;
    short shsize;
    int i;

    precord = (struct tag_record *)data;

    for ( ; precord < (struct tag_record *)((int)data + size); )
    {
        shsize = precord->shsize;

        printf("len: %p ", shsize);

        for (i = 0; i < shsize; i++)
        {
            printf("%c", precord->ch[i]);
        }
        printf("\r\n");

        precord = (struct tag_record *)((int)precord + sizeof(short) + shsize);
    }
}

/*
Function: show chars in the PASCAL-Style strings
*/
int
main(void)
{
    unsigned char data[64] = {
        0x05, 0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 
            0x0A, 0x00, 0x49, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x43, 0x2B, 0x2B, 
            0x04, 0x00, 0x6A, 0x6A, 0x79, 0x79, 
            0x0D, 0x00, 0x77, 0x77, 0x77, 0x2E, 0x35, 0x31, 0x61, 0x73, 0x6D, 0x2E, 0x63, 0x6F, 0x6D, 
            0x06, 0x00, 0x62, 0x61, 0x63, 0x6B, 0x65, 0x72, 
            0x08, 0x00, 0x43, 0x72, 0x61, 0x63, 0x6B, 0x69, 0x6E, 0x67, 
            0x04, 0x00, 0x61, 0x62, 0x63, 0x78
    };

    printf("Walking in the rain, by the ptr\r\n");
    walk_by_ptr(data, sizeof(data));

    printf("\r\nWalking in the rain, by the ary\r\n");
    walk_by_ary(data, sizeof(data));
    
    return 0;
}

