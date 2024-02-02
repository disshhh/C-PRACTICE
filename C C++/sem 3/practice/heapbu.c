#include <stdio.h>
#define MAX 50

void bottomupheap(int h[], int n);

int main()
{
    int h[MAX];
    int n;

    printf("enter the number of elements:");
    scanf("%d", &n);

    printf("enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", h[i]);
    }
    bottomupheap(h, n);

    printf("bottom up heap is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
}
void bottomupheap(int h[], int n)
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
            if (h[p] < h[c])
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
