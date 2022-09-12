#include <stdio.h>

int main()
{
    char msg[50] = "Hello, welcome to c programming";
    /*to store a sentence or several characters,
    you should use an array with the char data type*/
    printf("%s %c\n", msg, msg[1]);
    /*Use %s for string
    Use %c with the corresponding letter as var[n] 
    to print a single letter*/
    return 0;
}