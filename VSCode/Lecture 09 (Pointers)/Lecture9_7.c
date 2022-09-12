//passing arrays

void func(int array[], int size)    //array is just a pointer
{
    printf("size of the array = %d\n", sizeof(array));  //so the size will only be the general array address/value
    printf("first element = %d\n", array[0]);
    printf("first element = %d\n", *array);   //since array is a pointer, *array = first element
    array = array + 1; //the first element will be the second index / array[1]
    printf("first element after updating = %d\n", *(array));
}

int main()
{
    int arr1[5] = {1,2,3,4,5};
    printf("size of the array = %d\n", sizeof(arr1));
    func(arr1, 5);  

    return 0;
}