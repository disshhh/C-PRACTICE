//Stack

#include<stdio.h>
#define MAX 5
typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
int push(STACK *ps,int ele);
int pop(STACK *ps,int *pe);
int stackTop(STACK *ps,int *pe);
void display(STACK *ps);

int main()
{
	STACK s;
	//s.top=-1;
	initStack(&s);
	int choice,ele;
	printf("1.push 2.pop 3.isfull 4.isempty 5.stacktop 6.display\n");
		
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("enter an integer\n");
			       scanf("%d",&ele);
				   if(push(&s,ele))
					   printf("%d pushed successfully\n",ele);
				   else
					   printf("stack overflow");
			       break;
			case 2:if(pop(&s,&ele))
				       printf("popped %d\n",ele);
			       else
					   printf("stack underflow\n");
				   break;
			case 3:if(isFull(&s))
					   printf("stack overflow/full\n");
			       else
					   printf("stack not full\n");
				   break;
			case 4:if(isEmpty(&s))
					   printf("stack is empty\n");
			       else
					   printf("stack is not empty\n");
				   break;
			case 5:if(stackTop(&s,&ele))
					   printf("stack Top is %d\n",ele);
			       else
					   printf("stack is empty\n");
				   break;	  
			case 6:display(&s);
                   break;			
					
		}
	printf("1.push 2.pop 3.isfull 4.isempty 5.stacktop 6.display\n");
		
	printf("Enter your choice\n");
	scanf("%d",&choice);
		
	}while(choice<7);
return 0;
}


void initStack(STACK *ps)
{
	ps->top=-1;
	
}
int isFull(STACK *ps)
{
	return ps->top==MAX-1;
	
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;

}
int push(STACK *ps,int ele)
{
	if(isFull(ps))
		return 0;
	ps->top++;
	ps->s[ps->top]=ele;
	return 1;

   //	ps->s[++ps->top]=ele;
   //return 1;
	
}
int pop(STACK *ps,int *pe)
{
	if(isEmpty(ps))
		return 0;
	
	*pe=ps->s[ps->top];
	ps->top--;
	return 1;
	
	//*pe=ps->s[ps->top--];
	//return 1;
	
}
int stackTop(STACK *ps,int *pe)
{
	if(isEmpty(ps))
		return 0;
	
	*pe=ps->s[ps->top];
	return 1;

}
void display(STACK *ps)
{
	if(isEmpty(ps))
	{
		printf("stack is empty\n");
		return ;
	}
	for(int i=ps->top;i>=0;i--)
    {
		printf("%d",ps->s[i]);
		
	}	
  printf("\n");	
		
}