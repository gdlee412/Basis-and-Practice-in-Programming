#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	bool check = false;
	bool lowercheck = false;
	bool uppercheck = false;
	bool numbercheck = false;
	bool punccheck = false;
	bool blankcheck = false;
	char pw[100] = {};	//declaration variable
	gets(pw);
	int len = strlen(pw);
	if(len<6)	check = false; //check minimun length
	for(int i=0; i<len; i++){
		char pwarray = pw[i];
		if(!lowercheck)	lowercheck = islower(pwarray);
		if(!uppercheck)	uppercheck = isupper(pwarray);
		if(!numbercheck)	numbercheck = isdigit(pwarray);
		if(!punccheck)	punccheck = ispunct(pwarray);
		if(!blankcheck)	blankcheck = isspace(pwarray);
	} //check password
	if((lowercheck && uppercheck && numbercheck) && (punccheck || blankcheck)){
		check = true;
	}
	if(check)	printf("This is a valid password");
	else	printf("This is NOT a valid password");
}
