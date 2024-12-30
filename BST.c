#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
} *root = NULL, *par = NULL, *leaf, *new, *temp;

void insert();
void display();
void inOrder(struct node *root);
struct node *deleteNode(struct node *root, int key);
struct node *findMin(struct node *root);

void main()
{
    int ch, is_executing = 1, key;
    while (is_executing == 1)
    {
        printf("Binary Search Tree Operations:\n1.Insertion\n2.Display\n3.Deletion\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 4:
            is_executing = 0;
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}

void insert()
{
    new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->right = NULL;
    printf("Enter the element to be inserted:");
    scanf("%d", &new->data);
    if (root == NULL)
    {
        root = new;
        return;
    }
    leaf = root;
    while (leaf != NULL)
    {
        par = leaf;
        if (new->data < leaf->data)
        {
            leaf = leaf->left;
        }
        else
        {
            leaf = leaf->right;
        }
    }
    if (par->data > new->data)
    {
        par->left = new;
    }
    else
    {
        par->right = new;
    }
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void display()
{
    if (root == NULL)
    {
        printf("The BST is empty.\n");
        return;
    }
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");
}

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("The element %d is not an element in the Binary Search Tree.\n", key);
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
