#include <stdio.h>
#include <stdlib.h>
int n, a[20][20], i, j, visited[20], queue[20], start, front = -1, rear = -1, node;
void bfs(int start);
void enqueue(int node);
int dequeue();

int main()
{
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting node : ");
    scanf("%d", &start);
    if (start < 0 || start > n - 1)
    {
        printf("Invalid entry!");
        return 0;
    }
    else
    {
        printf("BFS visited order : ");
        bfs(start);
    }
}

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    printf("%d\t", start);
    while (front != -1 && rear != -1)
    {
        node = dequeue();
        for (i = 0; i < n; i++)
        {
            if (a[i][node] == 1 && visited[i] != 1)
            {
                visited[i] = 1;
                printf("%d\t", i);
                enqueue(i);
            }
        }
    }
}

void enqueue(int node)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else 
    {
        rear++;
    }
    queue[rear] = node;
}

int dequeue()
{
    node = queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return node;
}