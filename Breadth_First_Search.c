// Implement BFS algorithm
#include <stdio.h>

int a[20][20], visited[20], queue[20];   // a = adjacency matrix, visited[] = mark nodes visited, queue[] = queue for BFS
int n, front = 0, rear = -1;             // queue pointers: front points to dequeue, rear to enqueue

// BFS function definition
void bfs(int start)
{
    int i, v;

    visited[start] = 1;     // Mark starting node as visited
    queue[++rear] = start;  // Insert starting vertex into queue (enqueue)

    // Continue until queue becomes empty
    while(front <= rear)
    {
        v = queue[front++];   // Remove element from queue (dequeue)
        printf("%d ", v);     // Print the visited node

        // Check all adjacent vertices of v
        for(i = 0; i < n; i++)
        {
            // If there is an edge and the neighbor is not visited
            if(a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;         // Mark the vertex as visited
                queue[++rear] = i;      // Add vertex to the queue (enqueue)
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);        // Read number of vertices

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)  // Loop through rows
    {
        for(j = 0; j < n; j++)  // Loop through columns
        {
            scanf("%d", &a[i][j]);  // Read adjacency matrix values
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;     // Initialize visited array to 0 (not visited)

    printf("Enter starting vertex: ");
    scanf("%d", &start);    // Read starting node

    printf("BFS Traversal: ");
    bfs(start);             // Call BFS function

    return 0;               // End program
}


/*
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 0

Sample Output:
BFS Traversal: 0 1 2 3
*/