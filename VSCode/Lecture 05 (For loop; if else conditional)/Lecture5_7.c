#include <stdio.h>

void main()
{
    char ch;
    ch = getchar();

    while(ch != '\n')
    {
        if(ch >= 97 && ch <= 122)
            putchar(ch - 32);
        else
            putchar(ch);

        ch = getchar();
    }

    putchar(ch);
}