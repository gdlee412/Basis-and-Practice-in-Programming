#include <stdio.h>

int main()
{
	int op, input[20];
	FILE *fptr = fopen("score.dat", "rb+");
	do {
		printf("1. Read and display all data from \"score.dat\".\n2. Multiply all the numbers in \"score.dat\" by 2.\n3. Quit.");
		printf("\nEnter your option: ");
		scanf("%d", &op);
		if(op == 1){
			rewind(fptr);
			fread(&input, sizeof(int), 20, fptr);
			for(int i=0; i<20; i++)	printf("%d ", input[i]);
			printf("\n");
		}
		else if(op == 2){
			rewind(fptr);
			fread(&input, sizeof(int), 20, fptr);
			for(int i=0; i<20; i++)	input[i]*=2;
			rewind(fptr);
			fwrite(&input, sizeof(int), 20, fptr);
		}
		else if(op == 3)	break;
	} while (op != 3);
	fclose(fptr);
	return 0;
}
