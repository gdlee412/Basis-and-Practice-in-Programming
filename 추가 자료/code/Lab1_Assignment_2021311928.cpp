#include <stdio.h>

int main()
{
 	int John, Mary, Peter, Jane; //�������� 
 	printf("Input John's score': ");
 	scanf("%d", &John);
 	printf("Input Mary's score': ");
 	scanf("%d", &Mary);
 	printf("Input Peter's score': ");
 	scanf("%d", &Peter);
 	printf("Input Jane's score': ");
 	scanf("%d", &Jane);
 	printf("Average: %f", ((double)John+(double)Mary+(double)Peter+(double)Jane)/4); //���� ����ȯ���Ѽ� ��� ���ϱ� 
}
