#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct llist
{
    NODE *head;
} LLIST;

NODE *createnode(int ele);
void initlist(LLIST *pl);
void insertFront(LLIST *pl, int ele);
void insertLast(LLIST *pl, int ele);
void insertatpos(LLIST *pl, int ele, int pos);
void display(LLIST *pl);
void destroyList(LLIST *pl);
void deletefront(LLIST *pl, int *pe);
void deletelast(LLIST *pl, int *pe);
void deleteatpos(LLIST *pl, int pos, int *pe);
int countnodes(LLIST *pl);
int searchkey(LLIST *pl, int ele);

int main()
{
    LLIST lobj;
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
void initlist(LLIST *pl)
{
    pl->head = NULL;
}
NODE *createnode(int ele)
{
    NODE *p = malloc(sizeof(NODE));
    p->info = ele;
    p->next = NULL;
    return p;
}

void insertFront(LLIST *pl, int ele)
{
    NODE *temp = createnode(ele);

    temp->next = pl->head;
    pl->head = temp;
}

void insertLast(LLIST *pl, int ele)
{
    NODE *temp = createnode(ele);

    if (pl->head == NULL)
    {
        temp->next = pl->head;
        pl->head = temp;
        return;
    }
    else
    {
        NODE *p = pl->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        return;
    }
}
void insertatpos(LLIST *pl, int ele, int pos)
{
    NODE *temp = createnode(ele);
    if (pos == 0)
    {
        temp->next = pl->head;
        pl->head = temp;
        return;
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
        q->next = temp;
        temp->next = p;
    }
}
void display(LLIST *pl)
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
void destroyList(LLIST *pl)
{
    NODE *p = pl->head;
    NODE *q = NULL;
    if (pl->head == NULL)
    {
        printf("list is empty!!");
        return;
    }
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
        printf("freed %d\n", q->info);
        free(q);
    }
    q = q->next;
    printf("freed %d\n", q->info);
    pl->head = NULL;
}

void deletefront(LLIST *pl, int *pe)
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
void deletelast(LLIST *pl, int *pe)
{
    NODE *p = pl->head;
    NODE *q = NULL;
    if (p->next == NULL)
    {
        *pe = p->info;
        free(p);
        pl->head = NULL;
        return;
    }
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    *pe = p->info;
    free(p);
    q->next = NULL;
}
void deleteatpos(LLIST *pl, int pos, int *pe)
{
    NODE *p = pl->head;
    NODE *q = NULL;
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
    if (pos == 0)
    {
        pl->head = p->next;
        *pe = p->info;
        free(p);
    }
    for (int i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    *pe = p->info;
    free(p);
    return;
}
int countnodes(LLIST *pl)
{
    NODE *p = pl->head;
    int count = 0;
    if (pl->head == NULL)
        return count;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
int searchkey(LLIST *pl, int ele)
{
    NODE *p = pl->head;
    int pos = -1;
    if (pl->head != NULL)
    {
        while (p->next != NULL)
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