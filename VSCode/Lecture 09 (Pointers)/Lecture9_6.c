#include <stdio.h>

void setvalues(int *a, int *b) //direct addresses to a pointer a and b
{
    *a  = *a + 15 - *b;
    *b = 30 * 5 / 2;
}                       

int main()
{
    int x = 10;
    int y = 30;
    setvalues(&x, &y);  //send the address of variables
    printf("x = %d y = %d\n", x, y);
    return 0;
}

