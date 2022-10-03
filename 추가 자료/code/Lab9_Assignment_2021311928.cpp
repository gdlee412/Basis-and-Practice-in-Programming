#include <stdio.h>

int main(void)
{ 
	int input[10];
	for(int i=0; i<10; i++){
		printf("Enter number %d: ", i);
		scanf("%d", &input[i]);
	}
	printf("User entered: ");
	for(int i=0; i<10; i++)
		printf("%d ", input[i]); //print user's input
	int * head = &input[0];
	int * tail = &input[9];
	for(int i=0; i<5; i++){
		if(*head != *tail){
			printf("\nNO!!! It is not a palindrome!");
			return 0; //it's not a palindrome, so EXIT now
		}
		else {
			head++;
			tail--;
		}
	}
	printf("\nYES!!! It is a palindrome!");
	return 0;
}
