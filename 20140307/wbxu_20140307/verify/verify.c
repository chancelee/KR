#include <stdio.h>


int strlen(char *string);
int strlen(char string[]);

/*
copy strings from string to buffer
*/
void
mystrcpy(char *buffer, char const *string)
{
    while ((*buffer++ = *string++))
    {
        ;
    }
}


int
main(void)
{
    int i;
    int j;
    char a;
    char b;
    char c;

    struct s
    {
        int i;
        int j;
        char a;
        char b;
        char c;
    };

    struct s test;

   
    
    return 0;
}