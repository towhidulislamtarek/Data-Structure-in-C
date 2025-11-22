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
    struct node *pvrt;
};

int main()
{
    struct node *one = NULL;
    struct node *secend = NULL;
    struct node *thard = NULL;

    one = (struct node *)malloc(sizeof(struct node));
    one->data = 15;
    one->float_data = 12.34;
    one->char_data = 'A';
    one->string_data = strdup("Hello");
    one->next = NULL;
    one->pvrt = NULL;

    secend = (struct node *)malloc(sizeof(struct node));
    secend->data = 20;
    secend->float_data = 23.45;
    secend->char_data = 'B';
    secend->string_data = strdup("World");
    secend->next = NULL;
    secend->pvrt = NULL;

    thard = (struct node *)malloc(sizeof(struct node));
    thard->data = 30;
    thard->float_data = 34.56;
    thard->char_data = 'C';
    thard->string_data = strdup("OpenAI");
    thard->next = NULL;
    thard->pvrt = NULL;

    one->next = secend;
    secend->pvrt = one;
    secend->next = thard;
    thard->pvrt = secend;

    struct node *td = NULL;
    td = (struct node *)malloc(sizeof(struct node));
    td->data = 12;
    td->float_data = 45.67;
    td->char_data = 'D';
    td->string_data = strdup("ChatGPT");
    td->next = NULL;
    td->pvrt = NULL;

    td->next = one;
    one->pvrt = td;

    struct node *head = td;

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%.2f\n", ptr->float_data);
        printf("%c\n", ptr->char_data);
        printf("%s\n", ptr->string_data);
        ptr = ptr->next;
    }

    printf("\n");

    ptr = thard;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%.2f\n", ptr->float_data);
        printf("%c\n", ptr->char_data);
        printf("%s\n", ptr->string_data);
        ptr = ptr->pvrt;
    }

    return 0;
}
