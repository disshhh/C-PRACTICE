#include <stdio.h>
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} NODE;
typedef struct tree
{
    struct node *root;
} TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);

int main()
{
    TREE obj;
    initTree(&obj);
    createTree(&obj);

    printf("inorder Traversal:\n");
    inorder(&obj);

    printf("preorder Traversal:\n");
    preorder(&obj);

    printf("postorder Traversal:\n");
    postorder(&obj);

    return 0;
}
void initTree(TREE *pt)
{
    pt->root = NULL;
}

void createTree(TREE *pt)
{
    int choice;
    NODE *temp = malloc(sizeof(NODE));
    temp->left = temp->right = NULL;
    printf("enter the info:\n");
    scanf("%d", &temp->info);

    pt->root = temp;

    printf("do you want to add one more node?");
    scanf("%d", &choice);

    while (choice)
    {
        temp = malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        printf("enter the info:\n");
        scanf("%d", &temp->info);

        NODE *p = pt->root;
        NODE *q = NULL;

        while (p != NULL)
        {
            if (temp->info <= p->info)
            {
                q = p;
                p = p->left;
            }
            else
            {
                q = p;
                p = p->right;
            }
        }
        if (temp->info <= p->info)
        {
            q->left = temp;
        }
        else
        {
            q->right = temp;
        }
        printf("do you want to add one more node?");
        scanf("%d", &choice);
    }
}

void inord(NODE *i)
{
    if (i != NULL)
    {
        inord(i->left);
        printf(i->info);
        inord(i->right);
    }
}
void preord(NODE *i)
{
    if (i != NULL)
    {

        printf(i->info);
        preord(i->left);
        preord(i->right);
    }
}
void postord(NODE *i)
{
    if (i != NULL)
    {

        postord(i->left);
        postord(i->right);
        printf(i->info);
    }
}
void inorder(TREE *pt)
// LVR: root in between, increasing order always
{
    inord(pt->root);
}

void preorder(TREE *pt)
// VLR: root in the first
{
    preord(pt->root);
}

void postorder(TREE *pt)
// LRV: root in the last
{
    postord(pt->root);
}