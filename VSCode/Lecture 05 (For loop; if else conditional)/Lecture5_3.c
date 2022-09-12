#include <stdio.h>

void main()
{
    int num = 0, state;

    printf("Please enter an integer: ");
    state = scanf("%d", &num);

    if(num < 0 && state == 1)
    {
        num = -1 * num;
    }
    printf("The absolute value of num is %d\n", num);
}