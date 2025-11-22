#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = rear;

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
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        temp = front;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
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
        printf("%d ", front->data);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    peek();

    return 0;
}
