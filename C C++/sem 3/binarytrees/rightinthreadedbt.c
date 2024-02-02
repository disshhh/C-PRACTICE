// Threaded Binary tree:
//(inorder sucessor):
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
    int rThread;
} NODE;
typedef struct tree
{
    NODE *root;
} TREE;
int main()
{
    TREE tobj;
    initTree(&tobj);
    createTree(&tobj);
    printf("inorder traversa\n");
    inorder(&tobj);
}
void initTree(TREE *pt)
{
    pt->root = NULL;
}
NODE *createNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = ele;
    temp->left = ele;
    temp->left = temp->right = NULL;
    temp->rThread = 1;
    return temp;
}
void setLeft(NODE *q, NODE *temp)
{
    q->left = temp;
    temp->right = q;
}
void setRight(NODE *p, NODE *temp)
{
    temp->right = p->right;
    p->right = temp;
    p->rThread = 0;
}

void createTree(TREE *pt)
{
    int ele, choice;
    printf("enter root info\n");
    scanf("%d", &ele);
    pt->root = createNode(ele);

    printf("Do you want to add one more node\n");
    scanf("%d", &choice);
    NODE *p, *q, *temp;

    while (choice)
    {
        p = pt->root;
        q = NULL;
        printf("enter info\n");
        scanf("%d", &ele);
        temp = createNode(ele);
        while (p != NULL)
        {
            q = p;
            if (temp->info < p->info)
                p = p->left;
            else
        }
    }
}