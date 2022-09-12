#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

 
int main(void)
{
	struct date
	{
		int month;
		int day;
		int year;
	};
	struct date today, tomorrow;
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };
	

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%i%i%i", &today.month, &today.day, &today.year);
	
	tomorrow = today;
	if (today.day == tomorrow.day &&
		today.month == tomorrow.month &&
		today.year == tomorrow.year) {

		printf("today is same like tomorrow\n");
	}
	
	
	
	if (today.day != daysPerMonth[today.month - 1]) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12) { // end of year
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else { // end of month
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	printf("Tomorrow's date is %i/%i/%i.\n", tomorrow.month,
		tomorrow.day, tomorrow.year);
	return 0;
}

 