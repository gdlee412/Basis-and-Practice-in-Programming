#include <stdio.h>

int main()
{
    int i, j;
    int *i_ptr;
    int *j_ptr;

    i = 1;  //equate i as 1
    j = 2; //equate j as 2

    i_ptr = &i; //save the i address inside i_ptr
    j_ptr = i_ptr;  //save the address of inside i_ptr to j_ptr

    *i_ptr = 3; //change the value of i_ptr to 3 / change i to 3 / since j_ptr is also pointing to i, j_ptr's value becomes 3 as well
    j = *j_ptr; //change the value of j to the value inside j_ptr = 3
    
    printf("%d %d %d %d", i, j, *i_ptr, *j_ptr);
}