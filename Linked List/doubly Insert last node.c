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
    struct node *head = NULL;
    struct node *body = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->prev = NULL;
    head->next = NULL;

    body = (struct node *)malloc(sizeof(struct node));
    body->data = 10;
    body->prev = NULL;
    body->next = NULL;

    head->next = body;
    body->prev = head;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 15;
    tail->prev = NULL;
    tail->next = NULL;

    body->next = tail;
    tail->prev = body;

    struct node *last = NULL;
    last = (struct node *)malloc(sizeof(struct node));
    last->data = 22;
    last->prev = NULL;
    last->next = NULL;

    tail->next = last;
    last->prev = tail;

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = last;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr= ptr->prev;
    }

    return 0;
}
