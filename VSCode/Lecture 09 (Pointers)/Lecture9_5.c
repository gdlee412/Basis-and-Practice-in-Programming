#include <stdio.h>

int main()
{
    void* ip = NULL;    //void pointer for unknown data type (flexible pointer)
    
    char a = 'a';
    int b = 30;
    float c = 2.3;
    ip = &a;    //save character variable a into pointer
    putchar(*(char*)ip); //(char*) = indicate pointer as character
    ip = &b;
    printf("\n%d", *(int*)ip);
}