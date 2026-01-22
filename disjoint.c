#include <stdio.h>
#define MAX 100

int parent[MAX];   // parent[i] stores parent of i
int rank[MAX];     // rank[i] stores rank (depth) of tree

// Create: initialize n disjoint sets
void create(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;   // each element is its own parent
        rank[i] = 0;     // initial rank = 0
    }
}

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

// Union by rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    // Attach smaller rank tree under root of higher rank tree
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;  // increase rank
    }
    printf("Union done between %d and %d\n", x, y);
}

int main() {
    int n, choice, a, b;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    create(n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find\n2. Union\n3. Display parent array\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to find its set representative: ");
                scanf("%d", &a);
                if (a >= n) {
                    printf("Invalid element!\n");
                    break;
                }
                printf("Representative of %d is %d\n", a, find(a));
                break;

            case 2:
                printf("Enter two elements to perform union: ");
                scanf("%d %d", &a, &b);
                if (a >= n || b >= n) {
                    printf("Invalid elements!\n");
                    break;
                }
                unionSets(a, b);
                break;

            case 3:
                printf("Parent array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", parent[i]);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
 