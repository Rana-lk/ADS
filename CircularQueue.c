#include <stdio.h>
#include <stdlib.h>
void main()
{
    int front = -1, rear = -1, i, x, y;
    printf("Enter the size of the queue:");
    scanf("%d", &x);
    int b[x];
    while (1)
    {
        printf("Circular Queue Operations are:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            if ((rear + 1) % x == front)
            {
                printf("The circular queue is full.\n");
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                }
                rear = (rear + 1) % x;
                printf("Enter the element to be inserted:\n");
                scanf("%d", &b[rear]);
            }
            break;

        case 2:
            if (front == -1)
            {
                printf("The circular queue is empty.\n");
            }
            else
            {
                printf("The element that has been deleted from the circular queue is:%d\n", b[front]);
                if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }
                else
                {
                front = (front + 1) % x;
                }
            }
            break;

        case 3:
            if (front == -1)
            {
                printf("The circular queue is empty.\n");
            }
            else
            {
                printf("The circular queue is:\n");
                i=front;
                while (1)
                {
                    printf("%d\n", b[i]);
                    if(i==rear)
                    {
                        break;
                    }
                    i = (i + 1) % x;
                }
            }
            break;

        case 4:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}
