#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct list
{
    NODE *head;
} LIST;

void initlist(LIST *p);
void insertfront(LIST *p, int ele);
void insertlast(LIST *p, int ele);
int deletefront(LIST *p, int *pe);
int deletelast(LIST *p, int *pe);
int insertatpos(LIST *p, int ele, int pos);
int deleteatpos(LIST *p, int *pele, int pos);

int main()
{
}
void initlist(LIST *p)
{
    p->head = NULL;
}

NODE *createnode(int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = ele;
    newnode->next = NULL;
    return newnode;
}

void insertfront(LIST *p, int ele)
{
    NODE *temp = createnode(ele);

    if (p->head == NULL)
        p->head = temp;

    temp->next = p->head;
    p->head = temp;
}

void insertlast(LIST *p, int ele)
{
    NODE *temp = createnode(ele);
    if (p->head == NULL)
        p->head = temp;

    NODE *k = p->head;
    while (k->next != NULL)
        k = k->next;

    k->next = temp;
}

int deletefront(LIST *pl, int *pele)
{
    if (pl->head == NULL)
        return 0;
    NODE *k = pl->head;
    *pele = pl->head->info;
    pl->head = pl->head->next;
    free(k);
    return 1;
}

int deletelast(LIST *pl, int *pele)
{
    if (pl->head == NULL)
        return 0;
    if (pl->head->next == NULL)
    {
        *pele = pl->head->info;
        free(pl);
        pl->head = NULL;
        return 1;
    }
    NODE *p = pl->head;
    NODE *q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    *pele = p->info;
    free(p);
    q->next = NULL;
    return 1;
}
void display(LIST *pl)
{
    if (pl->head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        NODE *p = pl->head;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
}
int countnodes(LIST *pl)
{
    int count = 0;

    NODE *p = pl->head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int insertatpos(LIST *pl, int ele, int pos)
{
    NODE *temp = createnode(ele);
    int n = countnodes(pl);

    if (pos > n || pos < 0)
    {
        return 0;
    }
    if (pos == 0)
    {
        insertfront(pl, ele);
    }
    else
    {
        NODE *p = pl->head;
        NODE *q = NULL;
        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        temp->next = p;
        q->next = temp;
        return 1;
    }
}
int deleteatpos(LIST *pl, int *pele, int pos)
{
    NODE *p = pl->head;
    int n = countnodes(pl);
    if (pos > n || pos < 0)
    {
        return 0;
    }
    if (pos == 0)
    {
        deletefront(pl, pele);
    }
    else
    {
        NODE *p = pl->head;
    }
}
