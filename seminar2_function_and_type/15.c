#include <stdio.h>

float yearfrac(int year, int day)
{
    int days_in_year;
    if (year % 4 == 0)
    {
        days_in_year = 366;
    }
    else
    {
        days_in_year = 365;
    }
    return (float)day / days_in_year;
}

int main()
{
    int year, day;
    if (scanf("%d %d", &year, &day) == 2)
    {
        printf("%.5f\n", yearfrac(year, day));
    }
    return 0;
}