#include <stdio.h>

void main()
{
    int num;

    printf("Please enter an integer: ");
    scanf("%d", &num);

    if(num > 0)
    {
        if(num % 2 == 0)
        {
            printf("The number is positive and even.\n");
        }
        else
        {
            printf("The number is positive and odd.\n");
        }
    }
    else
    {
        printf("The number is negative.\n");
    }
}