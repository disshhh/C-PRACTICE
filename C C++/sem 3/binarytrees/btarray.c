// BST ARRAY IMPLEMENTATION:
#include <stdio.h>
#define MAX 20

typedef struct node
{
    int info;
    int used;
} NODE;

void initTree(NODE bst[MAX]);
void createTree(NODE bst[MAX]);
void levelorder(NODE bst[MAX]);
void inorder(NODE bst[MAX], int);
void preorder(NODE bst[MAX], int);
void postorder(NODE bst[MAX], int);

int main()
{
    NODE bst[MAX];
    initTree(bst);
    createTree(bst);

    printf("Levelorder: ");
    break;
}
void initTree(NODE bst[MAX])
{
    for (int i = 0; i < MAX; i++)
        bst[i].used = 0;
}
void createTree(NODE bst[MAX])
{
    int ele, choice;
    printf("enter root info\n");
    scanf("%d", &ele);
    bst[0].info = ele;
    bst[0].used = 1;
    printf("do you want to add one more node?");
    scanf("%d", &choice);
    int i;
    while (choice)
    {
        i = 0;
        while (i < MAX && bst[i].used)
        {
            if (ele < bst[i].info)
                i = 2 * i + 1;
            else
                i = 2 * i + 2;
        }
        if (i > MAX)
        {
            printf("Outside the array bound\n");
            break;
        }
    }
}
void levelorder(NODE bst[MAX])
{
}
void inorder(NODE bst[MAX], int i)
{
    if (i < MAX && bst[i].used)
    {
        inorder(bst, 2 * i + 1);
        printf("%d", bst[i].info);
        inorder(bst, 2 * i + 2);
    }
}
void preorder(NODE bst[MAX], int i)
{
    if (i < MAX && bst[i].used)
    {
        printf("%d", bst[i].info);
        inorder(bst, 2 * i + 1);
        inorder(bst, 2 * i + 2);
    }
}
void postorder(NODE bst[MAX], int i)
{
    if (i < MAX && bst[i].used)
    {
        inorder(bst, 2 * i + 1);
        inorder(bst, 2 * i + 2);
        printf("%d", bst[i].info);
    }
}