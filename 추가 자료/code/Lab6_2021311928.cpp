#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int array[20];
	int max=24;
	int min=101;
	int sum=0;
	float avg;
	
	srand(time(NULL));
	for(int i=0; i<20; i++){
		array[i] = (rand()%76)+25;
		printf("%d ", array[i]);
		sum += array[i];
		if(max<array[i])	max=array[i];
		if(min>array[i])	min=array[i];
	}
	avg = (float)sum/20;
	printf("\nThe smallest value: %d\n", min);
	printf("The largest value: %d\n", max);
	printf("The average value: %f", avg);
}
