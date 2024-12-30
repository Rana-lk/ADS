#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[100],x,y,front=-1,rear=-1,i;
    printf("Enter the size of the queue:\n");
    scanf("%d",&x);
    int b[x];
    printf("The Queue Operations are:\n1.Enqueue\n2.Display\n3.Dequeue\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice:\n");
        scanf("%d",&y);
        switch(y)
        {
            case 1:
            if(rear==x-1)
            {
                printf("The queue is full.\n");
            }
            else
            {
                if(front==-1)
                {
                    front=0;
                }
                rear++;
                printf("Enter the element to be inserted:\n");
                scanf("%d",&b[rear]);
            }
            break;
            case 2:
            if((front==-1)||(front>rear))
            {
                printf("The queue is empty.\n");
            }
            else
            {
                printf("The elements in the queue are:\n");
                for(i=front;i<=rear;i++)
                {
                    printf("%d\n",b[i]);
                }
            }
            break;
            case 3:
            if((front==-1)||(front>rear))
            {
                printf("The queue is empty.\n"); 
            }
            else
            {
                front++;
                printf("The element that is removed from the queue is:%d\n",b[front]);
                if(front>rear)
                {
                    front=rear=-1;
                }
            }
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice.\n");
        }
    }
}