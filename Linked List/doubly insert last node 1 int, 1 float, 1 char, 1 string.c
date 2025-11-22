#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data_int;
    float data_float;
    char data_char;
    char *data_string;
    struct node *next;
    struct node *prev;
};

int main()
{

    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data_int = 5;
    head->data_float = 12.34;
    head->data_char = 'A';
    head->data_string = strdup("Hello");
    head->next = NULL;
    head->prev = NULL;

    struct node *body = NULL;
    body = (struct node *)malloc(sizeof(struct node));
    body->data_int = 10;
    body->data_float = 23.45;
    body->data_char = 'B';
    body->data_string = strdup("Jabid");
    body->next = NULL;
    body->prev = NULL;

    head->next = body;
    body->prev = head;

    struct node *tail = NULL;
    tail = (struct node *)malloc(sizeof(struct node));
    tail->data_int = 15;
    tail->data_float = 34.56;
    tail->data_char = 'C';
    tail->data_string = strdup("kalsar");
    tail->next = NULL;
    tail->prev = NULL;

    body->next = tail;
    tail->prev = body;

    struct node *last = NULL;
    last = (struct node *)malloc(sizeof(struct node));
    last->data_int = 22;
    last->data_float = 45.67;
    last->data_char = 'D';
    last->data_string = strdup("sara");
    last->next = NULL;
    last->prev = NULL;

    tail->next = last;
    last->prev = tail;

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n ", ptr->data_int);
        printf("%.2f\n ", ptr->data_float);
        printf("%c\n ", ptr->data_char);
        printf("%s\n", ptr->data_string);
        ptr = ptr->next;
    }
    printf("\n");

    ptr = last;
    while (ptr != NULL)
    {
        printf("%d\n ", ptr->data_int);
        printf("%.2f\n ", ptr->data_float);
        printf("%c\n ", ptr->data_char);
        printf("%s\n", ptr->data_string);
        ptr = ptr->prev;
    }

    return 0;
}
