#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int inbest(struct node *root, struct node **prevt)
{
    if (root != NULL)
    {
        if (!inbest(root->left, prevt))
        {
            return 0;
        }
        if (*prevt != NULL && root->data <= (*prevt)->data)
        {
            return 0;
        }
        *prevt = root;
        return inbest(root->right, prevt);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key == root->data)
    {
        return root;
    }

    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    struct node *p = NULL;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 5;
    p->left = NULL;
    p->right = NULL;

    struct node *p1 = NULL;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 3;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2 = NULL;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 6;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

    struct node *p3 = NULL;
    p3 = (struct node *)malloc(sizeof(struct node));
    p3->data = 1;
    p3->left = NULL;
    p3->right = NULL;

    struct node *p4 = NULL;
    p4 = (struct node *)malloc(sizeof(struct node));
    p4->data = 4;
    p4->left = NULL;
    p4->right = NULL;

    p1->left = p3;
    p1->right = p4;

    struct node *prevt = NULL;
    printf("Is it a binary search tree? %d\n", inbest(p, &prevt));

    struct node *n = search(p, 7);
    if (n != NULL)
    {
        printf("Found: %d\n", n->data);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}