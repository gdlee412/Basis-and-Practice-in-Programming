#include <stdio.h>

struct date
{
    int month, day, year;
};

int main()
{
    int i;
    struct date today = {01,01,2000};
    struct date tomorrow = {.month = 01, .day = 02, .year = 2000};
    struct date arrayofDays[2] = {{01,01,2000}, {01,02,2000}};
    arrayofDays[0] = today;
    printf("%i %i %i\n", today.month, today.day, today.year);
    printf("%i %i %i\n", tomorrow.month, tomorrow.day, tomorrow.year);
    for(i = 0; i < 2; i++)
    {
        printf("%i %i %i\n", arrayofDays[i].month, arrayofDays[i].day, arrayofDays[i].year);
    }
}