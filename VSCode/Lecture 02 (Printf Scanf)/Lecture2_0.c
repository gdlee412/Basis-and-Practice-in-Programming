#include <stdio.h>
#include <stdlib.h>

int main()
{
    float age;
    float weight;

    printf("Please enter your age \n");
    scanf("%f", &age); //%f is used to specify float numbers
    printf("Please enter your weight \n");
    scanf("%f", &weight);

    printf("Thank you! \nYour age is %.3f, and you weigh %.3f kilograms.",age,weight); //.n in %.nf is the number of digits after the decimal point
    return 0;
}