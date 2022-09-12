/*Function: Main
*---------------
*Inputs the number of rows and columns for the matrices
*Inputs the elements of each matrix
*Function calls m_add to add the two matrices
*
*col: columns of each matrix
*row: rows of each matrix
*first: first matrix
*second: second matrix
*
*-----------------
*Function: m_add
*-----------------
*Given the two matrices, m_add will add them together
*The function will print out the elements of the added matrix
*
*input: first, second
*returns final: final matrix after the matrix addition
*
*/

//header file
#include <stdio.h>

//declaration of matrix adding function
//using pointers to call the matrices
void m_add(int row, int col, int *m1, int *m2, int *final);

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
    int first[row][col], second[row][col], final[row][col];

    //request for second matrix elements
    printf("Enter the first matrix elements: \n");
    //for loop for row
    for(i = 0; i < row; i++)
    {
        //for loop for column
        for(j = 0; j < col; j++)
        {
            //scan first matrix elements
            scanf("%d", &first[i][j]);
        }
    }

    //request for second matrix elements
    printf("Enter the second matrix elements: \n");
    //for loop for row
    for(i = 0; i < row; i++)
    {
        //for loop for column
        for(j = 0; j < col; j++)
        {
            //scan second matrix elements
            scanf("%d", &second[i][j]);
        }
    }

    //add the matrices
    m_add(row, col, (int*) first, (int*) second, (int*) final);

    //print out the final matrix
    printf("Addition of the matrices: \n");
    //for loop for row
    for(i = 0; i < row; i++)
    {
        //for loop for column
        for(j = 0; j < col; j++)
        {
            //print out the final matrix elements
            printf("%d ", final[i][j]);
        }
        printf("\n");
    }
}

//definition of m_add function
void m_add(int row, int col, int *m1, int *m2, int *final)
{
    //declare variables;
    int i, j;

    //for loop to allocate each added value to the total matrix
    //for loop for row
    for(i = 0; i < row; i++)
    {
        //for loop for column
        for(j = 0; j < col; j++) 
        {
            //equate each addition and allocate to the addresses of the final matrix
            *((final + i * col) + j) = *((m1 + i * col) + j) + *((m2 + i * col) + j);
        }
    }
}