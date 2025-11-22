#include <stdio.h>
#include <stdlib.h>

struct node *createlinkedlist(int arr[], int size);
void print(struct node *head);
struct node *delete(struct node *head, int data);
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int a[] = {15, 30, 45, 60, 100};
    struct node *head = NULL;
    head = createlinkedlist(a, 5);
    print(head);

    struct node *newHead = delete (head, 30);

    print(newHead);
    return 0;
}

struct node *delete(struct node *head, int data)
{
    struct node *dumyHead = (struct node *)malloc(sizeof(struct node));
    dumyHead->next = head;
    struct node *temp = dumyHead;

    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            // delete logic
            temp->next = temp->next->next;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    return dumyHead->next;
}

struct node *createlinkedlist(int arr[], int size)
{
    struct node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }

        else
        {
            current->next = temp;
            current = current->next;
        }
    }

    return head;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}