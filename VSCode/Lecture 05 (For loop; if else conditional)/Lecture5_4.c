#include <stdio.h>

#define low 5
#define high 28

void main()
{
    int temp = 0, state;

    printf("Please enter the temperature: ");
    state = scanf("%d", &temp);

    if(temp <= low && state == 2)
    {
        printf("I'm freezing! Turn the heater on. \n");
    }
    else if(temp >= high && state == 1)
    {
        printf("It's too hot! Turn the air conditioner on. \n");
    }
    else if(temp < high && temp > low && state == 1)
    {
        printf("The weather is amazing! Let's go party :)\n");
    } 
    else
    {
        printf("Input error! Program is terminated.\n");
    }
}