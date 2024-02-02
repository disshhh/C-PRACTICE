#include <stdio.h>
#define MAX 50

void topd(int h[], int n);
int main()
{
    int h[MAX];
    int n;

    printf("enter the number of elements:");
    scanf("%d", &n);

    printf("enter the elements:");
    topd(h, n);

    printf("the elements of the heap are:");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);
}

void topd(int h[], int n)
{
    int key, c, p;
    scanf("%d", &h[0]);

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &h[i]);
        c = i;
        key = h[i];
        p = (c - 1) / 2;

        while (c > 0 && key > h[p])
        {
            h[c] = h[p];
            c = p;

            p = (c - 1) / 2;
        }
        h[c] = key;
    }
}