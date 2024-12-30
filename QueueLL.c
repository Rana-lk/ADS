#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *front, *rear = NULL, *newnode, *temp;

void main()
{
    int ch;
    printf("Queue operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
    while (1)
    {
        printf("Enter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Memory allocation has been failed.\n");
            }
            printf("Enter the element to be inserted:\n");
            scanf("%d", &newnode->data);
            newnode->link = NULL;
            if(rear==NULL)
            {
                rear = newnode;
                front = newnode;
            }
            else
            {
                temp = rear;
                while (temp->link!=NULL)
                {
                    temp = temp->link;
                }
                temp->link = newnode;
            }
            break;

        case 2:
            if (rear == NULL)
            {
                printf("The queue is empty.\n");
            }
            else
            {
                temp = front->link;
                front->link = temp->link;
                free(temp);
            }
            break;

        case 3:
            temp = front;
            printf("The queue is:\n");
            while (temp != NULL)
            {
                printf("%d\n", temp->data);
                temp = temp->link;
            }
            break;

        case 4:
            if(rear==NULL)
            {
                printf("The queue is empty.\n");
            }
            else
            {
                printf("The peek element in the queue is:%d",front->data);
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