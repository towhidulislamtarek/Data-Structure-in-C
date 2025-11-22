#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *current = NULL;
    struct node *temp = NULL;

    int a[5] = {5, 6, 7, 8, 9};
    int i;

    for (i = 0; i < 5; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }

        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
