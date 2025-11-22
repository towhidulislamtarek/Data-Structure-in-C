#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pvrt;
};

int main()
{
    struct node *one = NULL;
    struct node *secend = NULL;
    struct node *thard = NULL;

    one = (struct node *)malloc(sizeof(struct node));
    one->data = 15;
    one->next = NULL;
    one->pvrt = NULL;

    secend = (struct node *)malloc(sizeof(struct node));
    secend->data = 20;
    secend->next = NULL;
    secend->pvrt = NULL;

    thard = (struct node *)malloc(sizeof(struct node));
    thard->data = 30;
    thard->next = NULL;
    thard->pvrt = NULL;

    one->next = secend;
    secend->pvrt = one;
    secend->next = thard;
    thard->pvrt = secend;

    struct node *td = NULL;
    td = (struct node *)malloc(sizeof(struct node));
    td->data = 12;
    td->next = NULL;
    td->pvrt = NULL;

    td->next = one;
    one->pvrt = td;

    struct node *head = td;

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = thard;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->pvrt;
    }

    return 0;
}
