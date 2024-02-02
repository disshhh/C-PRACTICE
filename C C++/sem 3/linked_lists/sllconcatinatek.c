#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node* concat_lists(struct node *list1,struct node *list2);
void display(struct node *head);

struct node* insertBeg(struct node *head,int ele)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->info=ele;
	temp->next=NULL;
	
	temp->next=head;
	head=temp;
	return head;
}

int main()
{
	int n,ele;
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	printf("List1 nodes\n");
	printf("enter the no of elements need to be entered into list1\n");
	scanf("%d",&n);
	
	printf("enter the elements for list1\n");
	for(int i=0;i<n;i++)
	{
		
		scanf("%d",&ele);
		head1=insertBeg(head1,ele);
	}
	printf("\n");
	display(head1);
	
	printf("List2 nodes\n");
	printf("enter the no of elements need to be entered into list1\n");
	scanf("%d",&n);
	printf("enter the elements for list2\n");
	for(int i=0;i<n;i++)
	{
		
		scanf("%d",&ele);
		head2=insertBeg(head2,ele);
	}
	printf("\n");
	display(head2);
	head3=concat_lists(head1,head2);
	printf("\n");
    display(head3);
	return 0;
}

struct node* concat_lists(struct node *list1,struct node *list2)
{
	struct node *ptr;
	if(list1==NULL)
	{
		list1=list2;
		return list1;
	}
	if(list2==NULL)
		return list1;
	ptr=list1;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=list2;
	return list1;
}

void display(struct node *head)	
{
	
	struct node *p=head;
	if(head==NULL)
	{
		printf("Empty lIST");
		return;
	}
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
	
}