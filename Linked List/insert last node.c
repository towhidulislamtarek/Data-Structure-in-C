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
    head->data = 5;
    head->next = NULL;

    body = (struct node *)malloc(sizeof(struct node));
    body->data = 10;
    body->next = NULL;

    head->next = body;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 15;
    tail->next = NULL;

    body->next = tail;

    struct node *last = NULL;
    last = (struct node *)malloc(sizeof(struct node));
    last->data = 22;
    last->next = NULL;

    tail->next = last;

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
