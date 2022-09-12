#include <stdio.h>

int main()
{
    printf("This data should leave the software to output stream\n"); 

    char ch;

    while((ch = getchar()) != '*')
    {
        putchar(ch);
    }
}

//cd "c:\Users\gdlee\OneDrive\바탕 화면\성균관대\1 - 2\프기실\코드\VSCode\Lecture 10 (File Input Output)\" 
//Lecture10_0.exe < Lecture10_0_input.txt > Lecture10_0_output.txt