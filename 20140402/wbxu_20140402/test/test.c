#include <stdio.h>

enum enu_test
{
    ONE, TWO, THREE, THOUR  //just 4 test;
};

struct tag_var
{
    enum
    {
        INT, FLOAT, STRING  //var type
    }type;  //now type is a variable

    union 
    {
        int i;
        float f;
        char ch;
    }value; //now value is a variable
};

int
main(void)
{
    float f = 0.0; //

    struct tag_var var;

    var.type = INT;     //
    var.value.i = 3;

    printf("%d\r\n", sizeof(enum enu_test));
 

    return 0;
}