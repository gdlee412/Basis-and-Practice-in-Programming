/*Function: main
*----------------
*Returns the reverse order of full name, twice for each character
*
*StrLen stops reading when it encounters a space
*Make two identical nested for() loops
*Each nested for() loop to print name in reverse and to print each character two times (first and last name)
*
*returns: full name in reverse, each character printed two times
*/

#include <stdio.h>  //header file
#include <string.h> //header file for strlen()

int main() //main function
{
    char first[50], last[50];  //string for full name; first and last
    int i, j;   //declaration of variables for the for loop

    printf("Enter your full name: ");   //request for full name input
    scanf("%s %s", first, last);  //scan input for full name

    for(i = strlen(last) - 1; i >= 0; i--)  //loop used to print last name in reverse from last character[length-1] to first character[0]
    {
        for(j = 0; j < 2; j++)  //loop used to print each character two times
        {
            printf("%c", last[i]);  //prints the characters of last name
        }
    }

    printf(" ");    //print the space in between both loops

    for(i = strlen(first) - 1; i >= 0; i--)  //loop used to print first name in reverse from last character[length-1] to first character[0]
    {
        for(j = 0; j < 2; j++)  //loop used to print each character two times
        {
            printf("%c", first[i]);  //prints the characters of first name
        }
    }
    return 0;
}