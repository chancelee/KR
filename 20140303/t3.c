#include <stdio.h>
#include <math.h>

int
main(void)
{
    int a, b, c;
    
    int delta;
    
    double tmp = 1.0;
    
    printf("Please enter a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    
    if (0 == a) 
    {
        printf("a cannot be 0 !!\n");
        
        return 1;
    }

    delta = b*b - 4*a*c;
    if (delta < 0)
    {
        printf("No answer for this !!\n");
    }
    else
    {
        tmp = sqrt((double)delta);
        
        printf("x1 = %f, x2 = %f\n", ((-b) + tmp) / (2 * a), ((-b) - tmp) / ( 2 * a));      
        
    }           
        
    return 0;
}