#include <stdio.h>

#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define ABS(a)      ((a) > 0 ? (a) : (-(a)))

#define LEAP_YEAR(year) (\
                            (\
                                ((year) % 4 == 0 && (year) % 100 != 0) \
                                || ((year) % 400 == 0) \
                            )\
                            ? 1 : 0 \
                        )

#define Isupper(a)      (((a) >= 'A' && (a) <= 'Z') ? 1: 0)

void
test_LEAPYEAR(void)
{
    int iresult;

    iresult = LEAP_YEAR(2000 + 3);
}

void
test_Isupper(void)
{
    int iresult;

    iresult = Isupper('a' + 1)
}

void
test_MAX(void)
{
    int iresult;

    iresult = MAX(1, 100);

}

void
test_MIN(void)
{

}

void
test_ABS(void)
{
    int iresult;

    iresult = ABS(-(9 - 5));

}

int
main(void)
{
    test_MAX();

    test_MIN();

    test_ABS();

    test_LEAPYEAR();

    test_Isupper();

    return 0;
}