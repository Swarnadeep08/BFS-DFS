#include <stdio.h>
#define V 10
#include "Queue.h"

// n is declared as a global variable
int n;

void BFS(int G[][n+1], int i)
{
    int j;
    int visited[V] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty())
    {
        i = dequeue();
        for(j=1; j<=n; j++){
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][n+1], int i)
{
    int j;
    static int visited[V] = {0};

    if(visited[i]==0){
        printf("%d ", i);
        visited[i] = 1;

        for(j = 1; j<=n; j++){
            if(G[i][j]==1 && visited[j]==0)
                DFS(G, j);
        }
    }
}

int main()
{
    int start;
    printf("Enter the number of vertex in the graph ");
    scanf("%d", &n);

    int G[n+1][n+1];
    printf("\nEnter 0 if edge is not present!\nEnter 1 if there is any edge present between the vertices\n");
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0 || i==j)
                G[i][j] = 0;
            else if(j>i){
                printf("G[%d][%d] = ", i, j);
                scanf("%d", &G[i][j]);
            }
            else if(i>j)
                G[i][j] = G[j][i];
        }
    }

    printf("\nThe adjacency matrix of the undirected graph G[%d][%d]\n", n, n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }

    printf("\nEnter the vertex with which you want to start BFS - ");
    scanf("%d", &start);
    BFS(G, start);
    printf("\n");

    printf("\nEnter the vertex with which you want to start DFS - ");
    scanf("%d", &start);
    DFS(G, start);

    front = rear = NULL;
    return 0;
}
