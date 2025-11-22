#include <stdio.h>
#include <stdlib.h>
#define n 6

int queue[n];
int funt = -1;
int real = -1;

void enqueue(int x)
{
    if (real == n - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    else if (funt == -1 && real == -1)
    {
        funt = real = 0;
        queue[real] = x;
    }
    else
    {
        real++;
        queue[real] = x;
    }
}

void dequeue()
{
    if (funt == -1 && real == -1)
    {
        printf("Underflow\n");
        return;
    }
    else if (funt == real)
    {
        printf("%d dequeued\n", queue[funt]);
        funt = real = -1;
    }
    else
    {
        printf("%d dequeued\n", queue[funt]);
        funt++;
    }
}

void display()
{
    if (funt == -1 && real == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = funt; i <= real; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peek()
{

    printf("The peek is %d\n", queue[funt]);
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
