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
days(int iyear1, int iyear2)
{
    int i, j;
    int leap;
    int days = 0;

    for (i = iyear1; i < iyear2; i++)
    {
        leap = isleap(i);

        for (j = 0; j < 12; j++)
        {
            days += days_of_month[leap][j];
        }
    }

    return days;    
}

void
physical(int days)
{
    int iresult;

    iresult = days % 23;

    if (iresult >= 0 && iresult <= 11)
    {
        printf("physical high\n");
    }
    else
    {
        printf("physical low\n");
    }
}

void
emotion(int days)
{
    int iresult;
    
    iresult = days % 28;
    
    if (iresult >= 0 && iresult <= 14)
    {
        printf("physical high\n");
    }
    else
    {
        printf("physical low\n");
    }
}

void
intellect(int days)
{
    int iresult;
    
    iresult = days % 33;
    
    if (iresult >= 0 && iresult <= 16)
    {
        printf("physical high\n");
    }
    else
    {
        printf("physical low\n");
    }

}

int
main(void)
{
    int iyear1, imonth1, idate1;
    int iyear2, imonth2, idate2;
    int iday1, iday2;
    int iday;
    
    printf("Please enter year1, month1, date1: ");
    scanf("%d%d%d", &iyear1, &imonth1, &idate1);

    printf("Please enter year2, month2, date2: ");
    scanf("%d%d%d", &iyear2, &imonth2, &idate2);
    
    iday1 = dayofyear(iyear1, imonth1, idate1);
    iday2 = dayofyear(iyear2, imonth2, idate2);

    iday  = days(iyear1, iyear2);

    iday = iday + iday2 - iday1;

    printf("all days are %d\n", iday + iday2 - iday1);

    physical(iday);

    emotion(iday);

    intellect(iday);
    
    return 0;
}
