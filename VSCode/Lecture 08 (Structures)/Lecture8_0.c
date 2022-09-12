#include <stdio.h>

int main()
{
    struct student
    {
        char firstname[20];
        char lastname[20];
        int age;
        float GPA;
    };

    struct student student1;
    gets(student1.firstname);
    gets(student1.lastname);
    student1.GPA = 3.5;
    student1.age = 24;
    printf("The student1 info is as follows: \n");
    puts(student1.firstname);
    puts(student1.lastname);
    printf(" is %d and his GPA = %f", student1.age, student1.GPA);

    struct student student2;
    struct student student3;
    struct student student4;
}