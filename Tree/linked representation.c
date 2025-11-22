#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

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

    struct node *p5 = NULL;
    p5 = (struct node *)malloc(sizeof(struct node));
    p5->data = 3;
    p5->left = NULL;
    p5->right = NULL;

    struct node *p6 = NULL;
    p6 = (struct node *)malloc(sizeof(struct node));
    p6->data = 4;
    p6->left = NULL;
    p6->right = NULL;

    p2->left = p5;
    p2->right = p6;

    printf("Root: %d\n", p->data);
    printf("Left child of root: %d\n", p->left->data);
    printf("Right child of root: %d\n", p->right->data);
    printf("Left child of left child of root: %d\n", p->left->left->data);
    printf("Right child of left child of root: %d\n", p->left->right->data);
    printf("Left child of right child of root: %d\n", p->right->left->data);
    printf("Right child of right child of root: %d\n", p->right->right->data);


    return 0;
}
