/*

heaps:(binary tree)
max heaps- (parent node value greater than child) topdown heap, bottomup heap(priority queue , reverse of topdown)
min heaps - (child value greater than the parent value)

How to identify heaps?
1.parent value greater than child values
2.fill nodes from left to right

*/

void topDownHeap(int h[MAX], int n)
{
    int c, p, key;
    printf("enter the elements\n");
    scanf("%d", &h[0]);

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &h[i]);
        c = i;
        p = (c - 1) / 2;
        key = h[c];

        while (c > 0 && h[p] < key)
        {
            h[c] = h[p];
            c = p;
            p = (c - 1) / 2;
        }
        h[c] = key;
    }
}
void bottomUpHeap(int h[MAX],int n);
int max delete