#include <stdio.h>

int main()
{
    int* ip = NULL;

    if(ip != NULL)
    {
        printf("Value ip != NULL %d\n", *ip); //*ip does not work for NULL values
    }
    else if(ip == NULL)
    {
        printf("Value ip = NULL %p\n", ip);
    }

    return 0;
}