#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *top = NULL, *newnode, *temp;
void main()
{
    printf("Stack Operations:\n1.Push\n2.Display\n3.Peek\n4.Pop\n5.Exit\n");
    while (1)
    {
        int n;
        printf("Enter your choice:\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Memory allocation has been failed.\n");
            }
            printf("Enter the element to be inserted:\n");
            scanf("%d", &newnode->data);
            newnode->link = top;
            top = newnode;
            break;

        case 2:
            if (top == NULL)
            {
                printf("The stack is empty.");
            }
            else
            {
                printf("The stack is:\n");
                temp = top;
                while (temp != NULL)
                {
                    printf("%d\n", temp->data);
                    temp = temp->link;
                }
            }
            break;

        case 3:
            if (top == NULL)
            {
                printf("The stack is empty.");
            }
            else
            {
                printf("The peek element in the stack is:%d\n", top->data);
            }
            break;

        case 4:
            if (top == NULL)
            {
                printf("The stack is empty.\n");
            }
            else
            {
                temp = top;
                top = top->link;
                free(temp);
            }
            break;

        case 5:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}