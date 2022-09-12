//do-while loops

#include <stdio.h>

void main(void)
{
    int sum = 0, ii = 0, num;
    int status = 1;

    printf("Enter a non-negative number: ");
    status = scanf("%d", &num);

    do
    {
        sum = sum + num;
        printf("Enter a non-negative number: ");
        status = scanf("%d", &num);
        ii++;
    }   while(num >= 0 && status ==1);

    printf("\nYou entered %d non-negative numbers,\n", ii);
    printf("their sum is %d.\n", sum);
}