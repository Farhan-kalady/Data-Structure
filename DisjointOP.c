#include <stdio.h>
#include<stdlib.h>
#define MAX 20 // Maximum allowed set size

int parent[MAX];   // Stores parent index for each element
int elements[MAX]; // Stores actual user-entered values
int n;             // Number of elements

// Function to get index of a value in elements[] array
int getIndex(int x)
{
    for (int i = 0; i < n; i++) // Traverse through elements
        if (elements[i] == x)   // If match found
            return i;           // Return index position
    return -1;                  // If not found
}

// Function to create disjoint sets
void createSet()
{
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {                              // Read n elements
        scanf("%d", &elements[i]); // Store element in array
        parent[i] = i;             // Each element initially points to itself
    }
    printf("Disjoint sets created.\n");
}

// Find root using index (without path compression for simplicity)
int findSet(int i)
{
    while (parent[i] != i) // Continue until the root parent is found
        i = parent[i];     // Move up to parent
    return i;              // Return representative
}

// Union two values x and y
void unionSet(int x, int y)
{
    int i = getIndex(x); // Get index of x
    int j = getIndex(y); // Get index of y

    if (i == -1 || j == -1)
    { // If either element doesn't exist
        printf("Element not found!\n");
        return;
    }

    int rootI = findSet(i); // Find representative of x
    int rootJ = findSet(j); // Find representative of y

    if (rootI != rootJ)
    {                          // If different sets
        parent[rootJ] = rootI; // Perform union
        printf("Union done: %d and %d merged.\n", x, y);
    }
    else
    {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Display the internal parent mapping
void display()
{
    printf("\nElement: ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[i]); // Print user-entered elements

    printf("\nParent : ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[parent[i]]); // Print corresponding parent values

    printf("\n");
}

int main()
{
    int choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n); // Read number of elements

    createSet(); // Create initial sets

    while(1)
    {
        printf("\n--- Menu ---\n"); // Display menu options
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read choice from user

        switch (choice)
        {
        case 1:
            printf("Enter two elements to union: ");
            scanf("%d %d", &x, &y); // Take values for union
            unionSet(x, y);
            break;

        case 2:
            printf("Enter element to find its representative: ");
            scanf("%d", &x);
            {
                int idx = getIndex(x); // Get index of element
                if (idx == -1)
                    printf("Element not found!\n");
                else
                    printf("Representative of %d is: %d\n",
                           x, elements[findSet(idx)]);
            }
            break;

        case 3:
            display(); // Print parent relationships
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }

    }  // Repeat until exit selected

    return 0; // End program
}

/*
------------------- SAMPLE OUTPUT -------------------

Enter number of elements: 5
Enter 5 elements: 10 20 30 40 50
Disjoint sets created.

--- Menu ---
1. Union
2. Find
3. Display
4. Exit
Enter your choice: 1
Enter two elements to union: 10 20
Union done: 10 and 20 merged.

Enter your choice: 1
Enter two elements to union: 30 40
Union done: 30 and 40 merged.

Enter your choice: 2
Enter element to find its representative: 20
Representative of 20 is: 10

Enter your choice: 3
Element: 10 20 30 40 50
Parent : 10 10 30 30 50

Enter your choice: 4
Exiting...
-----------------------------------------------------
*/
