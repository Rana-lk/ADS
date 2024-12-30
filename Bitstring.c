#include <stdio.h>

int isPresent(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

void makeSet(int arr[], int universal[], int size, int universalSize)
{
    int element;
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        if (!isPresent(arr, i, element) && (universal == NULL || isPresent(universal, universalSize, element)))
        {
            arr[i] = element;
        }
        else
        {
            printf("This element already exists or is not present in the universal set.\n");
            i--; 
        }
    }
}

void printSet(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void computeUnion(int set1[], int set2[], int result[], int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = set1[i] || set2[i];
    }
}

void computeIntersection(int set1[], int set2[], int result[], int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = set1[i] && set2[i];
    }
}

int main()
{
    int n, n1, n2;

    printf("Enter the size of the universal set: ");
    scanf("%d", &n);
    int U[n];
    printf("Enter the elements of the universal set:\n");
    makeSet(U, NULL, n, 0);

    printf("Enter the size of the first set: ");
    scanf("%d", &n1);
    if (n1 > n || n1 < 0)
    {
        printf("The size should be less than or equal to the universal set and a natural number.\n");
        return 1;
    }
    int set1[n1];
    printf("Enter the elements of the first set:\n");
    makeSet(set1, U, n1, n);

    printf("Enter the size of the second set: ");
    scanf("%d", &n2);
    if (n2 > n || n2 < 0)
    {
        printf("The size should be less than or equal to the universal set and a natural number.\n");
        return 1;
    }
    int set2[n2];
    printf("Enter the elements of the second set:\n");
    makeSet(set2, U, n2, n);

    int S1[n], S2[n];
    for (int i = 0; i < n; i++)
    {
        S1[i] = S2[i] = 0;
        for (int j = 0; j < n1; j++)
        {
            if (U[i] == set1[j])
            {
                S1[i] = 1;
                break;
            }
        }
        for (int j = 0; j < n2; j++)
        {
            if (U[i] == set2[j])
            {
                S2[i] = 1;
                break;
            }
        }
    }

    int setUnion[n], setIntersection[n];
    computeUnion(S1, S2, setUnion, n);
    computeIntersection(S1, S2, setIntersection, n);

    printf("Universal set (U): ");
    printSet(U, n);
    printf("Set 1 (S1 as bit vector): ");
    printSet(S1, n);
    printf("Set 2 (S2 as bit vector): ");
    printSet(S2, n);
    printf("S1 U S2: ");
    printSet(setUnion, n);
    printf("S1 n S2: ");
    printSet(setIntersection, n);

    return 0;
}
