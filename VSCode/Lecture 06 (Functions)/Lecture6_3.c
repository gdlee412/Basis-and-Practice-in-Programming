#include <stdio.h>

int str_length(char a[]);   //string length finding function

void main()
{
    char name[30];
    int len = 0;

    printf("Please enter your name: ");
    scanf("%s", name);

    len = str_length(name);

    printf("Your name is %s of length %d.\n", name, len);
}

int str_length(char a[])
{
    int count = 0;
    while(a[count] != '\0')
    {
        count++;
    }

    return count;
}