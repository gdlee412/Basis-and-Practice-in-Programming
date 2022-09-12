#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void init(int a[], int n);
void randarray(int a[], int n);
void printarray(int vec1[], int vec2[], int len);
void power(int in[], int out[], int size);

void main()
{
    int seq1[N], seq2[N];

    init(seq1, N);
    init(seq2, N);

    printarray(seq1, seq2, N);

    randarray(seq1, N);
    power(seq1, seq2, N);

    printarray(seq1, seq2, N);
}

void init(int a[], int n)   //set all the elements in array to 0
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}

void randarray(int a[], int n)  //generate random elements for arrays from 0 - 20
{
    int i = 0;

    srand(time(0));
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 21;
    }
}

void printarray(int vec1[], int vec2[], int len)    //print the elements of each array
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d\t%d\n", vec1[i], vec2[i]);
    }
    
    printf("\n");
}

void power(int in[], int out[], int n)  //squares the elements of first array to the second array
{
    int i = 0;

    for(i = 0; i < n; i++)
    {
        out[i] = in[i] * in[i];
    }
}