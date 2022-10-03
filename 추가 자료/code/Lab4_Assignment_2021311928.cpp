#include <stdio.h>

float CurrencyConversion(float AmountInWon, float rate);

int main(void)
{
	char select;
	int won = 0;
	float money;
	
	while(select != 'E'){
		printf("Please choose which currency you want to convert:\n");
		printf("A - Korean won to US Dollar (Exchange Rate: 0.00905)\n");
		printf("B - Korean won to Euro (Exchange Rate: 0.000807350908)\n");
		printf("C - Korean won to Japanese Yen (Exchange Rate: 0.0919061643)\n");
		printf("D - Korean won to Chinese RMB (Exchange Rate: 0.00603703605)\n");
		printf("E - Quit\n");
		printf("Enter your option: ");
		scanf(" %c", &select); //for buffer error solve
		
		switch(select) {
		case 'A': //dollar
			printf("Enter the amount in Korea Won: ");
			scanf("%d", &won);
			money = CurrencyConversion((float)won, 0.00905);
			printf("%d Won equals to %f US Dollar\n\n", won, money);
			break;
		case 'B': //euro
			printf("Enter the amount in Korea Won: ");
			scanf("%d", &won);
			money = CurrencyConversion((float)won, 0.000807350908);
			printf("%d Won equals to %f Euro\n\n", won, money);
			break;
		case 'C': //yen
			printf("Enter the amount in Korea Won: ");
			scanf("%d", &won);
			money = CurrencyConversion((float)won, 0.0919061643);
			printf("%d Won equals to %f Japanese Yen\n\n", won, money);
			break;
		case 'D': //rmb
			printf("Enter the amount in Korea Won: ");
			scanf("%d", &won);
			money = CurrencyConversion((float)won, 0.00603703605);
			printf("%d Won equals to %f Chinese RMB\n\n", won, money);
			break;
		case 'E': //quit
			break;
		default: //not abcde
			printf("You entered an invalid input.\n\n");
			break;
		}
	}
}

float CurrencyConversion(float AmountInWon, float rate)
{
	float money = AmountInWon*rate; //conversion (won to foreign money)
	return money;
}
