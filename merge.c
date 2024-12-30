#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[50], b[50], c[50], m, n, i, j;
    printf("Enter the size of the 1st array:\n");
    scanf("%d", &m);
    printf("Enter the size of the 2nd array:\n");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        printf("Enter the %dth element of the 1st array: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    for (j = 0; j < n; j++)
    {
        printf("Enter the %dth element of the 2nd array: ", j + 1);
        scanf("%d", &b[j]);
    }
    printf("\n");
    for (i = 0; i < m; i++)
    {
        c[i]=a[i];
    }
    for(j=0;j<n;j++)
    {
        c[m+j]=b[j];
    }
    printf("The merged array is:\n");
    for(i=0;i<m+n;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
}