#include <stdio.h>
#include <math.h>

int
reversedisplay(unsigned input)
{
    unsigned i;

    i = 0;

    while (input / 10)
    {
        printf("%d", input % 10);
        i++;

        input /= 10;
    }

    printf("%d\n", input);
    i++; 
    
    return i;
}

void
display(unsigned input, int len)
{
    unsigned i;

    while (len - 1 > 0)
    {
        i = (unsigned)pow(10, len - 1);
        
        printf("%d", input / i);
        
        input -= (input/i)*i;
        
        len -= 1;
    }
    printf("%d\n", input);
}

int
main(void)
{
    unsigned ilen;
    unsigned input;

    printf("Please enter an unsigned int (no more than 100000): ");
    scanf("%d", &input);

    ilen = reversedisplay(input);

    printf("length %d\n", ilen);

    display(input, ilen);

    return 0;
}