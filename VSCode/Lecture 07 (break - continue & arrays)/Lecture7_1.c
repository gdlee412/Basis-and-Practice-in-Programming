#include <stdio.h>

int main(void)
{
    int salary = 15000;
    int age = 65;

    if(age > 60)
    {
        salary *= 1.5;
        goto a; //goes to the given program / equation
    }
    else
    {
        salary *= 1.2;
        goto b;
    }

a: salary += 100;
b: salary += 97;
    printf("Salary = %d", salary);
    return 0;
}