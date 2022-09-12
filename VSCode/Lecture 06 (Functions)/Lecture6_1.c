#include <stdio.h>
#include <math.h>   //used for pow(x,y )

int sum(int);

int main()
{
    int limit = 0, out = 0;
    
    printf("Enter an integer: ");
    scanf("%d", &limit);

    out = sum(pow(limit, 2));   //recall function; pow(x,y) calculates x ^ y
    printf("The sum from 1 to %d^2 = %d\n", limit, out);
}

int sum(int limit)  //definition of sum() function
{
    int i = 0, result = 0;

    for(i = 1; i <= limit; i ++)
    {
        result += i;
    }
    return result;
}