#include <stdio.h>

int main(void)
{
    float a,b;
    int i = 2147483647; //the largest posible value for integers
    printf("%i %i %i\n",i,i+1,i+2); //adding from the maximum will give wrong answers
    b = 2.0e20 + 1.0; //float cannot store 21 digits, hence the final answer is wrong
    a = b - 2.0e20;
    printf("%f %f\n", a, b);
    return 0;
}