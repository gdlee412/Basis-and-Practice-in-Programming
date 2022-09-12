//Loops
//printing the multiplication table of 3

#include <stdio.h>
#define X 3
#define LIMIT 7

void main(void)
{
    int count = 1;

    while(count <= LIMIT)   //loop condition
    {
        printf("%d * X = %d,\n", count, count * X);
        count = count + 1; // add 1 to count
    }
}