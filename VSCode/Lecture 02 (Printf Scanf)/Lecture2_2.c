#include <stdio.h>

int main()
{
    float salary;

    printf("\aEnter your desired monthly salary:");
    printf(" $_______\b\b\b\b\b\b\b"); //\b represents a backspace during the input
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0); // .2 represents 2 final digits after the decimal point
    printf("\rGee!\n");

    return 0;
}