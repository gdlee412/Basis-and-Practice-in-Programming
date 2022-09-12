#include <stdio.h>

int main()
{
    int a = 5, b;
    int * a_ptr;    //pointer declaration
    a_ptr = &a; //direct a's address inside a_ptr
    *a_ptr = 20; //dereferencing / changing the value of a through pointer
    b = *a_ptr; //direct the value inside the pointer to b

    printf("%p %p\n", &a, a_ptr);   //address of a is equal to address inside a_ptr
    printf("%d %d %d\n", a, *a_ptr, b); //values of a, b, and value inside pointer are equivalent
    printf("%d\n", sizeof(a_ptr));  //size of pointer
    
    return 0;
}