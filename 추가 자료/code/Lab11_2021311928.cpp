#include <stdio.h>

int main()
{
	int input[20];
	FILE *fptr = fopen("score.dat", "wb");
	for(int i=0; i<20; i++){
		printf("Enter the score for student %d: ", i+1);
		scanf("%d", &input[i]);
	}
	fwrite(&input, sizeof(int), 20, fptr);
	fclose(fptr);
	return 0;
}
