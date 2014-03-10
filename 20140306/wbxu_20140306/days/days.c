#include <stdio.h>

int days_of_month[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int iyear)
{
    int leap = 0;

    if ( ((0 == (iyear % 4)) && (0 != (iyear % 100)))
        || (0 == (iyear % 400))
        )
    {
        leap = 1;
    }
    else
    {
        leap = 0;
    }

    return leap;
}


int
dayofyear(int iyear, int imonth, int idate)
{
    int i;

    int days = 0;

    int leap = 0;

    leap = isleap(iyear);

    for (i = 0; i < imonth - 1; i++)
    {
        days += days_of_month[leap][i];
    }

    days += idate;
    
    return days;
}


int
main(void)
{
    int iyear, imonth, idate;
    int iday;

    printf("Please enter year, month, date: ");
    scanf("%d%d%d", &iyear, &imonth, &idate);

    iday = dayofyear(iyear, imonth, idate);

    printf("it's the %d day of this year\n", iday);    

    return 0;
}
