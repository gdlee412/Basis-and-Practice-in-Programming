#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int binary(int a[], int n);

void main()
{
    int count = 0, bin[N];
    count = binary(bin, N);

    printf("Probability of ones is %0.3lf.\n", (double)count / N);
}

int binary(int seq[], int n)
{
    int i = 0, counter = 0;
    srand(time(0)); //seed of random number based on time

    for(i = 0; i < n; i++)
    {
        seq[i] = rand() % 2;
        if(seq[i] == 1)
        {
            counter++;
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d", seq[i]);
    }
    printf("\n");
    
    return counter;
}