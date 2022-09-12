#include <stdio.h>

int main()
{
    char light;
    char lane;
    char turn;

    //USER_INPUT Light Red?, Lane Right? Turn Yes?;
    printf("Is light red? \n");
    scanf("%c", &light);
    printf("Confirm answer: %c \n", light); //validate user input
    fflush(stdin);

    printf("Are you in the right lane? \n");
    scanf("%c", &lane);
    printf("Confirm answer: %c \n", lane); //validate user input
    fflush(stdin);

    printf("Are you making a turn? \n");
    scanf("%c", &turn);
    printf("Confirm answer: %c \n", turn); //validate user input
    fseek(stdin,0,SEEK_END);

    return 0;
}