/*Function: Main
*--------------
*Replace the letters that need to be replaced
*
*using the format variable[n] = 'x' to replace nth variable with 'x'
*/

#include <stdio.h>
int main()
{
    char sentence[] = "hisjniro, right24s8ress, qydnfiety, 5s8flh.";
    sentence[0] = 'H';  //Change letter
    sentence[1] = 'u';  //Change letter
    sentence[2] = 'm';  //Change letter
    sentence[3] = 'a';  //Change letter
    sentence[6] = 't';  //Change letter
    sentence[7] = 'y';  //Change letter
    sentence[10] = 'R'; //Change letter
    sentence[15] = 'e'; //Change letter
    sentence[16] = 'o'; //Change letter
    sentence[17] = 'u'; //Change letter
    sentence[18] = 's'; //Change letter
    sentence[19] = 'n'; //Change letter
    sentence[25] = 'P'; //Change letter
    sentence[26] = 'r'; //Change letter
    sentence[27] = 'o'; //Change letter
    sentence[28] = 'p'; //Change letter
    sentence[29] = 'r'; //Change letter
    sentence[36] = 'W'; //Change letter
    sentence[37] = 'i'; //Change letter
    sentence[38] = 's'; //Change letter
    sentence[39] = 'd'; //Change letter
    sentence[40] = 'o'; //Change letter
    sentence[41] = 'm'; //Change letter
    sentence[42] = '!'; //Change period to exclamation point
    printf("%s\n", sentence);
    return 0;
}