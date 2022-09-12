#include <stdio.h>

void dash(int a); //declare the function

void main()
{
    char name[20];

    printf("Please, enter your name : ");
    scanf("%s", name);

    dash(20); //recall function
    printf("Your name is %s\n", name);
    dash(20);
}

void dash(int a) //function
{
    int i;
    
    for(i = 0; i <= a; i++)
    {
        putchar('-');
    }
    printf("\n");
}