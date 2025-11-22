#include <stdio.h>
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = &a[3];

    printf("First pointer is: %d\n", *(ptr));
    printf("2nd pointer is: %d\n", *(ptr + 1));
}