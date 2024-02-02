#include <stdio.h>
#define MAX 50

void topdownheap(int h[], int n);
void heapify(int h[], int n);
int maxdelete(int h[], int *n);

int main()
{
    int n;
    int h[MAX];

    printf("enter the the number of elements:");
    scanf("%d", &n);

    printf("enter the elements:");
    topdownheap(h, n);

    printf("heap constructed:");
    for (int i = 0; i < n; i++)
    {
        printf("%d", h[i]);
    }

    int res = maxdelete(h, &n);
    printf("%d", res);

    int res = maxdelete(h, &n);
    printf("%d", res);
}

void topdownheap(int h[], int n)
{
    int key, p, c;
    scanf("%d", &h[0]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &h[i]);
        c = i;
        key = h[c];
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

void heapify(int h[], int n)
{
    int key, p, c;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        p = i;
        key = h[p];
        c = p * 2 + 1;
        while (c < n)
        {
            if (c + 1 < n)
            {
                if (h[c + 1] > h[c])
                {
                    c = c + 1;
                }
            }
            if (h[c] > key)
            {
                h[p] = h[c];
                p = c;
                c = p * 2 + 1;
            }
            else
                break;
        }
        h[p] = key;
    }
}
int maxdelete(int h[], int *n)
{
    int dele = h[0];
    h[0] = h[*n - 1];
    (*n)--;
    heapify(h, *n);
    return dele;
}
