#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    float data1;
    char data2;
    char *string_data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *body = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 12;
    head->data1 = 12.34;
    head->data2 = 'A';
    head->string_data = strdup("Hello");
    head->next = NULL;

    body = (struct node *)malloc(sizeof(struct node));
    body->data = 15;
    body->data1 = 23.45;
    body->data2 = 'B';
    body->string_data = strdup("World");
    body->next = NULL;

    head->next = body;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 14;
    tail->data1 = 34.56;
    tail->data2 = 'C';
    tail->string_data = strdup("Foo");
    tail->next = NULL;

    body->next = tail;

    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = 12;
    new_node->data2 = 58.44;
    new_node->data2 = 'g';
    new_node->string_data = strdup("jdla");
    new_node->next = NULL;

    struct node *ptr = head;
    while (ptr->next != NULL && ptr->data != 15)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%.2f\n", ptr->data1);
        printf("%c\n", ptr->data2);
        printf("%s\n", ptr->string_data);
        ptr = ptr->next;
    }

       return 0;
}
