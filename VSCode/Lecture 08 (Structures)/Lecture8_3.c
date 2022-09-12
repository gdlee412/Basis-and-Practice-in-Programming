#include <stdio.h>

struct time
{
    int hour, min, sec;
};

struct time timeUpdate(struct time now);

int main()
{
    struct time currentTime, nextTime;
    printf("Enter the time (hh:mm:ss): ");
    scanf("%i:%i:%i", &currentTime.hour, &currentTime.min, &currentTime.sec);

    nextTime = timeUpdate(currentTime);
    printf("Updated time is %.2i:%.2i:%.2i\n", nextTime.hour, nextTime.min, nextTime.sec);
    return 0;
}

struct time timeUpdate(struct time now)
{
    now.sec++;
    if(now.sec == 60)
    {
        now.sec = 0;
        now.min++;
        if(now.min == 60)
        {
            now.min = 0;
            now.hour++;
            if(now.hour == 24)
            {
                now.hour = 0;
            }
        }
    }
    return now;
}