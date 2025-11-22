#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
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
    body->prev = head;
    body->next = NULL;
    head->next = body;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 15;
    tail->prev = body;
    tail->next = NULL;
    body->next = tail;

    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = 12;

    struct node *ptr = head;
    while (ptr->next != NULL && ptr->data != 10)
    {
        ptr = ptr->next;
    }

    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = tail;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }

    return 0;
}
