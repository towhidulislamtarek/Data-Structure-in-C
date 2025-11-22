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

    struct node *head = NULL;
    head = one;

    struct node *ptr;
    ptr = head;

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
