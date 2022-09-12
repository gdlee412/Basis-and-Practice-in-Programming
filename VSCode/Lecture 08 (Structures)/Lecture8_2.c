#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

int numberofdays(struct date today);    //gets number of days in that month
bool isLeapYear(struct date today); //checks if year is a leap year
struct date GetTomorrow(struct date today); //function to get the variable for a structure

int main()
{
    struct date today, tomorrow;
    int days;
    const int dayspermonth[12] = {31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31};

    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &today.month, &today.day, &today.year);

    tomorrow = GetTomorrow(today);
    days = numberofdays(today);
    printf("There are %i days in this month.\n", days);
    printf("Tomorrow's date is %i/%i/%i.\n", tomorrow.month, tomorrow.day, tomorrow.year);
}

int numberofdays(struct date today)
{
    const int dayspermonth[12] = {31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31};
    int days;

    if(today.month == 2 & isLeapYear(today))
    {
        days = 29;
    }
    else
    {
        days = dayspermonth[today.month - 1];
    }
    
    return days;
}

bool isLeapYear(struct date today)
{
    bool leapyearflag;

    if(today.year % 4 == 0 && today.year % 100 != 0 || today.year % 400 == 0)
    {
        leapyearflag = true;
    }
    else
    {
        leapyearflag = false;
    }

    return leapyearflag;
}

struct date GetTomorrow(struct date today)
{
    struct date tomorrow;
     
    if(today.day != numberofdays(today))
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if(today.month == 12)
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else
    {
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    return tomorrow;
}