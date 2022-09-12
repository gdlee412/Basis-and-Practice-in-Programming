/*Function: Main
*------------------
*Returns the age, gender, height, weight, blood type, and body temperature information inputted by user
*
*age: integer variable
*gender and blood type: character variable (1 letter only)
*height, weight, body_temp: float number variables

*using scanf to receive all the needed variables
*using 1 printf to print the output

*/


#include <stdio.h> //header file to use printf and scanf

int main() //main program
{
    int age;        //declare the age variable as an integer
    char gender, blood_type;    //declare the gender and blood type variables as a character
    float height, weight, body_temp;    //declare the height, weight, and body temperature variables as float numbers as decimals are needed

    printf("How old are you?\n");   //print out the question
    scanf("%d", &age);  //used to input age data, use %d to specify an integer input for age

    printf("What is your gender (M/F)?\n"); //print out the question
    scanf(" %c", &gender);   //used to input gender data, use %c to specify a character input for gender (space added before %c due to an apparent error in the c software)


    printf("What is your height (in meters)?\n");   //print out the question
    scanf("%f", &height);   //used to input height data, use %f to specify a float number input for height

    printf("What is your weight (in kilograms)?\n");    //print out the question
    scanf("%f", &weight);   //used to input weight data, use %f to specify a float number input for weight

    printf("What is your blood type (allowable blood types: A, B and O)?\n");   //print out the question
    scanf(" %c", &blood_type);  //used to input blood type data, use %c to specify a character input for blood type (space added before %c due to an apparent error in the c software)
    
    printf("What is your body temperature?\n");     //print out the question
    scanf("%f", &body_temp);    //used to input body temperature, use %f to specify a float number input for body temperature


    printf("You are %d years old and your gender is \"%c\".\nYour height and weight are %.2f m, %.2f kg.\nYour blood type is \'%c\'.\nYour body temperature is %.2f degrees Celsius.", age, gender, height, weight, blood_type, body_temp); //print final output
    return 0;
}