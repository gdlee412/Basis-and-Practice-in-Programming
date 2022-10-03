#include <stdio.h>

int main()
{
	int a;
	int sum = 0;
	float avg;
	int cnt = 0;
	
	for (;a!=-1;) { //a가 -1일 때까지 loop 
		printf("Enter the number : ");
		scanf("%d", &a);
		sum += a;
		cnt++; 
	}
	sum += 1;
	cnt -= 1;
	avg = (float)sum / (float)cnt;
	printf("Average : %f", avg);
	return 0;
}
