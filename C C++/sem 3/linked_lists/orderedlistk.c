#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl);
void OrderedList(LLIST *pl,int ele);
void display(LLIST *pl);

int main()
{
	LLIST lobj;
	initList(&lobj);
	int choice,pos,ele;
	do
	{
		printf("1.Insert 2.Display 3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("enter an element\n");
					scanf("%d",&ele);
					OrderedList(&lobj,ele);
					break;
			case 2:display(&lobj);
				   break;			
			case 3:exit(1);
                   break;			
					}
	    }while(choice<4);
}		
void initList(LLIST *pl)
{
	pl->head=NULL;
}

NODE* getnode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
}		

void OrderedList(LLIST *pl,int ele)
{
	NODE *temp=getnode(ele);
	NODE *p=pl->head;
	NODE *q=NULL;
	
	if(p==NULL)
	{
		pl->head=temp;
		return;
	}
	
	while(p!=NULL && temp->info > p->info)
	{
		q=p;
		p=p->next;
		
	}
	
	if(p==pl->head)
	{
		temp->next=p;
		pl->head=temp;
		return;
	}
	q->next=temp;
	temp->next=p;
}

void display(LLIST *pl)
{
	NODE *p=pl->head;
	if(pl->head==NULL)
	{
		printf("Empty lIST");
		return;
	}
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
	printf("\n");
}