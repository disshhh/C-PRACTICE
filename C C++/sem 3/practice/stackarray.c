#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct stack
{
    int top;
    int arr[MAX];
} STCK;

void initstack(STCK *pl);
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
}

void initstack(STCK *pl)
{
    pl->top = -1;
}

void push(STCK *pl, int ele)
{
    pl->top++;
    pl->arr[pl->top] = ele;
}
int pop(STCK *pl)
{
    int res = pl->arr[pl->top];
    pl->top--;
    return res;
}
int isEmpty(STCK *pl)
{
    return pl->top == -1;
}
int stacktop(STCK *pl)
{
    return pl->arr[pl->top];
}
void display(STCK *ps)
{
    if (isEmpty(ps))
        printf("Stack is Empty\n");
    else
    {
        for (int i = ps->top; i >= 0; i--)
            printf("%d ", ps->arr[i]);
    }
}
