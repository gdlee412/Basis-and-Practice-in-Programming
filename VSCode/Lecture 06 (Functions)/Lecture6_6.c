#include <stdio.h>
#define N 3

void npower(int in, int* out, int n);   //* means pointer

void main()
{
    int num = 5, out = 0;
    npower(num, &out, N);   //function call; & is used to call address of function

    printf("%d^%d = %d\n", num, N, out);
}

void npower(int in, int* out, int n)    //* means pointer
{
    int i;
    *(out) = 1;
    for(i = 0; i < n; i ++)
    {
        *(out) = *(out) * in;
    }
}