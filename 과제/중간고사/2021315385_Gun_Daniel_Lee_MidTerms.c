/*Function: main
*---------------------------------------------------
*Function calls on all the functions needed in this project.
*
*Requests for basic information
*SID = student ID
*name = Student's full name
*c_num = number of courses
*
*function call on all the functions
*getinfo = get course information
*printinfo = print course information
*Gradeweightconvert = convert student grades to their grade weights
*GPAcalc = calculate the student GPA
*lowestcourse = finds lowest grade among the courses and suggest improvements
*/

/*Function: getinfo
*---------------------------------------------------
*Gets all the information needed for each course using scanf
*
*Uses the struct course variable to save and retrieve information quickly
*Uses for loop to scanf n times; n = number of courses
*/

/*Function: printinfo
*---------------------------------------------------
*Prints out all the information taken from main and getinfo
*Uses for loop to printf n times; n = number of courses
*Uses the macro function PRINTINFO
*
*PRINTINFO: prints out all the course information except for type (for future convenience purposes)
*/

/*Function: Gradeweightconvert
*---------------------------------------------------
*Converts the Grades into their corresponding grade weights
*
*Uses for loop to go through each array variable in the struct course variable
*Uses switch-case statement to convert 'A','B','C','D','F' to their corresponding values 4,3,2,1,0
*Uses an if-else statement within the switch-case statement to convert the '+' into an additional 0.5 to the grade weight
*/

/*Function: GPAcalc
*---------------------------------------------------
*Solves for the GPA given the grade weights and Credits
*
*GPA = total grade points / total credits
*total grade points = sum of grade weight * corresponding credits
*/

/*Function: lowestcourse
*---------------------------------------------------
*Finds the course with lowest grade
*If there are several courses with the lowest grade, the function will choose the one with the highest credits
*If there are several courses with the lowest grade and the same credits, the function will randomize one of these courses
*
*Uses for loop to compare the variables one by one
*Uses if-else statments to find the lowest grade
*Prints out the lowest course information
*/


//header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//defining integers, MAXCOURSE is used for the max number of courses per semester(approximately 8), MAX defines the max number of characters in each string/ array
#define MAXCOURSE 8
#define MAX 1000
//defining a macro function to print out course information
#define COURSEINFO(i)  printf("Course Code: %s\n", course[i].code); printf("Course Name: %s\n", course[i].name); printf("Course Grade: %s\n", course[i].grade); printf("Course Credits: %d\n", course[i].creds);

//declare a new structure named course; this variable will contain all the variables needed for each course
struct course
{
    char code[MAX], name[MAX], grade[MAX], type[MAX];
    int creds;
    float gradeweight;
};

//declaration of all the functions
void getinfo(int num, struct course course[]);
void printinfo(int sID, char name[], int num, struct course course[]);
void Gradeweightconvert(int num, struct course course[]);
float GPAcalc(int num, struct course course[]);
void lowestcourse(int num, struct course course[]);

//main function
void main()
{
    //declare variables
    int sID, c_num;
    char name[MAX];
    float GPA;
    struct course course[MAXCOURSE];

    //request for student ID(sID) input
    printf("Enter student ID: ");
    scanf("%d", &sID);

    //request for Full name input
    printf("Enter full name: ");
    scanf(" %[^\n]s", name);
    
    //request for number of courses input
    printf("Enter number of enrolled courses: ");
    scanf("%d", &c_num);

    //function call on getting all the course informations
    getinfo(c_num, course);

    //function call on printing all the given information
    printinfo(sID, name, c_num, course);

    //function call on converting letter grades to their grade weights
    Gradeweightconvert(c_num, course);

    //function call on calculating the GPA
    //save the return value of the function to GPA variable
    GPA = GPAcalc(c_num, course);
    printf("Overall GPA for the semester: %.2f\n\n", GPA);

    //function call on finding the lowest course and printing the information
    lowestcourse(c_num, course);
}


//getinfo function
void getinfo(int num, struct course course[])
{
    //declare variables
    int i;

    //for loop to get course information
    for (i = 0; i < num; i++)
    {
        printf("\n");

        printf("Enter the information of the course %d:\n\n", i + 1);

        //course code input
        printf("Course Code: ");
        scanf(" %[^\n]s", course[i].code);
        
        //course name input
        printf("Course Name: ");
        scanf(" %[^\n]s", course[i].name);
        
        //course grade input
        printf("Course Grade: ");
        scanf("%s", course[i].grade);

        //course credit input
        printf("Course Credits: ");
        scanf("%d", &course[i].creds);
        
        //course type input
        printf("Course Type: ");
        scanf(" %s", course[i].type);
    }
}


