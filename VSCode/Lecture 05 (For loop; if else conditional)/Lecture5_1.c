#include <stdio.h>

#define N 7

void main(void)
{
    int ii = 0, jj = 0;
    int result[N];

    for(ii = N - 1, jj = 0; jj < N; ii--, jj++)
    {
        result[jj] = ii + jj;
    }

    for(ii = 0; ii < N; ii++)
        printf("result[%d] = %d\n", ii, result[ii]);
}