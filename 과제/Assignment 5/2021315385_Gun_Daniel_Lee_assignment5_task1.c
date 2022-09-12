/*Function: main
*-----------------------------------
*Request for file name and function call of copyfile function
*
*Request for file name
*sends all file and file name to the copyfile function
*function call on copyfile function

*fp: file pointer for initial file
*copy: file pointer for copy file
*file: name of initial file
*copyf: name of copy file
*
*outputs the final output with the given file names
*/

/*Function: copyfile
*-----------------------------------
*Set name of the copy file as well as copy file information from initial to copy file
*
*open both files and check for possible errors in opening
*copy initial file name to copy file name excluding ".txt"
*add string "_copy.txt" to copy file name
*Open both files and check for error in opening files
*copy content of file to copy file until EOF
*close both files and check for possible errors in closing
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define temporary max
#define MAX 40

//declare copyfile function
void copyfile(char *file, FILE *fp, char *copyf, FILE *copy);

//main function
int main()
{
    //declare variables
    FILE *fp, *copy;
    char file[MAX], copyf[MAX];

    //request for filename input
    printf("Enter filename: ");
    scanf("%s", file);

    //function call on copyfile
    copyfile(file, fp, copyf, copy);

    //print out final output
    printf("The copy of the file \"%s\" is created with the name: %s\n", file, copyf);

    return 0;
}

//copyfile funtion
void copyfile(char *file, FILE *fp, char *copyf, FILE *copy)
{
    //declare variables
    char ch;
    int i;
    
    //for loop to copy name of file to copy file
    for(i = 0; i < MAX; i++)
    {
        //if statement to continuously copy until the '.'
        if(file[i] != '.')
        {
            copyf[i] = file[i];
        }
        
        //once '.' is reached
        else
        {
            //set the next index as '\0' to trash out the remaining space
            copyf[i] = '\0';
            //break out from loop
            break;
        }
    }

    //add "_copy.txt" to the copyf variable
    strcat(copyf, "_copy.txt");

    //open the initial file as well as check for successful file opening
    if((fp = fopen(file, "r")) == NULL)
    {
        //exit program if cannot open file
        fprintf(stdout, "Can't open given file.");
        exit(1);
    }
    
    //open the copy file as well as check for successful file opening
    if((copy = fopen(copyf, "w")) == NULL)
    {
        //exit program if cannot open file
        fprintf(stdout, "Can't open copied file."); 
        exit(1);
    }

    //while loop to check whether character is the EOF (End of File)
    while((ch = fgetc(fp)) != EOF)
    {
        //when not the EOF, put the character into the copyfile
        putc(ch, copy);
    }
    
    //close initial file as well as check for successful file closing
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }

    //close initial file as well as check for successful file closing
    if(fclose(copy) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }
}