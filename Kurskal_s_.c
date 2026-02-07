// Kruskal’s algorithm for finding the minimum cost spanning tree using Disjoint Set
#include <stdio.h>
#define MAX 10
int parent[MAX];
int cost[MAX][MAX];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main()
{
    int i, j, n;
    int v1, v2, u, v;
    int edgecount = 1;
    int c = 0, mincost = 0;
    printf("Enter total number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    for (i = 1; i <= n; i++)
        parent[i] = i;
    while (edgecount < n)
    {
        c = 9999;
        // Find minimum edge in cost matrix
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < c)
                {
                    c = cost[i][j];
                    v1 = i;
                    v2 = j;
                }
        u = find(v1);
        v = find(v2);
        // If u and v belong to different sets, include this edge
        if (uni(u, v))
        {
            printf("Edge %d: (%d -> %d) cost = %d\n", edgecount, v1, v2, c);
            edgecount++;
            mincost += c;
        }
        // Mark edge as used
        cost[v1][v2] = cost[v2][v1] = 9999;
    }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

/*
------------------- SAMPLE INPUT -------------------
Enter total number of vertices: 4
Enter the cost adjacency matrix:
0 10 6 0
10 0 5 15
6 5 0 4
0 15 4 0

------------------- SAMPLE OUTPUT -------------------
Edge 1: (3 -> 4) cost = 4
Edge 2: (2 -> 3) cost = 5
Edge 3: (1 -> 3) cost = 6

Minimum cost = 15
*/
