#include <stdio.h>

int main()
{
    int x = 1;
    int *ptr;
    ptr = &x;
    printf("Address of variable = %p and value of variable = %d\n", ptr, *ptr);

    ptr = ptr + 1; //goes to next address (usually 4 bytes after current address, depending on variable type)
    printf("Address of variable = %p and value of variable = %d\n", ptr, *ptr);
}