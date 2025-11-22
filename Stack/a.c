#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    char str;
    struct Node *next;
};

struct Node *createNode(int data, char *str)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->str = strdup(str);
    newNode->next = NULL;
    return newNode;
}

struct Node *top = NULL;

void push(int int_data, char *str)
{
    struct Node *newNode = createNode(int_data, char *str);
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    printf("Popped element: (%d, %.2f)\n", temp->int_data, temp->float_data);
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element of the stack: (%d, %.2f)\n", top->int_data, top->float_data);
}

void display()
{
    struct Node *current = top;
    if (current == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (current != NULL)
    {
        printf("(%d, %.2f)\n", current->int_data, current->float_data);
        current = current->next;
    }
}

int main()
{

    push(10, 3.14);
    push(20, 4.5);
    push(30, 6.7);
    push(40, 8.9);
    push(50, 10.1);

    peek();

    display();

    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}
