#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
} STCK;

void initstack(STCK *pl);
NODE *createnode(STCK *pl, int ele);
void push(STCK *pl, int ele);
int pop(STCK *pl);
int isEmpty(STCK *pl);
int stacktop(STCK *pl);
void display(STCK *pl);
void destroy(STCK *pl);

int main()
{
    STCK sobj;

    initstack(&sobj);

    int choice, ele;

    do
    {
        printf("1.push 2.pop 3.isempty 4.stacktop 5.display 6.exit\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element:");
            scanf("%d", &ele);
            push(&sobj, ele);
            break;
        case 2:
            if (!isEmpty(&sobj))
            {
                ele = pop(&sobj);
                printf("the element poppped is %d\n", ele);
                break;
            }
            else
            {
                printf("stack is empty!!\n");
                break;
            }
        case 3:
            if (isEmpty(&sobj))
                printf("stack is empty!!\n");
            else
                printf("stack is not empty\n");
            break;
        case 4:
            if (!isEmpty(&sobj))
            {
                ele = stacktop(&sobj);
                printf("stack top is %d\n", ele);
            }
            else
            {
                printf("stack is empty!!\n");
            }
            break;
        case 5:
            display(&sobj);
            break;
        case 6:
            exit(0);
        }

    } while (choice < 15);
    destroy(&sobj);
}

void initstack(STCK *pl)
{
    pl->top = NULL;
}
NODE *createnode(STCK *pl, int ele)
{
    NODE *p = malloc(sizeof(NODE));
    p->info = ele;
    p->next = NULL;
    return p;
}

void push(STCK *pl, int ele)
{
    NODE *p = createnode(pl, ele);
    p->next = pl->top;
    pl->top = p;
}
int pop(STCK *pl)
{
    int pe;
    NODE *p = pl->top;
    pe = p->info;
    pl->top = pl->top->next;
    free(p);
    return pe;
}
int isEmpty(STCK *pl)
{
    return pl->top == NULL;
}
int stacktop(STCK *pl)
{
    return pl->top->info;
}
void display(STCK *ps)
{
    if (ps->top == NULL)
        printf("Stack is Empty\n");
    else
    {
        NODE *p = ps->top;

        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
    }
}
void destroy(STCK *pl)
{
    NODE *p;
    while (pl->top != NULL)
    {
        p = pl->top;
        pl->top = pl->top->next;
        printf("deleted ele is %d", p->info);
        free(p);
    }
}
