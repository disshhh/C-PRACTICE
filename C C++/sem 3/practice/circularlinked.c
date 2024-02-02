#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;

} NODE;

typedef struct circularlinked
{
    NODE *last;

} CLL;

void initlist(CLL *cl);
void insertfront(CLL *cl, int ele);
void insertlast(CLL *cl, int ele);
void insertatpos(CLL *cl, int ele, int pos);
void display(CLL *cl);

int main()
{
    CLL lobj;

    initlist(&lobj);

    int choice, ele, pos;
    do
    {
        printf("1.insert front 2.insert last 3.insert at position 4.display 5.exit\n");
        printf("enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element:");
            scanf("%d", &ele);
            insertfront(&lobj, ele);
            break;
        case 2:
            printf("enter the element:");
            scanf("%d", &ele);
            insertfront(&lobj, ele);
            break;
        case 3:
            printf("enter the element:");
            scanf("%d", &ele);
            printf("enter the position:");
            scanf("%d", &pos);
            insertatpos(&lobj, ele, pos);
            break;
        case 4:
            display(&lobj);
        case 5:
            exit(0);
        }
    } while (choice < 15);
}

void initlist(CLL *cl)
{
    cl->last = NULL;
}
void insertfront(CLL *cl, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = ele;

    if (cl->last == NULL)
    {
        cl->last = temp;
        temp->next = temp;
    }
    temp->next = cl->last->next;
    cl->last->next = temp;
}
void insertlast(CLL *cl, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = ele;

    if (cl->last == NULL)
    {
        cl->last = temp;
        temp->next = temp;
    }
    temp->next = cl->last->next;
    cl->last->next = temp;
    cl->last = temp;
}
void deletefront(CLL *pl, int *pe)
{
    if (pl->last == NULL)
    {
        printf("empty list\n");
    }
    if (pl->last == pl->last->next)
    {
        *pe = pl->last->info;
        free(pl->last);
        pl->last = NULL;
        return;
    }
    NODE *p = pl->last->next;
    pl->last->next = p->next;
    *pe = p->info;
    free(p);
    return;
}
void deletelast(CLL *pl, int *pe)
{
    if (pl->last == NULL)
    {
        printf("empty list\n");
    }
    if (pl->last == pl->last->next)
    {
        *pe = pl->last->info;
        free(pl->last);
        pl->last = NULL;
        return;
    }
    NODE *p = pl->last->next;
    while (p->next != pl->last)
    {
        p = p->next;
    }
    p->next = pl->last->next;
    *pe = pl->last->info;
    free(pl->last);
    pl->last = p;
    return;
}
void insertatpos(CLL *cl, int ele, int pos)
{
}
void display(CLL *cl)
{
}