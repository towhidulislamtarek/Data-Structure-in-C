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
    struct node *body = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = NULL;

    body = (struct node *)malloc(sizeof(struct node));
    body->data = 9;
    body->next = NULL;

    head->next = body;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 10;
    tail->next = NULL;

    body->next = tail;

    struct node *prev = NULL;
    struct node *current = head;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    if (prev != NULL)
    {
        free(current);
        prev->next = NULL;
    }
    else
    {
        free(head);
        head = NULL;
    }

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}
