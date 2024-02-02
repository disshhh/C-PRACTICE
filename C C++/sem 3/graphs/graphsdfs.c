#include <stdio.h>
#include <stdlib.h>
#define MAX 10

readgraph(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
    visited[source] = 1;
    printf("%d", source);
    for (int i = 0; i < n; i++)
    {
        if (a[source][i] && visited[i] == 0)
            dfs(a, n, visited, i);
    }
} // two ways of coding this .....1.recursion...2.stack.
int main()
{
    int visited[MAX]
}
void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
    int s[n];
    int top=-1;
    int flag;
    s[++top]=source;
    visited[source]=1;
    printf("%d",source);

    while(top!=-1)
    {
            flag=0;
            source=s[top];
            for(int i=0;i<n;i++)
            {
                if(a[v][i] && visited[i]==0){
                flag=1;
                break;
            }
            if(flag){
                s[++top]=i;
                visited[i]=1;
                printf("%d",i);
            }
            else
            {
                top--;
            }
    }}
}
// path:
int dsf(int a[MAX][MAX], int n, int visited[MAX], int source, int dest)
{
    visited[source] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[source][i] && visited[i] == 0)
        {

            if (i == dest)
            {
                return 1;
            }
            else
                return dfs(a, n, visited, i, dest);
        }
    }
}
BST DICTIONARY: