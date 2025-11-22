#include <stdio.h>
int main()
{
    int j, i;
    int A[3][4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)

        {
            scanf("%d", &A[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}