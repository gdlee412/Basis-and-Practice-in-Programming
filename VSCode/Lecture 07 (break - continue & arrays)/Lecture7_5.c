#include <stdio.h>
#define SIZE 6

void main()
{
    int i = 0, a[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("address of a[%d] = %p\n", i, &a[i]);
        printf("address of a[%d] = %p\n", i, a + i);
    }
}