#include <stdio.h>

#define name "John"
#define college "SKKU"
#define age 19
#define PRINT(digitvalue) printf("the digit value is %d \n", digitvalue)

int main()
{
    printf("My name is %s \n", name);
    printf("I study at %s \n", college);
    printf("I am %d years old \n", age);
    PRINT(age);

    return 0;
}