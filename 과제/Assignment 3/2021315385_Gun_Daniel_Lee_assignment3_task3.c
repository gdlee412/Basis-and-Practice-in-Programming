/*Function: Main
*---------------
*Given an array of numbers, function will arrange numbers from smallest to largest
*
*Input array: jumbled set of numbers
*
*Function call on Arrange
*Returns arranged array of numbers from smallest to largest
*
*----------------
*Function: Arrange
*----------------
*Given an array of numbers
*
*Loop an if statement to arrange values
*
*Returns array
*/

//header files and defining max value for arrays
#include <stdio.h>
#include <string.h>
#define MAX 100

//declare arrange function
void arrange(int size, int arr[]);


//main function
int main()
{
    //declare variables
    int arr[MAX] =  {0,};
    int i, size = 0;

    //request for array input
    printf("Enter the elements of the array: ");
    //while loop to continuously scan for the new elements of the array
    while(scanf("%d", &arr[size]))
    {
        //increase the size value to get next elements of array (also used to find the size input for future references)
        size++;
        //if statement using getchar() to stop the loop when the enter key is pressed or when a new line is detected
        if(getchar() == '\n')
        {
            //break out from the loop
            break;
        }
    }

    //function call to arrange
    arrange(size, arr);

    //print out the results
    printf("The result: ");
    //for loop used to print out each element of the array
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

//definition for arrange function
void arrange(int size, int arr[])
{
    //declaration of integer variables
    int i, j, temp;

    for(i = 0; i < size - 1; i++)   //for loop to go through each element of the array
    {
        for(j = i + 1; j < size; j++)    //for loop to compare element with every other element
        {
            if(arr[i] > arr[j]) //condition to check if values are increasing
            {
                temp = arr[i];  //input first integer to a temporary variable
                arr[i] = arr[j];    //replace first position with the smaller value
                arr[j] = temp;  //substitute the second position
            }
        }
    }
}