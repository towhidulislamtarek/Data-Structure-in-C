#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    float float_data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x, float y)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->float_data = y;
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
            printf("%d, %.2f -> ", temp->data, temp->float_data);
            temp = temp->next;
        }
        printf("NULL\n");
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
        printf("%d, %.2f\n", front->data, front->float_data);
    }
}

int main()
{
    enqueue(1, 1.1);
    enqueue(2, 2.2);
    enqueue(3, 3.3);
    enqueue(4, 4.4);
    enqueue(5, 5.5);
    enqueue(6, 6.6);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    peek();

    return 0;
}
