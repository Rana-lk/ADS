#include <stdio.h>
int n, i, j, start, visited[20], a[20][20], stack[20], top = -1;
void dfs(int start);

int main()
{
    printf("Enter the number of nodes in the graph: ");
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
    printf("Enter the starting node: ");
    scanf("%d", &start);
    if (start < 0 || start >= n)
    {
        printf("Invalid entry.\n");
        return 0;
    }
    printf("DFS visited order is: ");
    dfs(start);
    return 0;
}

void dfs(int start)
{
    visited[start] = 1;
    printf("%d\t", start);
    for (i = 0; i < n; i++)
    {
        if (a[start][i] == 1 && visited[i] != 1)
        {
            dfs(i);
        }
    }
}