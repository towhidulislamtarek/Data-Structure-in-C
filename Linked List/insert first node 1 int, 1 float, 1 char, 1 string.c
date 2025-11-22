#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    float float_data;
    char char_data;
    char *string_data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *body = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->float_data = 10.5;
    head->char_data = 'A';
    head->string_data = strdup("Hello");
    head->next = NULL;

    body = (struct node *)malloc(sizeof(struct node));
    body->data = 10;
    body->float_data = 20.7;
    body->char_data = 'B';
    body->string_data = strdup("World");
    body->next = NULL;

    head->next = body;

    tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 15;
    tail->float_data = 30.9;
    tail->char_data = 'C';
    tail->string_data = strdup("OpenAI");
    tail->next = NULL;

    body->next = tail;

    struct node *first = NULL;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = 34;
    first->float_data = 40.3;
    first->char_data = 'D';
    first->string_data = strdup("ChatGPT");
    first->next = head;

    head = first;

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%.2f\n", ptr->float_data);
        printf("%c\n", ptr->char_data);
        printf("%s\n", ptr->string_data);
        ptr = ptr->next;
    }

    return 0;
}
