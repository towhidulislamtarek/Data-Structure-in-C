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

    // Allocate memory for nodes and assign data
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

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    int search_value = 10;
    ptr = head;
    struct node *search_result = NULL;

    while (ptr != NULL)
    {
        if (ptr->data == search_value)
        {
            search_result = ptr;
            break;
        }
        ptr = ptr->next;
    }

    if (search_result != NULL)
    {
        printf("Element %d found in the linked list.\n", search_value);
    }
    else
    {
        printf("Element %d not found in the linked list.\n", search_value);
    }

    return 0;
}
