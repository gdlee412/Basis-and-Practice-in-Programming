#include <stdio.h>

int main()
{
	int select = 0;
	int won = 0;
	float money = 0;
	while(select!=5){
		printf("Please choose which currency you want to convert:\n");
		printf("1 - Korean won to US Dollar (Exchange Rate: 0.00905\n");
		printf("2 - Korean won to Euro (Exchange Rate: 0.000807350908\n");
		printf("3 - Korean won to Japanese Yen (Exchange Rate: 0.0919061643\n");
		printf("4 - Korean won to Chinese RMB (Exchange Rate: 0.00603703605\n");
		printf("5 - Quit\n");
		printf("Enter your option: ");
		scanf("%d", &select);

		switch(select) {
			case 1:
				printf("Enter the amount in Korea Won: ");
				scanf("%d", &won);
				money = (float)won*0.00905;
				printf("%d Won equals to %f US Dollar\n\n", won, money);
				break;
			case 2:
				printf("Enter the amount in Korea Won: ");
				scanf("%d", &won);
				money = (float)won*0.000807350908;
				printf("%d Won equals to %f Euro\n\n", won, money);
				break;
			case 3:
				printf("Enter the amount in Korea Won: ");
				scanf("%d", &won);
				money = (float)won*0.0919061643;
				printf("%d Won equals to %f Japanese Yen\n\n", won, money);
				break;
			case 4:
				printf("Enter the amount in Korea Won: ");
				scanf("%d", &won);
				money = (float)won*0.00603703605;
				printf("%d Won equals to %f Chinese RMB\n\n", won, money);
				break;
			case 5:
				break;
			default:
				printf("You entered an invalid input.\n\n");
				break;
		}
	}
}	
