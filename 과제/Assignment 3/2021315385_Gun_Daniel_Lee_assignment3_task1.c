/*Function: Main
*---------------
*Matrix Addition: Adds the two inputted matrices
*
*Inputs the number of rows and columns for the matrices
*Inputs the elements of each matrix
*Adds the two matrices using a separate function
*
*col: columns of each matrix
*row: rows of each matrix
*first: first matrix
*second: second matrix
*calls function mat_add to add and print matrix result
*
*-----------------
*Function: Mat_Add
*-----------------
*Given the two matrices, mat_add will add them together
*The function will print out the elements of the added matrix
*
*input: first, second
*returns total: final matrix after the matrix addition
*
*/

//header file
#include <stdio.h>

//declaration of matrix adding function
void mat_add(int row, int col, int *mat1, int *mat2);

void main()
{
    //declares variables
    int col, row;
    int i, j;

    //request for row input
    printf("Enter number of rows: ");
    scanf("%d", &row);

    //request for column input
    printf("Enter number of columns: ");
    scanf("%d", &col);

    //declare matrix variables using arrays
    int first[row][col], second[row][col];

    //request for first matrix elements
    printf("Enter the first matrix elements: \n");
    for(i = 0; i < row; i++)    //for loop to scan each row
    {
        for(j = 0; j < col; j++)    //for loop to scan each column
        {
            scanf("%d", &first[i][j]);  //scan function for elements
        }
    }

    //request for second matrix elements
    printf("Enter the second matrix elements: \n");
    for(i = 0; i < row; i++)    //for loop to scan each row
    {
        for(j = 0; j < col; j++)    //for loop to scan each column
        {
            scanf("%d", &second[i][j]);     //scan function for elements
        }
    }

    //function call mat_add for matrix addition
    printf("Addition of the matrices: \n");
    mat_add(row, col, (int*) first, (int*) second);
}

//definition of mat_add function
void mat_add(int row, int col, int *mat1, int *mat2)
{
    //declare variables; total variable = final matrix
    int i, j;
    int total[row][col];

    //for loop to allocate each added value to the total matrix
    //then the loop will print out each value in the matrix format
    for(i = 0; i < row; i++)    //for loop to scan each row
    {
        for(j = 0; j < col; j++)    //for loop to scan each column
        {
            total[i][j] = *((mat1 + i * col) + j) + *((mat2 + i * col) + j);    //equate each addition and allocate to total matrix
            printf("%d ", total[i][j]);     //print out the elements
        }
        printf("\n");   //used to start each row with a new line
    }
}