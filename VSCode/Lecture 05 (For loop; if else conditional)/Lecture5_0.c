#include <stdio.h>

void main(void)
{
    char ch;

    for(ch = 'a'; ch <= 'z'; ch++)  //for loop
        printf("The ASCII value for %c is %d.\n",ch , ch); //for 1 line of code within loop, no need {}
}