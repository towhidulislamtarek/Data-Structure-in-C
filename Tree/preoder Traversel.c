#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *p = NULL;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    struct node *p1 = NULL;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2 = NULL;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

    struct node *p3 = NULL;
    p3 = (struct node *)malloc(sizeof(struct node));
    p3->data = 11;
    p3->left = NULL;
    p3->right = NULL;

    struct node *p4 = NULL;
    p4 = (struct node *)malloc(sizeof(struct node));
    p4->data = 12;
    p4->left = NULL;
    p4->right = NULL;

    p1->left = p3;
    p1->right = p4;

    printf("Preorder traversal:");
    preorder(p);

    return 0;
}