//printinfo function
void printinfo(int sID, char name[], int num, struct course course[])
{
    //declare variables
    int i;

    //print the general information
    printf("\nStudent ID: %d\n", sID);
    printf("Student name: %s\n", name);
    printf("Number of enrolled courses: %d\n\n", num);

    //print all the course information
    printf("Courses:\n\n");
    //use for loop to go through all the courses in the struct course array []
    for (i = 0; i < num; i++)
    {
        //print out the course information using macros
        COURSEINFO(i);
        
        printf("Course Type: %s\n\n", course[i].type);
    }
}

//Gradeweightconvert function
void Gradeweightconvert(int num, struct course course[])
{
    //declare variables
    int i = 0;

    //find grade weight of each course and save them in the variable gradeweight
    for (i = 0; i < num; i++)
    {
        //switch-case statement to equate the grades to their grade weights
        switch(course[i].grade[0])
        {
            case 'A':
                //if statement to check whether the grades have a '+' beside them
                if(course[i].grade[1] == '+')
                {
                    course[i].gradeweight = 4.5;
                }
                else
                {
                    course[i].gradeweight = 4;
                }
                break;
            case 'B':
                //if statement to check whether the grades have a '+' beside them
                if(course[i].grade[1] == '+')
                {
                    course[i].gradeweight = 3.5;
                }
                else
                {
                    course[i].gradeweight = 3;
                }
                break;
            case 'C':
                //if statement to check whether the grades have a '+' beside them
                if(course[i].grade[1] == '+')
                {
                    course[i].gradeweight = 2.5;
                }
                else
                {
                    course[i].gradeweight = 2;
                }
                break;
            case 'D':
                //if statement to check whether the grades have a '+' beside them
                if(course[i].grade[1] == '+')
                {
                    course[i].gradeweight = 1.5;
                }
                else
                {
                    course[i].gradeweight = 1;
                }
                break;
            case 'F':
                course[i].gradeweight = 0;
                break;
        }

    }
}

//GPAcalc function
float GPAcalc(int num, struct course course[])
{
    //declare variables
    int i;
    float total = 0, totalcreds = 0, GPA = 0;

    //for loop to get the total grade points and total credits
    for(i = 0; i < num; i++)
    {
        //grade points = the sum of the product of the grade weight and its corresponding credits for each course
        total = total + course[i].gradeweight * course[i].creds;
        totalcreds = totalcreds + course[i].creds;
    }

    //solve for the GPA by dividing the total grade points by the total credits
    GPA = total / totalcreds;
    //return the float GPA variable
    return GPA;
}

//lowestcourse function
void lowestcourse(int num, struct course course[])
{
    //declare variables
    int i, j, coursenum;

    //use time as the random seed
    srand(time(0));
    //for loops to compare the course grades using gradeweight
    for(i = 0; i < num; i++)
    {
        for(j = i + 1; j < num; j++)
        {
            //if case where first course is lower than the second
            if(course[i].gradeweight < course[j].gradeweight)
            {
                //initially saves the first course number in the variable
                coursenum = i;
            }
            //second if case where second course is lower than the first
            else if(course[i].gradeweight > course[j].gradeweight)
            {
                //initially saves the second course number in the variable
                coursenum = j;
            }
            //third if case where first and second course are equal
            else if(course[i].gradeweight == course[j].gradeweight)
            {
                //if statement where the first course has higher credits
                if(course[i].creds > course[j].creds)
                {
                    //initially saves the first course number in the variable
                    coursenum = i;
                }
                //if statement where the second course has higher credits
                else if(course[i].creds < course[j].creds)
                {
                    //initially saves the second course number in the variable
                    coursenum = j;
                }
                //if statement where both courses have identical credits
                else if(course[i].creds == course[j].creds)
                {
                    //using a random function to choose one of the two courses
                    //if the random value is even
                    if(rand() % 2 == 0)
                    {
                        //the function will choose the first course
                        coursenum = i;
                    }
                    //if the random value is odd
                    else
                    {
                        //the function will choose the second course
                        coursenum = j;
                    }
                }
            }
        }
    }

    //print out the information of the lowest course
    printf("You should focus on the following course:\n\n");
    COURSEINFO(coursenum);
}