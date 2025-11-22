#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    char *str;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x, char *s)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->str = strdup(s); // Allocating memory for the string and copying it
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("(%d, %s) ", temp->data, temp->str);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        free(temp->str); // Freeing memory allocated for the string
        free(temp);
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("(%d, %s) ", front->data, front->str);
    }
}

int main()
{
    enqueue(1, "One");
    enqueue(2, "Two");
    enqueue(3, "Three");
    enqueue(4, "Four");
    enqueue(5, "Five");

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    peek();

    return 0;
}
