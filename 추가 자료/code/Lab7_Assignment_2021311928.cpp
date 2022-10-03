#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int array[], int search, int &answer);

int main()
{
	int search, array[10];
	int answer = 0;
	srand(time(NULL));
	for(int i=0; i<10; i++){
		array[i] = rand()%99 + 1;
		printf("A[%i]: %d, ", i, array[i]);
	}
	printf("\nEnter the number you want to search: ");
	scanf("%d", &search);
	func(array, search, answer);
	if (answer == 1)	printf("The number you entered is in the array."); //if contain
	else if (answer == 2)	printf("The number you entered is not in the array."); //if not contain
}

void func(int array[], int search, int &answer){
	for(int i=0; i<10; i++){
		if(array[i] == search){
			answer = 1;
			break;
		} else {
			continue;
		}
	}
	if(answer != 1) answer = 2;  //after turning for¹®, if not contain, turn answer = 2 
}
