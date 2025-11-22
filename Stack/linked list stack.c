#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(int data)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack overflow");
        return;
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int val;
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack underflow.");
        return -1;
    }

    return top->data;
}

void print()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("Stack underflow.");
        return;
    }

    printf("The stack elements: ");

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Stack elements: ");
    print();

    printf("Top element of the stack: %d\n", peek());

    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());

    return 0;
}
