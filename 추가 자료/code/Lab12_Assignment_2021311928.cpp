#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StuInfo {
	char Name[10];
	int IDNo;
	int Exam[2];
	StuInfo * NextPtr;
};

void PrintAllName(StuInfo Node)
{
	StuInfo * ThisPtr = &Node;
	while(ThisPtr != NULL){
		printf("Name: %s\n", ThisPtr->Name);
		ThisPtr = ThisPtr->NextPtr;
	}
	printf("\n");
}

float AverageScore(StuInfo Node)
{
	float sum = 0;
	StuInfo * ThisPtr = &Node;
	while(ThisPtr != NULL){
		sum += ThisPtr->Exam[0];
		sum += ThisPtr->Exam[1];
		ThisPtr = ThisPtr->NextPtr;
	}
	sum = sum/160;
	return sum;
}

StuInfo * BestStudent (StuInfo Node)
{
	float av = 0, max = -999;
	StuInfo * ThisPtr = &Node;
	StuInfo * tmp = NULL;
	while(ThisPtr != NULL){
		av = (ThisPtr->Exam[0] + ThisPtr->Exam[1]) / 2;
		if(av > max) {
			max = av;
			tmp = ThisPtr;
		}
		ThisPtr = ThisPtr->NextPtr;
	}
	return tmp;
}

int main()
{
	FILE *fptr = fopen("lab12_datafile.txt", "r");
	StuInfo node[1000];
	StuInfo * best;
	
	for(int i=0; feof(fptr)==0; i++){
		fscanf(fptr, "%s\t%d\t%d\t%d", &node[i].Name, &node[i].IDNo, &node[i].Exam[0], &node[i].Exam[1]);
		node[i].NextPtr = NULL;
		node[i-1].NextPtr = &node[i];
	}
	fclose(fptr);
	PrintAllName(node[0]);
	printf("%f\n", AverageScore(node[0]));
	best = BestStudent(node[0]);
	printf("\n%s\t%d\t%d\t%d", best->Name, best->IDNo, best->Exam[0], best->Exam[1]);
}
