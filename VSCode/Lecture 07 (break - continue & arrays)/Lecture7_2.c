#include <stdio.h>

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    printf("Size of entire array: %d\n", sizeof(arr));
    printf("Size of one element of array: %d\n", sizeof(arr[0]));
    printf("Address of array: %d\n", arr);
    printf("Address of first element using P: %d\n", &arr[0]);
    printf("Address of second element using P: %d\n", &arr[1]);
    printf("Value of first element in the array: %d\n", arr[0]);
    printf("Address of array using P: %p\n", arr);
    printf("Address of first element using P: %p\n", &arr[0]);
    printf("Address of second element using P: %p\n", &arr[1]);

}