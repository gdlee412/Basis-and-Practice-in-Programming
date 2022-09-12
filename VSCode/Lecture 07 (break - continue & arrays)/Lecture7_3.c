#include <stdio.h>
#define N 5

void main()
{
    int arr_i[N], i = 0;    //int array of size N
    double arr_d[N];        //double array of size N

    for(i = 0; i < N; i++)
    {
        arr_i[i] = N - i;
        // print int array
        printf("arr_i[%d] = %d and saved at location %p\n", i, arr_i[i], &arr_i[i]);
    }

    for(i = 0; i < N; i++)
    {
        arr_d[i] = (double) (N - i) / N;
        //print double array
        printf("arr_d[%d] = %.1lf and saved at location %p\n", i, arr_d[i], &arr_d[i]);
    }
}