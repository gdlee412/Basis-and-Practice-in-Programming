#include <stdio.h>
#include <string.h>

struct StuInfo {
	char Name[10];
	int IDNo;
	int Exam[2];
};

int main()
{
	FILE *fptr = fopen("lab12_datafile.txt", "r");
	struct StuInfo s[1000];
	char buffer[20]; //for line count (do not print)
	int no; //input student no
	do {
		printf("Enter a student no (-1 to quit): ");
		scanf("%d", &no);
		int line = 0;
		if(no == 1){ //When student_ID is 1, I don't count the lines and immediately read and print fscanf.
			fscanf(fptr, "%s\t%d\t%d\t%d", &s[line].Name, &s[line].IDNo, &s[line].Exam[0], &s[line].Exam[1]);
			printf("Name: %s, Stu#: %d, Exam1: %d, Exam2: %d\n", s[line].Name, s[line].IDNo, s[line].Exam[0], s[line].Exam[1]);	
		}
		rewind(fptr);
		while(fgets(buffer, 20, fptr) != NULL){
			line++;
			if(line == no-1){ //Pointer already goes to the next line because of fgets. So comparing line count(line) and student_id-1 (no-1).
				fscanf(fptr, "%s\t%d\t%d\t%d", &s[line].Name, &s[line].IDNo, &s[line].Exam[0], &s[line].Exam[1]);
				printf("Name: %s, Stu#: %d, Exam1: %d, Exam2: %d\n", s[line].Name, s[line].IDNo, s[line].Exam[0], s[line].Exam[1]);
				break;
			}
		}
	} while(no != -1);
	fclose(fptr);
}
