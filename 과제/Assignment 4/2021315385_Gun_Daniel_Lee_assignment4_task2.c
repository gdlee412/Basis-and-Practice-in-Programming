/*Function: main
*------------------------------------
*Solve for time difference in seconds between start and end time
*
*requests for start and end time inputs
*start: starting time variable
*end: ending time variable
*
*function call on t_diff
*print out the final output
*/

/*Function: t_diff
-------------------------------------
*calculate the difference between two given time inputs
*
*converts both time into seconds
*uses if statement to subtract the smaller time variable from the larger time variable
* diff = larger time variable - smaller time variable
* diff value will be changed using a pointer and dereferencing
*/

//declare header file
#include <stdio.h>

//declare and define the time structure
typedef struct
{
    //declare needed variables in struct
    int hours, minutes, seconds;
}time;

//declare function for time difference
void t_diff(time start, time end, int *diff);


//main function
int main()
{
    //declare variables
    time start, end;
    int diff;

    //request for the starting time information
    //use scanf to retrieve data
    printf("Enter starting time: \n");
    printf("hours: ");
    scanf("%d", &start.hours);
    printf("minutes: ");
    scanf("%d", &start.minutes);
    printf("seconds: ");
    scanf("%d", &start.seconds);
    printf("\n");

    //request for the ending time information
    //use scanf to retrieve data
    printf("Enter ending time: \n");
    printf("hours: ");
    scanf("%d", &end.hours);
    printf("minutes: ");
    scanf("%d", &end.minutes);
    printf("seconds: ");
    scanf("%d", &end.seconds);

    //function call of t_diff to calculate difference
    //save sending diff's address to change diff's value in function
    t_diff(start, end, &diff);

    //print the output
    printf("Time difference: %d:%d:%d - %d:%d:%d = %d seconds", start.hours, start.minutes, start.seconds, end.hours, end.minutes, end.seconds, diff);
    return 0;
}

//t_diff function
void t_diff(time start, time end, int *diff)
{
    //declare variables
    int starttime, endtime;

    //calculate the start and end time into seconds and save in the variables
    starttime = 3600 * start.hours + 60 * start.minutes + start.seconds;
    endtime = 3600 * end.hours + 60 * end.minutes + end.seconds;

    //if statement to check whether start time or end time is bigger (just in case)
    //if starttime is larger than endtime
    if(starttime > endtime)
    {
        //find difference and save to diff using dereferencing
        *diff = starttime - endtime;
    }
    //if endtime is larger than starttime
    else if(endtime >= starttime)
    {
        //find difference and save to diff using dereferencing
        *diff = endtime - starttime;
    }
}