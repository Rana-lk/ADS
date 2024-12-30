#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[100], x, y, top = -1, i;
    printf("Enter the size of the array:\n ");
    scanf("%d", &x);
    int b[x];
    while (y)
    {
        printf("Stack Operations:\n1.Push\n2.Display\n3.Peek\n4.Pop\n5.Exit\n");
        printf("Enter the choice: \n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            if (top == x - 1)
            {
                printf("Overflow.\n");
            }
            else
            {
                top++;
                printf("Enter the element to be pushed:\n");
                scanf("%d", &b[top]);
            }
            break;
        case 2:
            if (top == -1)
            {
                printf("No element.\n");
            }
            else
            {
                printf("The stack is:\n");
                for (i = 0; i <= top; i++)
                {
                    printf("%d\n", b[i]);
                }
            }
            break;
        case 3:
            if (top == -1)
            {
                printf("The stack is empty.\n");
            }
            else
            {
                printf("%d", b[top]);
            }
            break;
        case 4:
            if (top == -1)
            {
                printf("Underflow.\n");
            }
            else
            {
                printf("The element that has been poped is:%d\n", b[top]);
                top--;
            }
            break;
        case 5:
            printf("Exit.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}