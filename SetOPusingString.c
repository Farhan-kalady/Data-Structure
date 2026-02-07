#include <stdio.h>
#define MAX 20

void display(int set[], int n, char universal[])
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if (set[i] == 1)
        {
            printf("%c", universal[i]);
        }
    }
    printf("}");
}

void unionset(int A[], int B[], int C[], int n)
{
    for (int i = 0; i < n; i++)
    {
        C[i] = A[i] | B[i];
    }
}

void intersection(int A[], int B[], int C[], int n)
{
    for (int i = 0; i < n; i++)
    {
        C[i] = A[i] & B[i];
    }
}

void difference(int A[], int B[], int C[], int n)

{
    for (int i = 0; i < n;i++)
    {
        C[i] = A[i] & (!B[i]);
    }
}
int main()
{
    int n, i;
    char universal[MAX];
    printf("Enter the Number of elements in the Universal Set:");
    scanf("%d", &n);

    printf("Enter the elements of the Universal Set:\n");
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &universal[i]);
    }

    int A[MAX] = {0}, B[MAX] = {0}, C[MAX] = {0}, SizeA, SizeB;
    printf("Enter the Number of Elements in the set A :");
    scanf("%d", &SizeA);
    printf("enter the elemtns in the set A :");
    for (i = 0; i < SizeA; i++)
    {
        char x;
        scanf(" %c",&x);
        for (int j = 0; j < n; j++)
        {
            if (universal[j] == x)
            {
                A[j] = 1;
            }
        }
    }
    printf("Enter the Number of elements in the set B:");
    scanf("%d", &SizeB);
    printf("Enter the elements in the set B:");
    for (i = 0; i < SizeB; i++)
    {
        char x;
        scanf(" %c", &x);
        for (int j = 0; j < n; j++)
        {
            if (universal[j] == x)
            {
                B[j] = 1;
            }
        }
    }

    printf("set a:");
    display(A, n, universal);
    printf("Set B:");
    display(B, n, universal);

    unionset(A, B, C,n);
    printf("AuB :");
    display(C, n, universal);

    intersection(A, B, C, n);
    printf("AnB :");
    display(C, n, universal);

    difference(A, B, C, n);
    printf("A-B =");
    display(C, n, universal);

    return 0;
}