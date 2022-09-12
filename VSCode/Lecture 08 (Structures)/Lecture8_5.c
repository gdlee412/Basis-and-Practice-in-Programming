#include <stdio.h>

struct date
{
    int month, day, year;
};

struct time
{
    int hour, min, sec;
};

typedef struct 
{
    struct date sdate;
    struct time stime;
}dateandtime;

int main()
{
    dateandtime exam;
    exam.sdate.year = 2020;
    exam.sdate.month = 12;
    exam.sdate.day = 20;
    
    exam.stime.hour = 10;
    exam.stime.min = 10;
    exam.stime.sec = 0;

    printf("%i %i %i %i %i %i", exam.sdate.year, exam.sdate.month, exam.sdate.day, exam.stime.hour, exam.stime.min, exam.stime.sec);
}