#include <stdio.h>
#define N 3
#define M 4

int main()
{
    int arr[N][M];
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }

    }


    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            printf("%5d", arr[i][j]); //%5d meaning there will be 5 digit spaces before each integer value

        }
        printf("\n");
    }
    return 0;
}