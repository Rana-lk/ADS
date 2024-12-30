#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL, *tail = NULL, *newNode, *temp;

void create()
{
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data: ");
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void display()
{
    int choice;
    printf("Display From\n1. Start\n2. End\nChoose: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {
            printf("%d\t", temp->data);
        }
    }
    else if (choice == 2)
    {
        for (temp = tail; temp != NULL; temp = temp->prev)
        {
            printf("%d\t", temp->data);
        }
    }
    else
    {
        printf("Invalid choice!\n");
    }
    printf("\n");
}

void insert()
{
    int choice, position;
    printf("Data to be inserted\n1. At the Top\n2. At the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &choice);
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter The Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (choice == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
    }
    else if (choice == 2)
    {
        if (tail != NULL)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &position);
        if (position < 1)
        {
            printf("Invalid position!\n");
            return;
        }
        temp = head;
        for (int i = 1; temp != NULL && i < position; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position out of range!\n");
            return;
        }
        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete()
{
    int choice, position;
    printf("Data to be Deleted\n1. From the Top\n2. From the Bottom\n3. In Between\nChoose(1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (head == NULL)
        {
            printf("List is empty!\n");
            return;
        }
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        if (head == NULL)
            tail = NULL;
    }
    else if (choice == 2)
    {
        if (tail == NULL)
        {
            printf("List is empty!\n");
            return;
        }
        temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        if (tail == NULL) //
            head = NULL;
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &position);
        if (position < 1 || head == NULL)
        {
            printf("Invalid position or empty list!\n");
            return;
        }
        temp = head;
        for (int i = 1; temp != NULL && i < position; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position out of range!\n");
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp == head)
            head = temp->next;
        if (temp == tail)
            tail = temp->prev;
        free(temp);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n1. Create a LL\n2. Display the LL\n3. Insert Elements into the LL\n4. Delete\n5. End\nChoose: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice.\n");
            break;
        }
    }
}
