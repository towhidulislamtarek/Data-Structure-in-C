#include <stdio.h>
int main()
{
    int roll[10];

    for (int i = 0; i < 10; i++)
        scanf("%d", &roll[i]);

    for (int i = 0; i < 10; i++)
    {
        printf("%d", roll[i]);
    }

    return 0;
}