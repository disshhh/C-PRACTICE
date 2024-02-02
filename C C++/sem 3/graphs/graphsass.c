#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Define a graph using an adjacency list
int graph[MAX][MAX];
int n; // Number of nodes

bool vissii[MAX];

// Depth-First Search (DFS) function
bool canredest(int sssssccrr, int dest)
{
    if (sssssccrr == dest)
    {
        return true;
    }

    vissii[sssssccrr] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[sssssccrr][i] && !vissii[i] && canredest(i, dest))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int e; // Number of edges
    scanf("%d %d", &n, &e);

    // Initialize the graph
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    int q; // Number of queries
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int sssssccrr, dest;
        scanf("%d %d", &sssssccrr, &dest);

        // Initialize vissii array for each query
        for (int j = 1; j <= n; j++)
        {
            vissii[j] = false;
        }

        if (canredest(sssssccrr, dest))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}
