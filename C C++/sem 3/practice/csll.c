#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct csll *next;
} NODE;

typedef struct csll
{
    NODE *last;
} CSLL;

void initlist(CSLL *cl)
{
    cl->last = NULL;
};

NODE *createnode(int ele)
{
    NODE *p = malloc(sizeof(NODE));
    p->info = ele;
    p->next = NULL;
    return p;
};

void insertfront(CSLL *cl, int ele)
{
    NODE *newnode = createnode(ele);
    if (cl->last == NULL)
    {
        newnode->next = newnode;
        cl->last = newnode;
    }
    else
    {
        newnode->next = cl->last->next;
        cl->last->next = newnode;
    }
}
void insertlast(CSLL *cl, int ele)
{
    NODE *newnode = createnode(ele);
    if (cl->last == NULL)
    {
        newnode->next = newnode;
        cl->last = newnode;
    }
    else
    {
        newnode->next = cl->last->next;
        cl->last->next = newnode;
        cl->last = newnode;
    }
}