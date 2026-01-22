#include <stdio.h>

#define SIZE 10   // You can change this to any universal set size

// Function to display a set from bit string
void displaySet(int set[]) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1)
            printf("%d ", i);
    }
    printf("}\n");
}

// Function for Union
void setUnion(int A[], int B[], int result[]) {
    for (int i = 0; i < SIZE; i++) 
        result[i] = A[i] | B[i];
}

// Function for Intersection
void setIntersection(int A[], int B[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = A[i] & B[i];
}

// Function for Difference (A - B)
void setDifference(int A[], int B[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = A[i] & (!B[i]);
}

int main() {
    int A[SIZE] = {0}, B[SIZE] = {0};
    int Union[SIZE], Intersection[SIZE], Difference[SIZE];

    int n, elem;

    // Input set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &n);
    printf("Enter elements of Set A (0-%d): ", SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        if (elem >= 0 && elem < SIZE)
            A[elem] = 1;
    }

    // Input set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &n);
    printf("Enter elements of Set B (0-%d): ", SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        if (elem >= 0 && elem < SIZE)
            B[elem] = 1;
    }

    // Perform operations
    setUnion(A, B, Union);
    setIntersection(A, B, Intersection);
    setDifference(A, B, Difference);

    // Display results
    printf("\nSet A = "); displaySet(A);
    printf("Set B = "); displaySet(B);

    printf("\nUnion (A ∪ B) = "); displaySet(Union);
    printf("Intersection (A ∩ B) = "); displaySet(Intersection);
    printf("Difference (A - B) = "); displaySet(Difference);

    return 0;
}
