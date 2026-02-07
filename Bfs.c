#include<stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = 0;
int visited[MAX] = {0};


void enqueue(int v){
    queue[rear++] = v;
}

int dequeue(){
    return queue[front++];
}

int isEmpty(){
    return front == rear;
}


void bfs(int graph[MAX][MAX],int n,int start){
    int i;

    visited[start] = 1;
    enqueue(start);

    printf("BFS traversal : ");

    while(!isEmpty())
    {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n;i++)
        {
            if(graph[node][i]==1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}
int main()
{
    int n,i,j,start;
    int graph[MAX][MAX];

    printf("Enter the Number OF vertices :");
    scanf("%d", &n);

    printf("Enter the Adjancency matrix :\n");
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting Vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}