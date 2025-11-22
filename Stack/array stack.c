#include <stdio.h>
#include <stdlib.h>                            

#define MAX 5
int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
}

int pop()
{
    int value;

    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }

    value = stack_arr[top];
    top--;
    return value;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack_arr[top];
}

void print()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack_arr[i]);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Stack elements:\n");
    print();

    printf("Top element of the stack: %d\n", peek());

    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
    printf("Popping an element: %d\n", pop());
   
    return 0;
}
