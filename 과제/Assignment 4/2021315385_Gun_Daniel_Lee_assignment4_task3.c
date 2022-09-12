/*Function: main
*---------------------------------
*Mainly used to function call and print final output
*
*Function call on inputinfo
*inputinfo: request and scan employee information
*
*Function call on totalmoney
*totalmoney: sum of all the employee's salaries
*
*Function call on maxsalary
*maxsalary: finds the employee with the highest salary
*
*Function call on minsalary
*minsalary: finds the employee with the lowest salary
*
*prints out the final output
*/

/*Function: inputinfo
*--------------------------------
*Request for all the employee's information
*
*uses for loop and scanf to request input
*/

/*Function: totalmoney
*--------------------------------
*Adds all the employee's salary
*
*total = sum of all the employee's salary
*/

/*Function: maxsalary
*--------------------------------
*Finds the index of the employee with the highest salary
*
*uses for loop
*max = index of the employee with the highest salary
*compares new employee's salary with the current max employee's salary
*if new employee has a higher salary, function will update the max index
*
*return max index
*/

/*Function: minsalary
*--------------------------------
*Finds the index of the employee with the lowest salary
*
*uses for loop
*min = index of the employee with the lowest salary
*compares new employee's salary with the current min employee's salary
*if new employee has a lower salary, function will update the min index
*
*return min index
*/

//header files
#include <stdio.h>
//define the max number of employees which is 4 for this task
#define MAX 4

//define the employee structure
typedef struct
{
    int ID;
    char name[50];
    float salary;
}employee;

//declare the functions
void inputinfo(employee name[MAX]);
float totalmoney(employee name[MAX]);
int maxsalary(employee name[MAX]);
int minsalary(employee name[MAX]);


//main function
int main()
{
    //declare variables
    employee name[MAX];
    float total;
    int max, min;

    //function call on inputinfo
    inputinfo(name);
    
    //function call on totalmoney and save it in total variable
    total = totalmoney(name);

    //function call on maxsalary and save it in max variable
    max = maxsalary(name);

    //function call on minsalary and save it in min variable
    min = minsalary(name);

    //print out the final output
    printf("Statistics\n\n");

    //print the total amount of salary for all the employees
    printf("Total amount of money for employees: %.2f\n\n", total);

    //print out the information of the employee with the max salary
    printf("Maximum Salary:\n");
    printf("ID: %d\n", name[max].ID);
    printf("Name: %s\n", name[max].name);
    printf("Salary: %.2f\n\n", name[max].salary);

    //print out the information of the employee with the min salary
    printf("Minimum Salary:\n");
    printf("ID: %d\n", name[min].ID);
    printf("Name: %s\n", name[min].name);
    printf("Salary: %.2f\n", name[min].salary);

    return 0;
}

//inputinfo function
void inputinfo(employee name[MAX])
{
    //declare variables
    int i;

    //for loop to input all the needed information
    for(i = 0; i < MAX; i++)
    {
        //request for all the information for each employee
        printf("ID: ");
        scanf("%d", &name[i].ID);
        printf("Name: ");
        scanf("%s", name[i].name);
        printf("Salary: ");
        scanf("%f", &name[i].salary);
        printf("\n");
    }
}

//totalmoney function
float totalmoney(employee name[MAX])
{
    //declare variables
    float total = 0;
    int i;

    //for loop to find all the salary information for each employee through the index
    for(i = 0; i < MAX; i++)
    {
        //add each employee's salary to the total
        total += name[i].salary;
    }

    //return the total amount as a float
    return total;
}

//maxsalary function
int maxsalary(employee name[MAX])
{
    //declare variables; max = index of the employee with maximum salary
    int i, max = 0;

    //for loop to find the employee with the highest salary
    for(i = 1; i < MAX; i++)
    {
        //if statement to compare a employee's salary to the current employee with the most salary
        if(name[i].salary > name[max].salary)
        {
            //if the current employee has a higher salary, the max index will be updated
            max = i;
        }
    }

    //return the max index
    return max;
}


//minsalary function
int minsalary(employee name[MAX])
{
    //declare variables
    int i, min = 0;

    //for loop to find the employee with the lowest salary
    for(i = 1; i < MAX; i++)
    {
        //if statement to compare a employee's salary to the current employee with the least salary
        if(name[i].salary < name[min].salary)
        {
            //if the current employee has a lower salary, the min index will be updated
            min = i;
        }
    }
    
    //return the min index
    return min;
}