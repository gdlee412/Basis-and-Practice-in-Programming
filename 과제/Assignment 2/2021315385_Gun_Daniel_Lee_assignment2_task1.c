/*Function: Main
*----------------
*Return the sum of numbers 1 to N, each multiplied by 2
*
*Use define as a macro function for multiplying 2
*
*N: input value; last value considered by count
*count: all the values which will be added; used to go through the macro function
*total: some of all the count values from 1 to N
*
*returns: sum of all the count values; summation of (1*2) + (2*2) + ... + ((N-1)*2) + (N*2)
*/

#include <stdio.h>  //header file

#define MULT(i) i * 2   //macro function for multiplying 2

int main()  //main function
{
    int N;  //declaring integer N used for input
    int count = 1;  //declaring integer count used for while loop; count = 1 since program is meant to find sum of numbers from 1 to N
    int final = 0;  //final sum of number 1 to N, each multiplied by 2; final = 0 just for assurance for the sum

    printf("Enter the value of N: ");   //printf function to request for input by user
    scanf("%d", &N);    //scanf to read the input

    while(count <= N)   //while loop (condition is to run to loop N times)
    {
        final += MULT(count);   //this function will add the MULT(count) macro function every loop (count value will be updated each loop)
        count++;    //increase thw count value by one each loop to update the new count value
    }
    printf("The result of summation: %d", final);   //print the output and final results of sum
    return 0;
}