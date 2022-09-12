#include <stdio.h>
#include <math.h>
#define N 10

double POLY(double, int);   //add sum of the increasing exponents of a number x^1 + x^2 + ... x^9 + x^10

void main()
{
    double r = 0., out = 0.;

    printf("Enter a double number: ");
    scanf("%lf", &r);

    out = POLY(r, N);
    printf("The result = %.3lf\n", out);
}

double POLY(double r, int n)
{
    int i = 0;
    double result = 0;

    for(i = 1; i <= n; i++)
    {
        result += pow(r, i);
    }
    return result;
}