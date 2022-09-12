#include <stdio.h>
#include <string.h> //header for strlen() prototype

void main()
{
    float weight;
    int size, letters;
    char name[40];  //name variable is an array of 40 char

    printf("Hi! What's your first name?\n");
    scanf("%s", name); // & is not required for strings
    printf("Hi %s, what's your weight in kg?\n", name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name); 
    /*strlen() counts the numbers of char in string
    strlen means string length*/

    printf("Hello %s, \n", name);
    printf("your name has %d letters, \n", letters);
    printf("and your weight is %.2f kg.\n", weight);
}

