#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct stack
{
	int top;
	int s[MAX];
} STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, int ele);
int pop(STACK *ps);
int stackTop(STACK *ps);
void display(STACK *ps);

int main()
{
	STACK s;
	// s.top=-1;
	initStack(&s); // List is initisized to be empty

	int choice, ele, status;

	printf("1.Push 2.Pop 3.isFull 4.isEmpty 5.Stacktop/peek 6.Display\n");
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
			printf("Popped %d\n", pop(&s));
			break;
		case 3:
			if (isFull(&s))
				printf("stack overflow/full\n");
			else
				printf("stack not full");
			break;
		case 4:
			if (isEmpty(&s))
				printf("stack empty\n");
			else
				printf("stack is not empty\n");
			break;
		case 5:
			printf("Stack Top %d\n", stackTop(&s));

			break;
		case 6:
			display(&s);
			break;
		}
		printf("1.Push 2.Pop 3.isFull 4.isEmpty 5.Stacktop/peek 6.Display\n");
		scanf("%d", &choice);
	} while (choice < 7);
}

void initStack(STACK *ps)
{
	ps->top = -1;
}
int isFull(STACK *ps)
{
	return ps->top == MAX - 1;
}
int isEmpty(STACK *ps)
{
	return ps->top == -1;
}
void push(STACK *ps, int ele)
{
	ps->top++;
	ps->s[ps->top] = ele;

	// ps->a[++(ps->top)]=ele;
}
int pop(STACK *ps)
{
	int res = ps->s[ps->top];
	ps->top--;

	return res;

	// return ps->a[ps->top--];
}
int stackTop(STACK *ps)
{
	return ps->s[ps->top];
}
void display(STACK *ps)
{
	if (isEmpty(ps))
	{
		printf("stack is empty\n");
		return;
	}

	for (int i = ps->top; i >= 0; i--)
		printf("%d ", ps->s[i]);

	printf("\n");
}