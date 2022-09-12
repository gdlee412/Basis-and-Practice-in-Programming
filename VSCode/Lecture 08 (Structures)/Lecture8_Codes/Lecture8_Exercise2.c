#include <stdio.h>
#define MAX 1000

typedef struct
{
    int bday, bmonth, byear;
}birth;

typedef struct
{
    char name[MAX];
    int year;
    birth date;
}student;


int main()
{
    student n;

    printf("Enter name: ");
    gets(n.name);

    printf("Enter your join year: ");
    scanf("%d", &n.year);

    printf("Enter Date of Birth [DD MM YYYY] format: ");
    scanf("%d %d %d", &n.date.bday, &n.date.bmonth, &n.date.byear);

    printf("\nName : %s\n", n.name);
    printf("Join Year : %d\n", n.year);

    if(n.date.bmonth < 10)
    {
        printf("Date of Birth : %d - 0%d - %d", n.date.bday, n.date.bmonth, n.date.byear);
    }
    else
    {
        printf("Date of Birth : %d - %d - %d", n.date.bday, n.date.bmonth, n.date.byear);
    }

    return 0;
}