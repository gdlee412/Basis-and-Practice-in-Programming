#include <stdio.h>
#include <math.h>

void PrintMenu(void);
int AskUserInput(void);
void DisplayResult(int result);

int main (void)
{
	PrintMenu();
	int input = AskUserInput();
	int result = pow(input, 3);
	DisplayResult(result);
	return 0;
}

void PrintMenu(void) //input request
{
	printf("Please input an integer: ");
}

int AskUserInput(void) //user write input
{
	int a;
	scanf("%d", &a);
	printf("You entered: %d\n", a);
	return a;
}

void DisplayResult(int result) //show result
{
	printf("The result is: %d", result);
}
