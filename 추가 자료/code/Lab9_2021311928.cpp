#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int numbers[45];
	for (int i=0; i<45; i++)
		numbers[i] = i+1;
	int * pick[6] = {0};
	
	srand(time(NULL));
	for (int i=0; i<6; i++){
		int a = rand()%45; //0 to 44 
		pick[i] = &numbers[a];
	}
	
	printf("%d %d %d %d %d %d", *pick[0], *pick[1], *pick[2], *pick[3], *pick[4], *pick[5]);
}
