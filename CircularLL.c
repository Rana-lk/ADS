#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head = NULL, *temp, *newnode;

void insertBeg();
void insertEnd();
void insertPos();
void display();
void deleteNode();

void main()
{
    int ch;
    while (1)
    {
        printf("Circular Linked List Operations:\n");
        printf("1. Insertion at the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion at any position\n");
        printf("4. Display\n");
        printf("5. Deletion\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            display();
            break;
        case 5:
            deleteNode();
            break;
        case 6:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void insertBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        newnode->link = head;
    }
    else
    {
        temp = head;
        while (temp->link != head)
            temp = temp->link;
        newnode->link = head;
        head = newnode;
        temp->link = head;
    }
    printf("Element inserted at the beginning.\n");
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        newnode->link = head;
    }
    else
    {
        temp = head;
        while (temp->link != head)
            temp = temp->link;
        temp->link = newnode;
        newnode->link = head;
    }
    printf("Element inserted at the end.\n");
}

void insertPos()
{
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);

    if (pos == 1 || head == NULL)
    {
        insertBeg();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp->link != head; i++)
        temp = temp->link;

    if (temp->link == head && pos > 1)
    {
        printf("Position exceeds the size of the list. Adding at the end.\n");
        insertEnd();
        return;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    printf("Element inserted at position %d.\n", pos);
}

void display()
{
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }
    temp = head;
    printf("The circular linked list is: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("\n");
}

void deleteNode()
{
    int pos;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);
    if (head == NULL || pos < 1)
    {
        printf("Invalid position or the list is empty.\n");
        return;
    }
    temp = head;

    if (pos == 1)
    {
        if (head->link == head) // Single node case
        {
            free(head);
            head = NULL;
        }
        else
        {
            while (temp->link != head)
                temp = temp->link;
            struct node *delNode = head;
            head = head->link;
            temp->link = head;
            free(delNode);
        }
        printf("Element at position 1 deleted.\n");
        return;
    }

    for (int i = 1; i < pos - 1 && temp->link != head; i++)
        temp = temp->link;

    if (temp->link == head || temp->link == NULL)
    {
        printf("Position exceeds the size of the list.\n");
        return;
    }

    struct node *delNode = temp->link;
    temp->link = delNode->link;
    free(delNode);
    printf("Element at position %d deleted.\n", pos);
}
