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

    if (head != NULL)
    {
        struct node *del1 = head;
        head = head->next;
        free(del1);
        del1 = NULL;
    }

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");

    return 0;
}
