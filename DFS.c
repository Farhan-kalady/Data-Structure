// Implement DFS algorithm
#include <stdio.h>

int visited[20], n;        // visited[] to track visited vertices, n = number of vertices
int a[20][20];             // adjacency matrix representing edges between vertices

// DFS function definition
void dfs(int v)
{
    int i;
    visited[v] = 1;        // Mark current vertex as visited
    printf("%d ", v);      // Print the visited vertex

    // Traverse all vertices connected to v
    for(i = 0; i < n; i++)
    {
        // Check if there is an edge and vertex i is not visited
        if(a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);        // Recursive call to visit the next connected vertex
        }
    }
}

int main()
{
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);       // Read the number of vertices
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)        // Loop for rows
    {
        for(j = 0; j < n; j++)    // Loop for columns
        {
            scanf("%d", &a[i][j]); // Read each value of adjacency matrix
        }
    }
    
    // Initialize visited array to 0 (meaning unvisited)
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);   // Read starting vertex value

    printf("DFS Traversal: ");
    dfs(start);            // Call DFS beginning from the starting vertex

    return 0;              // End of program
}


/*
Sample Input:
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 0

Sample Output:
DFS Traversal: 0 1 3 2
*/
