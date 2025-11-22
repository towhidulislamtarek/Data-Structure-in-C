#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getheight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
        return 0;
    return getheight(n->left) - getheight(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return createnode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(getheight(node->left), getheight(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf = getbalancefactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotation needed
    return node;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);

    printf("Preorder traversal of the AVL tree is: \n");
    preorder(root);

    return 0;
}
