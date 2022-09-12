/*Function: Main
*---------------
*Given a certain string, function will count the occurence of lowercase, uppercase, special characters and numeric values
*
*Input string: string including a combination of lowercase, uppercase, special characters, and numeric values
*
*Function call on Occur
*Return the occurence
*
*----------------
*Function: Occur
*----------------
*Given a string input, function will scan the occurences
*
*Returns low, up, num, spec:
* low: number of lowercase letters
* up: number of uppercase letters
* num: number of numeric values
* spec: number of special characters
*/

//header file and defining the max for strings
#include <stdio.h>
#include <string.h>
#define MAX 100

//declaration of occurence function
void occur(char str[]);

//main function
int main()
{
    //declare string variable
    char str[MAX];

    //request for string input
    printf("Enter the string: ");
    scanf("%s", str);

    //function call on occur
    occur(str);
}

//definition of occur
void occur(char str[])
{
    //declare all the int variables
    int i, low = 0, up = 0, spec = 0, num = 0;

    //for loop will loop for as long as the string length
    for(i = 0; i < strlen(str); i++)
    {
        //if to determine which counter variable to increase
        //uppercase letters
        if(str[i] >= 'A' && str[i] <= 'Z')  //condition to increase uppercase variable
        {
            up++;
        }
        //lowercase letters
        else if(str[i] >= 'a' && str[i] <= 'z') //condition to increase lowercase variable
        {
            low++;
        }
        //numbers
        else if(str[i] >= '0' && str[i] <= '9') //condition to increase number variable
        {
            num++;
        }
        //special characters
        else
        {
            spec++;
        }
    }

    //print out the results of occurence
    printf("Uppercase letters: %d\n", up);
    printf("Lowercase letters: %d\n", low);
    printf("Numbers: %d\n", num);
    printf("Special characters: %d\n", spec);
}