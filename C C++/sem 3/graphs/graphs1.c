#include <stdio.h> //bsf
#include <stdlib.h>
#define MAX 10

void readgraph(int a[MAX][MAX], int n);
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int connected(int a[MAX][MAX], int n, int visited[MAX], int source);
int path(int a[MAX][MAX], int n, int visited[MAX], int source, int dest);
int main()
{
    int a[MAX][MAX], n;
    int visited[MAX] = {0}, source;

    printf("enter the source\n");
    scanf("%d", &source);
    printf("enter the destination\n");
    scanf("%d", &dest);
    printf("enter the adjacency matrix\n");
    readgraph(a, n);

    printf("BFS traversal\n");

    bfs(a, n, visited, source);

    if (connected(a, n, visited, source))
        printf("graph is connected \n");
    else
        printf("graph is not connected\n");
    return 0;
    readgraph(a, n);

    printf("BFS traversal\n");

    if (bfs(a, n, visited, source, dest))
        ;
    int count = connected(a, n, visited, source);
    printf("%d", count);
}
// print all the vertices in disconnected graph:
int connected(int a[MAX][MAX], int n, int visited[MAX], int source)
{
    bfs(a, n, visited, source);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
// path:
int path(int a[MAX][MAX], int n, int visited[MAX], int source, int dest)
{
    visited[source] = 1;
    while (f <= r)
    {
        int v = q[f++];
        printf("%d", v);
        for (int i = 0; i < n; i++)
        {
            if (a[v][i] && visited[i] == 0)
            {
                q[++r] = i;
                visited[i] = 1;
                if (i == dest)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
// count of disconnected graph:
int connected(int a[MAX][MAX], int n, int visited[MAX], int source)
{
    int count = 1;
    bfs(a, n, visited, source);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            bfs(a, n, visited, i);
        }
    }
    return count;
}
