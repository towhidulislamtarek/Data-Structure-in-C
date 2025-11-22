#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Pushed %d into the list\n", data);
}

int pop()
{
    if (head == NULL)
    {
        printf("List is empty, cannot pop\n");
        return -1;
    }
    int data = head->data;
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    printf("Popped %d from the list\n", data);
    return data;
}

int peek()
{
    if (head == NULL)
    {
        printf("List is empty, cannot peek\n");
        return -1;
    }
    return head->data;
}

void display()
{
    printf("List elements after push operations:\n");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    printf("Top element of the list: %d\n", peek());

    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());

    return 0;
}
