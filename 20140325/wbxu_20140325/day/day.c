#include <stdio.h>

#define LEAP_YEAR(year) (\
                            (\
                                ((year) % 4 == 0 && (year) % 100 != 0) \
                                || ((year) % 400 == 0) \
                             )\
                            ? 1 : 0 \
                        )

int days_of_month[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //non-leap
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void
getinput(int *piyear, int *pimonth, int *pidate)
{
    printf("Please enter year, month and date(yyyy mm  dd):\r\n");
    scanf("%4d%2d%2d", piyear, pimonth, pidate);
}

int 
dayofyear(int iyear, int imonth, int idate)
{
    int leap;
    int idays;
    int i;

    leap = LEAP_YEAR(iyear);

    for (i = 0, idays = 0; i < imonth - 1; i++)
    {
        idays += *(*(days_of_month + leap) +i);
    }

    idays += idate;

    return idays;
}

void
output(int idays)
{
    printf("it is the %dth day of the year\r\n", idays);
}

int
main(void)
{
    int iyear, imonth, idate;
    int idays;

    getinput(&iyear, &imonth, &idate);

    idays = dayofyear(iyear, imonth, idate);

    output(idays);

    return 0;
}