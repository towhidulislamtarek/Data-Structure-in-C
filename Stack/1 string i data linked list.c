#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    char *str;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data, char *str)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->str = strdup(str);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d, %s\n", data, str);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d, %s\n", top->data, top->str);
    top = top->next;
    free(temp->str);
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element of the stack: %d, %s\n", top->data, top->str);
}

int main()
{
    push(10, "Hello");
    push(20, "World");
    push(30, "OpenAI");

    printf("Stack elements:\n");
    peek();

    pop();
    pop();
    pop();
    pop();

    return 0;
}
