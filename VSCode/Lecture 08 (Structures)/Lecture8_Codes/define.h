#pragma once
typedef struct
{
	int month;
	int day;
	int year;
}date;

typedef struct  {
	int hour;
	int min;
	int sec;

}time;

typedef struct 
{
	 date sdate;
	 time stime;
}dateAndTime;