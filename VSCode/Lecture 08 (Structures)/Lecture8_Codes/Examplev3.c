// Program to determine tomorrow's date
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
struct date
{
	int month;
	int day;
	int year;
};

struct date dateUpdate(struct date today);

int main(void) {
	struct date thisDay, nextDay;
	printf("Enter today's date (mm dd yyyy): ");
	scanf("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);
	nextDay = dateUpdate(thisDay);
	printf("Tomorrow's date is %i/%i/%i.\n", nextDay.month,
		nextDay.day, nextDay.year);
	return 0;
}
int numberOfDays(struct date d);

// Function to calculate tomorrow's date
struct date dateUpdate(struct date today) {
	struct date tomorrow;
	if (today.day != numberOfDays(today)) {
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
	return tomorrow;
}

bool isLeapYear(struct date d);

// Function to find the number of days in a month
int numberOfDays(struct date d) {
	int days;
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(d) == true && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month - 1];
	return days;
}

// Function to determine if it's a leap year
bool isLeapYear(struct date d) {
	bool leapYearFlag;
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leapYearFlag = true; // It's a leap year
	else
		leapYearFlag = false; // Not a leap year
	return leapYearFlag;
}
