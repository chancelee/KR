#include <stdio.h>

#define  OFFSET(s, m)   (size_t)&(((s *)(NULL))->m)

#pragma pack(push)
#pragma pack(2)

struct  tag_test
{
    char c1;
    double d;
    char c2;
    int a;
};

#pragma pack(pop)

int
main(void)
{


    printf("%2d\r\n", OFFSET(struct tag_test, c1));
    printf("%2d\r\n", OFFSET(struct tag_test, d));
    printf("%2d\r\n", OFFSET(struct tag_test, c2));
    printf("%2d\r\n", OFFSET(struct tag_test, a));


    return 0;
}