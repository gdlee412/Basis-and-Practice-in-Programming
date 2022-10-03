#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int result[2];
	int sum = 0;
	srand(time(NULL));
	printf("Result: ");
	for (int i=0; i<3; i++){
		int random = (rand()%6)+1;
		printf("%d ", random);
		sum += random;
		result[i] = random;
	}
	if (result[0] == result[1] && result[0] == result[2] && result[1] == result[2])
		printf("\nTRIPLE!");
	else if (sum >= 3 && sum <= 10)		printf("\nSMALL!");
	else if (sum >= 11 && sum <= 17)	printf("\nBIG!");
	return 0;
}
