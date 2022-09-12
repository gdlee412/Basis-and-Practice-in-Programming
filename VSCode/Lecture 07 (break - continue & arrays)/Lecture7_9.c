#include <stdio.h>
#define MAX 4

int main(void)
{
    int a[MAX];
    int n, i, j;

    printf("How many elements (maximum %d)?\n", MAX);
    scanf("%d", &n);

    if(n > MAX)
    {
        printf("Number too big!\n");
        return 1; //software will terminate with error
    }
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
    return 0;
}