#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int value1, value2;
    float result;

    printf("Insert first value \n");
    scanf("%d", &value1);
    printf("Insert second value \n");
    scanf("%d", &value2);

    result = (float)value1 / (float)value2; //casting or converting to change values
    printf("The division result is %f \n", result);
    return 0;
}