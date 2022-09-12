#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //header file for the bool data type

int main()
{
    _Bool var = 50; //used for Boolean data types, any digit other than 0 gets 1 as the output 
    bool boolvar = false; //can use integers as well as true, false
    printf("Variable has value = %d\n", var);
    printf("Variable uses size = %d\n", sizeof(var));
    printf("Variable has value = %d\n", boolvar);
    printf("Variable uses size = %d\n", sizeof(boolvar));
    return 0;
}