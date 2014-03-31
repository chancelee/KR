#include <stdio.h>

#define LEAP_YEAR(year) (                                                   \
                            (                                               \
                                (((year) % 4 == 0) && ((year) % 100 != 0))  \
                                || ((year) % 400 == 0)                      \
                            )                                               \
                            ? 1 : 0                                         \
                        )

int days_of_month[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //non-leap
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
                        
                            

struct tag_date
{
    int nyear;
    int nmonth;
    int nday;
};

void
output(int days)
{
    printf("It's the %d th day of the year\r\n", days);
}

void
getinput(struct tag_date *mydate)
{
    printf("Please enter the year, month and day u want to calculate:\r\n");
    scanf("%4d%2d%2d", &mydate->nyear, &mydate->nmonth, &mydate->nday);
    fflush(stdin);
}

int 
daysofyear(struct tag_date mydate)
{
    int leap;
    int days;
    int i;

    leap = LEAP_YEAR(mydate.nyear);
    days = 0;

    for (i = 0; i < mydate.nmonth - 1; i++)
    {
        days += days_of_month[leap][i];
    }

    days += mydate.nday;

    return days;
}

/*
����һ�������ꡢ�¡��յĽṹ��������������ꡢ
     �¡������ݺ󣬼����������һ���еĵڼ��졣
*/
int
main(void)
{
    struct tag_date mydate;
    int ndays;

    getinput(&mydate);

    ndays = daysofyear(mydate);

    output(ndays);

    return 0;
}