#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int array[10][8];
	int max=9;
	int min=101;
	int sum=0;
	float avg;
	
	srand(time(NULL));
	for(int i=0; i<10; i++){
		for(int j=0; j<8; j++){
			array[i][j] = (rand()%91)+10;
			printf("%d ", array[i][j]);
			sum += array[i][j];
			if(max<array[i][j])	max=array[i][j];
			if(min>array[i][j])	min=array[i][j];
		}
		printf("\n");
	}

	avg = (float)sum/80;
	printf("The smallest value is %d.\n", min);
	printf("The largest value is %d,\n", max);
	printf("The average value is %f,", avg);
}
