#include <stdio.h>

int
main(void)
{
    float fFahr;
    float fCels;

    //had better init 
    fFahr = 0.0f;
    fCels = 0.0f;

    printf("Please input the Fahrenheit temperature: ");
    scanf("%f", &fFahr);
    
    //What if we #define BASE (1/1.8f) ???
    fCels = (fFahr - 32)/1.8f;

    printf("The Celsius temperature is: %f\n", fCels);
    

    return 0;
}