#include <stdio.h>

int main()
{
	int date, y, m, d1, d;
	printf("Enter a date in numerical form (MMDDYYYY):");
	scanf("%d", &date); //input date
	y = date % 10000;
	m = date / 1000000;
	d1 = date / 10000;
	d = d1 % 100;
	
	printf("%d.%d.%d", y,m,d);

	printf("The date you entered is: "); //output change date
	if (d==1 || d==21 || d==31)	printf("%dst ", d);
	else if (d==2 || d==22) 	printf("%dnd ", d);
	else if (d==3 || d==23) 	printf("%drd ", d);
	else 						printf("%dth ", d);  //output day
	if (m==1)		printf("January");
	else if (m==2)	printf("February");
	else if (m==3)	printf("March");
	else if (m==4)	printf("April");
	else if (m==5)	printf("May");
	else if (m==6)	printf("June");
	else if (m==7)	printf("July");
	else if (m==8)	printf("August");
	else if (m==9)	printf("September");
	else if (m==10)	printf("October");
	else if (m==11)	printf("November");
	else if (m==12)	printf("Dececmber"); //output month
	printf(" %d", y); //output year
}
