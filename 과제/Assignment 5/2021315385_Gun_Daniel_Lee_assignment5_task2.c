/*Function: main
*-----------------------------------
*Request for file name and function call of rowlength function
*
*Request for file name
*sends all file and file name to the rowlength function
*function call on rowlength function
*
*fp: file pointer for initial file
*file: name of initial file
*/

/*Function: rowlength
*-----------------------------------
*check number of characters in row and outputs each row's results
*
*open file and check for errors while opening
*use while loop to get the number of characters in each row
*when space is encountered, program will ignore and continue
*when newline is encountered, program will print result, restart values, and continue
*when EOF is encountered, program will print last result, and break from loop
*close file
*
*count: number of characters in each row
*i: row number
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define temporary max
#define MAX 100

void rowlength(FILE *fp, char *file);

//main function
int main()
{
    //declare variables
    FILE *fp;
    char *file;

    //request for filename input
    printf("Enter filename: ");
    scanf("%s", file);

    //function call on rowlength
    rowlength(fp, file);
    
    return 0;
}

//rowlength function
void rowlength(FILE *fp, char *file)
{
    //declare variables
    char ch;
    int i = 1, count = 0;

    //open the file as well as check for successful file opening
    if((fp = fopen(file, "r")) == NULL)
    {
        //exit program if cannot open file
        fprintf(stdout, "Can't open given file.");
        exit(1);
    }
    
    //while loop
    while(1)
    {
        //increase count if character is not a space
        if((ch = getc(fp)) != ' ')
        {
            count++;
        }
        
        //if space is encountered, just continue with the loop
        else
        {
            continue;
        }

        //if new line is detected, program will output the number of letters in the line
        if(ch == '\n')
        {
            //subtract 1 count due to the excess count caused by the new line
            count--;
            //print result
            printf("Row %d: there are %d letters\n", i, count);
            //restart variables and increase row variable
            count = 0;
            i++;
        }
        
        //if end of file is reached, program will output the last row before the EOF
        //then program will escape the while loop
        if(ch == EOF)
        {
            //subtract 1 count due to excess count caused by EOF
            count--;
            //print result
            printf("Row %d: there are %d letters\n", i, count);
            //break out from for loop
            break;
        }
    }

    //close initial file as well as check for successful file closing
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }
}