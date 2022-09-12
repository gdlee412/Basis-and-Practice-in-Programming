#include <stdio.h>

void main(void)
{
    int sum = 0, ii = 0, num;
    int status = 1;

    printf("Enter a non-negative number: ");
    status = scanf("%d", &num); //using characters will let status = 0

    while(num >= 0 && status == 1) // two cond. 1)num must be a positive integers
    {                                // 2) status equals 1
        sum = sum + num;
        printf("Enter a non-negative number: ");
        status = scanf("%d", &num);
        ii++;  // ii = ii + 1       increase ii by one
    }

    printf("\nYou entered %d non-negative numbers,\n", ii);
    printf("their sum is %d.\n", sum);
}