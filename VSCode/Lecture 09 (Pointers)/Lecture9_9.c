#include <stdio.h>
#include <stdbool.h>

bool compare(int *arr1, int size1, int *arr2, int size2)
{
    if(size1 != size2)
    {
        return false;
    }
    for(int i = 0; i < size1; i++)
    {
        if(arr1 + i == arr2 + i)//same array
        {
            return true;
        }
        else if(*(arr1 + i) != *(arr2 + i)) //not same array values
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size1 = 3, size2 = 3;
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 5, 3};
    printf("%d\n", compare(arr1, size1, arr1, size2));  //1 since true
    printf("%d\n", compare(arr1, size1, arr2, size2));  //1 since true
    printf("%d\n", compare(arr1, size1, arr3, size2));  //print out 0 since false
}