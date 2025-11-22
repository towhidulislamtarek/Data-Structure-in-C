#include<stdio.h>
int main()
{
    int arr[100];
    int i,n;

    printf("Enter this element: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("%u\n",&arr[i]);
    }

}