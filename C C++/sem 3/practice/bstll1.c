typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

void createtree(TREE *t)
{
    int choice;
    NODE *temp = malloc(sizeof(NODE));
    temp->left = temp->right = NULL;
    printf("enter data:")
        scanf("%d", temp->info);

    t->root = temp;

    while (choice)
    {
        NODE *temp = malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        printf("enter data:")
            scanf("%d", temp->info);
        NODE *p = t->root;
        NODE *q = NULL;
        while (p != NULL)
        {
            if (temp->info < p->info)
            {
                q = p;
                p = p->left;
            }
        }

        if (q->info <= temp->info)
        {
            q->left = temp;
        }
        else
        {
            q->right = temp;
        }
    }
}

void postorder(TREE *t)
{
    post(t->root);
}
NODE *post(NODE *r)
{
    if (r != NULL)
    {
        post(r->left);
        post(r->right);
        printf("%d", r->info);
    }
}

int search(NODE *r, int ele)
{
    if (r != NULL)
    {
        if (r->info == ele)
        {
            return 1;
        }
        if (r->info < ele)
        {
            return search(r->left, ele);
        }
        else
        {
            return search(r->right, ele);
        }
    }
    return 0;
}

int searchnode(TREE *t, key)
{
    return search(t->root, key);
}

int deletenode(NODE *r, int ele)
{
    NODE *temp;
    if (ele < r->info)
    {
        r->left = deletenode(r->left, ele);
    }
    else if (ele > r->info)
    {
        r->right = deletenode(r->right, ele);
    }
    else if (r->left == NULL)
    {
        temp = r->right;
        free(r);
        return temp;
    }
    else if (r->right == NULL)
    {
        temp = r->left;
        free(r);
        return temp;
    }
    else
    {
        temp = r->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        r->info = temp->info;
        r->right = deletenode(r->right, temp->info);
    }
    return r;
}

int findmin(TREE *t)
{
    return findmini(t->root);
}
int finidmini(NODE *r)
{
    if (r == NULL)
        return -1;
    while (r->left != NULL)
    {
        r = r->left;
    }
    return (r->info);
}
int findmax(TREE *t)
{
    return findmini(t->root);
}
int finidmaxi(NODE *r)
{
    if (r == NULL)
        return -1;
    while (r->right != NULL)
    {
        r = r->right;
    }
    return (r->info);
}
int findheight(NODE *r)
{
    if (r == NULL)
        return -1;
    return 1 + max(findheight(r->left), findheight(r->right));
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int findheight1(TREE *t)
{
    return findheight1(t->root);
}
int leafcount(NODE *r)
{
    if (r == NULL)
    {
        return 0;
    }
    if (r->left == NULL && r->right == NULL)
    {
        return 1;
    }
    return leafcount(r->left) + leafcount(r->right)
}
int findleafcount(TREE *t)
{
    if (t->root == NULL)
    {
        return 0;
    }
    return leafcount(t->root);
}

int findnode(NODE *r)
{
    if (r == NULL)
        return -1;

    return 1 + findnode(r->left) + findnode(r->right);
}
int findnode1(TREE *t)
{
    if (t->root == NULL)
    {
        return -1;
    }
    return findnode(t->root);
}

// BST ARRAY IMPLIMENTATION
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

    printf("Levelorder:");
    levelorder(bst);

    printf("Inorder:");
    inorder(bst, 0);

    printf("\nPreorder:");
    preorder(bst, 0);

    printf("\nPostorder:");
    postorder(bst, 0);

    return 0;
}

void initTree(NODE bst[MAX])
{
    for (int i = 0; i < MAX; i++)
        bst[i].used = 0;
}

void createTree(NODE bst[MAX])
{
    int ele, choice;
    printf("Enter root info\n");
    scanf("%d", &ele);
    bst[0].info = ele;
    bst[0].used = 1;

    printf("Do you want to add one more node\n");
    scanf("%d", &choice);
    int i;
    while (choice)
    {
        printf("Enter node info\n");
        scanf("%d", &ele);
        i = 0;
        while (i < MAX && bst[i].used)
        {
            if (ele < bst[i].info)
                i = 2 * i + 1;
            else
                i = 2 * i + 2;
        }
        if (i >= MAX)
        {
            printf("Outside the array bound\n");
            break;
        }
        bst[i].info = ele;
        bst[i].used = 1;
        printf("Do you want to add one more node\n");
        scanf("%d", &choice);
    }
}

void levelorder(NODE bst[MAX])
{
    for (int i = 0; i < MAX; i++)
        if (bst[i].used)
            printf("%d", bst[i].info);

    printf("\n");
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

void creattree