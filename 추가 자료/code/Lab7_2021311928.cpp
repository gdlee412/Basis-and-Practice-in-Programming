#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int array[]);

int main()
{
	int array[18];
	srand(time(NULL));
	int i=0;
	for(i=0; i<15; i++){
		array[i] = rand()%56 - 5;
		printf("%d ", array[i]);
	}
	printf("\n");
	func(array);
	printf("max = %d\nmin = %d\nsum = %d", array[15], array[16], array[17]);
}

void func(int array[]){
	int i=0;
	int max=-6, min=51, sum=0;
	for(i=0; i<15; i++){
		if(max < array[i]) max=array[i];
		if(min > array[i]) min=array[i];
		sum += array[i];
	}
	array[15] = max;
	array[16] = min;
	array[17] = sum;
}
