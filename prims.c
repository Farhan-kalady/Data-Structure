#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int i, j, ne = 1;
    int min, a, b, u, v;
    int total_cost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (use 0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // Replace 0 with infinity
        }
    }

    visited[1] = 1; // Start from vertex 1

    printf("\nEdges of Minimum Cost Spanning Tree:\n");

    while (ne < n) {
        min = INT_MAX;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[u] || !visited[v]) {
            printf("\nEdge %d: (%d -> %d)  cost: %d", ne++, a, b, min);
            total_cost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = INT_MAX; // mark edge as used
    }

    printf("\n\nMinimum cost = %d\n", total_cost);
    return 0;
}
