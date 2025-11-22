#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{

    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = 10;
    first->next = NULL;
    first->prev = NULL;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = 20;
    second->next = NULL;
    second->prev = first;
    first->next = second;

    third = (struct node *)malloc(sizeof(struct node));
    third->data = 30;
    third->next = NULL;
    third->prev = second;
    second->next = third;

    printf("Original linked list:\n");
    struct node *current = first;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    current = first;
    while (current != NULL && current->data != 20)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        free(current);
    }
    printf("Linked list after removing middle node:\n");
    current = first;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
