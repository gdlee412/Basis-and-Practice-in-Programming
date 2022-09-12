#include <stdio.h>

void funcwithpointer(int array[], int size)
{
    int *i;
    for(i = array; i < &array[size]; i++)
    {
        printf("%d\n", *i);
    }
}

void func(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int arr1[5] = {1,2,3,4,5};
    func(arr1, 5);
    funcwithpointer(arr1, 5);
    return 0;
}