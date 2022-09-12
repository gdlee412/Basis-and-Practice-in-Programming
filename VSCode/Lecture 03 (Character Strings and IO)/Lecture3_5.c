#include <stdio.h>

#define CIRCUM(r) 2.0 * PI * r //using define to simplify equations
#define AREA(r) PI * r * r
#define PRINT(x,y) printf("circumference = %1.2f, area = %1.2f\n", x, y)

int main()
{
    float area, circum, radius; //const to express constant unchanging values
    const char NAME[5] = "John";
    const char COLLEGE[5] = "SKKU";
    const int AGE = 20;
    const float PI = 3.14159;
    //expressions are not allowed for const

    printf("What is the radius of your pizza? \n");
    scanf("%f", &radius);
    circum = CIRCUM(radius);
    area = AREA(radius);
    
    PRINT(circum, area);

    return 0;
}