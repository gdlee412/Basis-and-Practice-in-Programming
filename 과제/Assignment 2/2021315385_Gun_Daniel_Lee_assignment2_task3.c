/*Function: Main
*----------------
*Returns the number of years it takes Frank to have less than $20k in his account
*
*loops the withdrawal of $300k from account and the interest rate of 3% per year
*
*returns: N, number of years it takes Frank to have less than $20k
*/

#include <stdio.h>  //header file

int main()  //main function
{
    int N = 0, m = 2000000; //declaration of integers N and m, N = number of years it takes Frank to have less than $20k, m = money in Frank's account
    int i;  //declaration of variable for the for loop

    for(i = 0; i <= 10; i++)    //for loop to repeat the withdrawal and interest rate process
    {
        m -= 300000;    //withdrawal of $300k before the interest rate
        m *= 1.03;  //interest rate of 3%, adding 3% to the account is the same as multiplying 103% (1.03) to the account
        N++;
        if(m < 20000)   //if statement used to stop loop when money is less than $20,000
        {
            break;  //break out of loop
        }
    }
    printf("It takes %d years for Frank to have money less than $20,000 in his account.", N);   //prints final N
    return 0;   
}