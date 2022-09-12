#include <stdio.h>
#define MAX 100


typedef struct
{
    char name[MAX];
    char* subj[5];
    int score[5];

}student;

int main()
{
    student n;
    int i, sum = 0;
    float percentage = 0;
    n.subj[0] = "C Programming subject";
    n.subj[1] = "Data Structure subject";
    n.subj[2] = "Algorithm Subject";
    n.subj[3] = "Math subject";
    n.subj[4] = "Physics subject";

    printf("Enter name: ");
    gets(n.name);

    for(i = 0; i < 5; i++)
    {
        printf("Marks in grade for %s = ", n.subj[i]);
        scanf("%d", &n.score[i]);
        sum = sum + n.score[i];
    }

    percentage = sum / 5;

    printf("Name: %s\n", n.name);
    printf("Total Marks = %d\n", sum);
    printf("Percentage: %.2f", percentage);

    return 0;
}