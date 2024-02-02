#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

typedef struct node
{
    char info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct tree
{
    NODE *root;
} TREE;

typedef struct stack
{
    NODE *s[MAX];
    int top;
} STACK;

void inittree(TREE *pt);
void initstack(STACK *ps);
void postordertrav(TREE *pt);
void preordertrav(TREE *pt);
void inordertrav(TREE *pt);
void exprtree(char postfix[], TREE *pt);
int evalexp(TREE *pt);

int main()
{
    TREE tobj;
    inittree(&tobj);
    char postfix[MAX];
    printf("enter the postfix exp:");
    scanf("%s", postfix);

    printf("preorder traversal:");
    preordertrav(&tobj);

    printf("postorder traversal:");
    postordertrav(&tobj);

    printf("inorder traversal:");
    inordertrav(&tobj);

    int res = evalexp(&tobj);
    printf("expression tree evaluation: %d", res);
}

void inittree(TREE *pt)
{
    pt->root = NULL;
}
void initstack(STACK *ps)
{
    ps->top = -1;
}
void push(STACK *ps, NODE *newnode)
{
    ps->top++;
    ps->s[ps->top] = newnode;
}
NODE *pop(STACK *ps)
{
    NODE *popped = ps->s[ps->top];
    ps->top--;
    return popped;
}
void exprtree(char postfix[], TREE *pt)
{
    STACK sobj;
    initstack(&sobj);
    for (int i = 0; postfix != '\0'; i++)
    {
        NODE *newnode = malloc(sizeof(NODE));
        newnode->info = postfix[i];

        if (isdigit(postfix[i]))
        {
            newnode->left = NULL;
            newnode->right = NULL;
            push(&sobj, postfix[i]);
        }
        else
        {
            newnode->right = pop(&sobj);
            newnode->left = pop(&sobj);
            push(&sobj, newnode);
        }
        pt->root = pop(&sobj);
    }
}
void post(NODE *n)
{
    if (n != NULL)
    {
        post(n->left);
        post(n->right);
        printf("%c", n->info);
    }
}
void postordertrav(TREE *pt)
{
    post(pt->root);
}
void pre(NODE *n)
{
    if (n != NULL)
    {
        printf("%c", n->info);
        post(n->left);
        post(n->right);
    }
}
void preordertrav(TREE *pt)
{
    pre(pt->root);
}
void inord(NODE *n)
{
    if (n != NULL)
    {
        post(n->left);
        printf("%c", n->info);
        post(n->right);
    }
}
void inordertrav(TREE *pt)
{
    inord(pt->root);
}

int eval(NODE *p)
{
    int res;
    switch (p->info)
    {
    case '+':
        res = eval(p->left) + eval(p->right);
        break;
    case '-':
        res = eval(p->left) - eval(p->right);
        break;
    case '*':
        res = eval(p->left) * eval(p->right);
        break;
    case '/':
        res = eval(p->left) / eval(p->right);
        break;
    default:
        res = p->info - '0';
        break;
    }
    return res;
}
int evalexp(TREE *pt)
{
    return eval(pt->root);
}

/*
void replace(TREENODE *p)
{
    TREENODE *q,*r;
    float value;
    if(p->utype==operator)
    {
        q=p->child;
        while(q!=NULL)
        {
            replace(q);
            q=q->next;
        }
        value=apply(p);
        p->utype=OPERAND;
        p->val=value;
        q=p->child;

    }
}



*/
