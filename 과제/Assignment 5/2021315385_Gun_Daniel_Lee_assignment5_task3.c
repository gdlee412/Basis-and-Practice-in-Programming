/*Function: main
*-----------------------------------
*Request for file name and function call of wordoccurence function
*
*Request for file name
*Request for word used for wordoccurence function
*sends file, file name, and word to the wordoccurence function
*function call on wordoccurence function
*print out final result
*
*fp: file pointer for initial file
*file: name of initial file
*word: word needed for wordoccurence function
*occur: number of occurrences of word
*/

/*Function: wordoccurence
*-----------------------------------
*check number of occurences of the given word in the given file
*
*open file and check for possible errors during the opening process
*use while loop to go through entire file
*use second while loop to check for specific string / word occurence
*close file and check for errors during the closing process
*return the number of occurences
*
*count: number of occurences of the given word
*i: index to help create new string
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define temporary max
#define MAX 40

int wordoccurence(FILE *fp, char *file, char *word);

//main function
int main()
{
    //declare variables
    FILE *fp;
    char *file, word[MAX];
    int occur;

    //request for filename input
    printf("Enter filename: ");
    scanf("%s", file);

    //request for word input
    printf("Enter a word: ");
    scanf("%s", word);

    //function call on wordoccurence
    //save result in occur variable
    occur = wordoccurence(fp, file, word);
    
    //if statement just for grammatical purposes
    if(occur <= 1)
    {
        printf("There is %d occurence of the word \"%s\"", occur, word);
    }
    else
    {
        printf("There are %d occurences of the word \"%s\"", occur, word);
    }

    return 0;
}

//wordoccurence function
int wordoccurence(FILE *fp, char *file, char *word)
{
    //declare variables
    char c[MAX];
    char *ch = NULL;
    int i = 1, count = 0;

    //open the file as well as check for successful file opening
    if((fp = fopen(file, "r")) == NULL)
    {
        //exit program if cannot open file
        fprintf(stdout, "Can't open given file.");
        exit(1);
    }
    
    //first while loop to read the entire file until EOF
    while(fgets(c, MAX, fp) != NULL)
    {
        //declare local variable
        int i = 0;
        //second while loop to find occurence of the word
        //will loop every time a new occurence is found
        while((ch = strstr(c + i, word)) != NULL)
        {
            //declare i = 1 for new index (used to continue finding occurences after the first)
            i = 1;
            //increase count
            count++;
        }
    }
    //close initial file as well as check for successful file closing
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }

    //return count
    return count;
}