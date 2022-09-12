//Finding Errors

#include <stdio.h>  //1 did not include header file

#define B "Huey" //2, 3 missing #; missing ""
#define X 10

int main() //4 int before main
{
    int age;
    int xp;
    char name[50]; //5 must use array of characters
    printf("My name is %s, please enter your first name.", B); //6 %s instead of %c
    scanf("%s", name); 
    printf("All right, %s, what's your age?\n", name); //7 %s instead of %c
    scanf("%d", &age); //8,9 %d instead of %f, age missing &
    xp = age + X; //10 xp is undeclared
    printf("After %d years, you will be %d years old.\n", X, xp); //11 did not specify first value
    return 0;
} //12 did not enclose main program; missing }