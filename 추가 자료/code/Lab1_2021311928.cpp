#include <stdio.h>

int main()
{
 	int JohnS, MaryS, PeterS, JaneS;
 	printf("Input John's score': ");
 	scanf("%d", JohnS);
 	printf("Input Mary's score': ");
 	scanf("%d", MaryS);
 	printf("Input Peter's score': ");
 	scanf("%d", PeterS);
 	printf("Input Jane's score': ");
 	scanf("%d", JaneS);
 	float aver=(JohnS+MaryS+PeterS+JaneS)/4;
 	printf("%f", aver);
}
