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
    struct node *body1 = NULL;
    struct node *body2 = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = NULL;

    body1 = (struct node *)malloc(sizeof(struct node));
    body1->data = 9;
    body1->next = NULL;

    head->next = body1;

    body2 = (struct node *)malloc(sizeof(struct node));
    body2->data = 11;
    body2->next = NULL;

    body1->next = body2;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 10;
    tail->next = NULL;

    body2->next = tail;

    struct node *del1;
    struct node *del2;

    del1 = head;
    del2 = head;

    int pos = 3, i=1;
    while (i < 3)
    {
        del1 = del2;
        del2 = del2->next;
        i++;
    }

    del1->next = del2->next;
    free(del2);

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
