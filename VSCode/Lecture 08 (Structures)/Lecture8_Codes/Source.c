#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	struct student {
		char firstName[20];
		char lastName[20];
		int age;
		float GPA;
	};
	// define one variable from the student structure
	struct student student1;
	//read members of the structure variable structureName.memberName
	gets(student1.firstName);
	gets(student1.lastName);
	student1.GPA = 3.5f;
	student1.age = 24;
	printf("The student1 info is as follows \n");
	puts(student1.firstName);
	puts(student1.lastName);
	printf(" is %d and his GPA = %f",student1.age, student1.GPA);
	struct student student2;
	struct student student3;
	struct student student4;
}