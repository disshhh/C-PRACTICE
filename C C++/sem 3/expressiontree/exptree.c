#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 20

typedef struct node
{
    int info;
    NODE *left;
    NODE *right;
} NODE;
typedef struct tree
{
    NODE *root;
} TREE;
typedef struct stack
{
    int top;
    NODE *s[MAX];
} STACK;

void inittree(TREE *pt)
{
    pt->root = NULL;
}

void initstack(STACK *ps)
{
    ps->top = -1;
}

int push(STACK *ps, int e)
{
    if (ps->top == MAX - 1)
        return 0;

    ps->top++;
    ps->s[ps->top] = e;
    return 1;
}

NODE *pop(STACK *ps)
{
    NODE *t = ps->s[ps->top];
    ps->top--;
    return t;
}

float eval(NODE *r)
{
    float res;
    switch (r->info)
    {
    case 1:
    }
}