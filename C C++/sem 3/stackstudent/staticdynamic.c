#include <stdio.h>
#include <stdlib.h>
#define MAX 3
typedef struct stack
{
	int top;
	int *a;
	int SIZE; // Length of the dynamic array or Max elts that can be stored in stack
} STACK;

void initStack(STACK *ps, int n);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, int ele);
int pop(STACK *ps);
int stackTop(STACK *ps);
void display(STACK *ps);
// void doubleStackSize(STACK *ps);
// void destroyStack(STACK *ps);

int main()
{
	STACK s;

	int n = 3;

	initStack(&s, n); // List is initisized to be empty

	int choice, ele, status;

	printf("1.Push 2.Pop 3.Isfull 4.IsEmpty 5.StackTop 6.Display\n");
	scanf("%d", &choice);
	do
	{
		switch (choice)
		{
		case 1:
			printf("Enter an integer\n");
			scanf("%d", &ele);
			push(&s, ele);
			break;
		case 2:
			if (!isEmpty(&s))
			{
				ele = pop(&s);
				printf("Popped %d\n", ele);
			}
			else
				printf("Stack is already empty\n");
			break;
		case 3:
			display(&s);
			break;
		case 4:
			if (!isEmpty(&s))
			{
				ele = stackTop(&s);
				printf("Top ele %d\n", ele);
			}
			else
				printf("Stack is already empty\n");
			break;
		case 5:
			if (isFull(&s))
				printf("Stack has %d elements\n", s.SIZE);
			break;
		}
		printf("1.Push 2.Pop 3.Display4.StackTop 5.IsFull\n");
		scanf("%d", &choice);
	} while (choice < 6);

	// destroyStack(&s);
}

void initStack(STACK *ps, int n)
{
	ps->top = -1;
	ps->SIZE = n;
	ps->a = malloc(n * sizeof(int)); // ps->a=malloc(ps->SIZE*sizeof(int));
}
int isFull(STACK *ps)
{
	return ps->top == ps->SIZE - 1;
}
int isEmpty(STACK *ps)
{
	return ps->top == -1;
}
void push(STACK *ps, int ele)
{
	/*if(isFull(ps))
		doubleStackSize(ps);*/
	ps->top++;
	ps->a[ps->top] = ele;

	// ps->a[++(ps->top)]=ele;
}
int pop(STACK *ps)
{
	int poppedEle = ps->a[ps->top];
	ps->top--;

	return poppedEle;

	// return ps->a[ps->top--];
}
int stackTop(STACK *ps)
{
	return ps->a[ps->top];
}
void display(STACK *ps)
{
	if (ps->top == -1)
		printf("Empty Stack\n");
	else
	{
		for (int i = ps->top; i >= 0; i--)
			printf("%d ", ps->a[i]);
	}
	printf("\n");
}

/*
void doubleStackSize(STACK *ps)
{
	ps->SIZE=ps->SIZE*2;
	ps->a=realloc(ps->a,ps->SIZE*sizeof(int));
}
void destroyStack(STACK *ps)
{
	free(ps->a);
	ps->SIZE=0;
	ps->top=-1;
}
*/
