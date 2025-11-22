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

    struct node *extra1 = (struct node *)malloc(sizeof(struct node));
    extra1->data = 20;
    extra1->data1 = 45.67;
    extra1->data2 = 'D';
    extra1->string_data = strdup("Bar");
    extra1->next = NULL;

    tail->next = extra1;

    struct node *extra2 = (struct node *)malloc(sizeof(struct node));
    extra2->data = 25;
    extra2->data1 = 56.78;
    extra2->data2 = 'E';
    extra2->string_data = strdup("Baz");
    extra2->next = NULL;

    extra1->next = extra2;

    struct node *extra3 = (struct node *)malloc(sizeof(struct node));
    extra3->data = 30;
    extra3->data1 = 67.89;
    extra3->data2 = 'F';
    extra3->string_data = strdup("Qux");
    extra3->next = NULL;

    extra2->next = extra3;

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%.2f\n", ptr->data1);
        printf("%c\n", ptr->data2);
        printf("%s\n", ptr->string_data);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr != NULL)
    {
        free(ptr->string_data);
        ptr = ptr->next;
    }
    return 0;
}
