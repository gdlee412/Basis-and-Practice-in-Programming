#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void main()
{
    int arr[N], i = 0;
    //set the seed value (number to start with)
    //the seed is set to the current time in seconds
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 2;
    }

    for (int i = 0; i < N; i++)
    {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}