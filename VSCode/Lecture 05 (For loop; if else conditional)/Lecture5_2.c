#include <stdio.h>

int main()
{
    int n1 = 9, n2 = 10;
    int min;

    if(n1 <= n2)
    {
        min = n1;
    }
    else
    {
        min = n2;
    }
    printf("The min number is %d", min);
    return 0;
}