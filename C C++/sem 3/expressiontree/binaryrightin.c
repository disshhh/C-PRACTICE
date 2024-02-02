#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    NODE *left;
    NODE *right;
    int inRight;
} NODE;

typedef struct tree
{
    NODE *root;
} TREE;

void inittree(TREE *pt)
{
    pt->root = NULL;
}
NODE *create(int ele)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->inRight = 1;

    return newNode;
}
void setleft(NODE *cur, NODE *newNode)
{
    newNode->right = cur;
    cur->left = newNode;
}
void setright(NODE *cur, NODE *newNode)
{
    newNode->right = cur->right;
    cur->right = newNode;
    cur->inRight = 0;
}
void createtree(TREE *pt)
{
    NODE *p, *q, *newNode;
    int ele, choice;

    printf("enter root :");
    scanf("%d", &ele);
    pt->root = create(ele);
    printf("do you want to add more?");
    scanf("%d", &choice);

    while (choice)
    {
        p = pt->root;
        printf("enter value:");
        scanf("%d", ele);

        newNode = create(ele);
        while (p != NULL)
        {
            q = p;
            if (newNode->info < p->info)
            {
                p = p->left;
            }
            else
            {
                if (p->inRight)
                    break;
                p = p->right;
            }
        }
        if (p == NULL)
        {
            setleft(q, newNode)
        }
    }
}

void inorder(TREE *pt)
{
    NODE *p = pt->root;
    NODE *q = NULL;
    while (p != NULL)
    {
        while (p != NULL)
        {
            q = p;
            p = p->left;
        }
        printf("%d", q->info);
        p = q->right;
        if (q->inRight && p != NULL)
        {
            printf("%d", p->info);
            q = p;
            p = p->right;
        }
    }
}

void createtree(TREE *pt)
{
    int ele, choice;
    NODE *p, *q, *new;

    printf("enter value:");
    scanf("%d", &ele);

    new = create(ele);
    pt->root = new;

    printf("do u want more nodes?");
    scanf("%d", &choice);

    while (choice)
    {
        p = pt->root;
        while (p != NULL)
        {
            q = p;
            if (new->info < p->info)
            {
                p = p->left;
            }
            else
            {
                if (p->inRight)
            }
        }
    }
}