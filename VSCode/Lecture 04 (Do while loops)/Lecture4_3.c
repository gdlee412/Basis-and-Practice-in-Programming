#include <stdio.h>

void main(void)
{
    int sum = 4, num;
    int status = 1;

    printf("Enter a non-negative number: ");
    status = scanf("%d", &num);
    sum += num;    //sum = sum + num

    printf("sum = %d", sum);
}