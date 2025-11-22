#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int key)
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node **root, int key)
{
    struct node *prev = NULL;
    struct node *temp = *root;

    while (temp != NULL)
    {
        prev = temp;
        if (key == temp->data)
        {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    struct node *newNode = createnode(key);
    if (prev == NULL)
    {
        *root = newNode;
    }
    else if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // search for the node to be deleted
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        struct node *ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

void removeTree(struct node *root)
{
    if (root == NULL)
        return;
    removeTree(root->left);
    removeTree(root->right);
    free(root);
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

    insert(&p, 7);
    printf("%d\n", p->right->right->data);

    removeTree(p); // Free the memory allocate
    return 0;
}
