#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} NODE;

typedef struct dlist
{
    NODE *head;
} DLIST;

NODE *createnode(int ele);
void initlist(DLIST *pl);
void insertFront(DLIST *pl, int ele);
void insertLast(DLIST *pl, int ele);
void insertatpos(DLIST *pl, int ele, int pos);
void display(DLIST *pl);
void destroyList(DLIST *pl);
void deletefront(DLIST *pl, int *pe);
void deletelast(DLIST *pl, int *pe);
void deleteatpos(DLIST *pl, int pos, int *pe);
int countnodes(DLIST *pl);
int searchkey(DLIST *pl, int ele);

int main()
{
    DLIST lobj;
    initlist(&lobj);
    int choice, ele, pos;

    do
    {
        printf("1.Insert front 2.Insert Last 3.Insert at position 4.Display 5.Destroy 6.Delete front 7.Delete Last 8.Delete at position 9.exit 10.search element\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the ele: ");
            scanf("%d", &ele);
            insertFront(&lobj, ele);
            break;
        case 2:
            printf("enter the ele: ");
            scanf("%d", &ele);
            insertLast(&lobj, ele);
            break;
        case 3:
            printf("enter the ele: ");
            scanf("%d", &ele);
            printf("enter the pos: ");
            scanf("%d", &pos);
            insertatpos(&lobj, ele, pos);
            break;
        case 4:
            display(&lobj);
            break;
        case 5:
            destroyList(&lobj);
            break;
        case 6:
            deletefront(&lobj, &ele);
            printf("deleted element is %d\n", ele);
            break;
        case 7:
            deletelast(&lobj, &ele);
            printf("deleted element is %d\n", ele);
            break;
        case 8:
            printf("emter the position: ");
            scanf("%d", &pos);
            deleteatpos(&lobj, pos, &ele);
            printf("deleted element is %d\n", ele);
            break;
        case 9:
            exit(0);
        case 10:
            printf("enter the element to be searched:");
            scanf("%d", &ele);
            pos = searchkey(&lobj, ele);
            printf("position is:%d\n", pos);
            break;
        }

    } while (choice < 15);

    return 0;
}
void initlist(DLIST *pl)
{
    pl->head = NULL;
}
NODE *createnode(int ele)
{
    NODE *p = malloc(sizeof(NODE));
    p->prev = NULL;
    p->info = ele;
    p->next = NULL;
    return p;
}

void insertFront(DLIST *pl, int ele)
{
    NODE *temp = createnode(ele);
    if (pl->head == NULL)
    {
        pl->head = temp;
    }
    else
    {
        temp->next = pl->head;
        pl->head->prev = temp;
        pl->head = temp;
    }
}

void insertLast(DLIST *pl, int ele)
{
    NODE *temp = createnode(ele);

    if (pl->head == NULL)
    {
        pl->head = temp;
    }
    else
    {
        NODE *p = pl->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}
void insertatpos(DLIST *pl, int ele, int pos)
{
    NODE *temp = createnode(ele);
    int n = countnodes(pl);
    if (pos < 0 || pos > n)
    {
        printf("invalid");
    }
    if (pos == n)
    {
        NODE *p = pl->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    if (pos == 0)
    {
        temp->next = pl->head;
        pl->head->prev = temp;
        pl->head = temp;
        return;
    }
    else
    {
        NODE *p = pl->head;

        for (int i = 0; i < pos; i++)
        {

            p = p->next;
        }
        p->prev->next = temp;
        temp->prev = p->prev;
        p->prev = temp;
        temp->next = p;

        return;
    }
}
void display(DLIST *pl)
{
    NODE *p = pl->head;
    if (pl->head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}
void destroyList(DLIST *pl)
{
    NODE *p = pl->head;

    if (pl->head == NULL)
    {
        printf("list is empty!!");
        return;
    }
    while (p->next != NULL)
    {

        p = p->next;
        printf("freed %d\n", p->prev->info);
        free(p->prev);
    }
    p = p->next;
    printf("freed %d\n", p->prev->info);
    pl->head = NULL;
}

void deletefront(DLIST *pl, int *pe)
{
    if (pl->head == NULL)
    {
        printf("list is empty!!\n");
        return;
    }
    else
    {
        NODE *p = pl->head;
        pl->head = pl->head->next;
        *pe = p->info;
        free(p);
        printf("element has been deleted\n");
        return;
    }
}
void deletelast(DLIST *pl, int *pe)
{
    NODE *p = pl->head;

    if (p->next == NULL)
    {
        *pe = p->info;
        free(p);
        pl->head = NULL;
        return;
    }
    while (p->next != NULL)
    {

        p = p->next;
    }
    *pe = p->info;
    p->prev->next = NULL;
    free(p);
}
void deleteatpos(DLIST *pl, int pos, int *pe)
{
    NODE *p = pl->head;

    int n = countnodes(pl);
    if (pos < 0 || pos > n)
    {
        printf("Invalid\n");
        return;
    }
    if (pl->head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    if (pos == n - 1)
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        *pe = p->info;
        p->prev->next = NULL;
        free(p);
    }
    if (pos == 0)
    {
        pl->head = pl->head->next;
        *pe = p->info;
        free(p);
        return;
    }
    for (int i = 0; i < pos; i++)
    {

        p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    *pe = p->info;
    free(p);
    return;
}
int countnodes(DLIST *pl)
{
    NODE *p = pl->head;
    int count = 0;
    if (pl->head == NULL)
        return count;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
int searchkey(DLIST *pl, int ele)
{
    NODE *p = pl->head;
    int pos = -1;
    if (pl->head != NULL)
    {
        while (p != NULL)
        {
            pos++;
            if (p->info == ele)
            {
                return pos;
            }
            p = p->next;
        }
    }
    return -1;
}
