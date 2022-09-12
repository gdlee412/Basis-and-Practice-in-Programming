#include <stdio.h>
#define SECRET 9

void main()
{
    int num = 0;

    printf("Enter the secret number: ");
    while(1)    //infinite loop
    {
        scanf("%d", &num);
        if(num == SECRET)
        {
            printf("CORRECT! Congratulations. \n");
            break;  //end the while loop
        }
        else
        {
            printf("Try again: ");
            continue;   //go to next iteration (continue the loop/program)
        }
    }
}