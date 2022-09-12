#include <stdio.h>

int main()
{
    int i, j;
    //arr[i][j] = element at row i, column j
    int arr[4][5] = {{10, 5, -3, 17, 82},       //matrix, 4 rows, 5 columns
                     {9, 0, 0, 8, -7},
                     {32, 20, 1, 0, 14},
                     {0, 0, 8, 7, 6}};

    //this works as well int arr[4][5] = {10, 5, -3, 17, 82, 9, 0, 0, 8, -7, 32, 20, 1, 0, 14, 0, 0, 8, 7, 6};
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}