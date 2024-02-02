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

void initList(LLIST *pl);
void insertFront(LLIST *pl, int ele);
void insertLast(LLIST *pl, int ele);
void insertAtpos(LLIST *pl, int ele, int pos);
void display(LLIST *pl);
void deleteFront(LLIST *pl, int *pe);
void deleteLast(LLIST *pl, int *pe);
void deleteAtpos(LLIST *pl, int *pe, int pos);
int searchkey(LLIST *pl, int ele);
void destroyList(LLIST *pl);

int main()
{
	LLIST lobj;

	initList(&lobj);
	int choice, ele, pos;

	do
	{
		printf("1.InsertFront 2.InsertLast 3.InsertAtpos 4.Display 5.DeleteFront 6.DeleteLast 7.DeleteAtpos 8.Destroy 9.Searchkey 10.exit\n");
		printf("enter the choice\n");
		scanf("%d", &choice);
		switch (choice)
		{

		case 1:
			printf("enter the element\n");
			scanf("%d", &ele);
			insertFront(&lobj, ele);
			break;
		case 2:
			printf("enter the element\n");
			scanf("%d", &ele);
			insertLast(&lobj, ele);
			break;
		case 3:
			printf("enter the element\n");
			scanf("%d", &ele);
			printf("enter the pos\n");
			scanf("%d", &pos);
			insertAtpos(&lobj, ele, pos);
			break;
		case 4:
			display(&lobj);
			break;
		case 5:
			deleteFront(&lobj, &ele);
			printf("deleted element is %d\n", ele);
			break;
		case 6:
			deleteLast(&lobj, &ele);
			printf("deleted element is %d\n", ele);
			break;
		case 7:
			printf("enter the pos\n");
			scanf("%d", &pos);
			deleteAtpos(&lobj, &ele, pos);
			printf("deleted element is %d\n", ele);
			break;

		case 8:
			destroyList(&lobj);
			break;

		case 9:
			printf("enter the search element\n");
			scanf("%d", &ele);
			pos = searchkey(&lobj, ele);

			if (pos > -1)
				printf("found at %d\n", pos);
			else
				printf("not found\n");

			break;
		}
	} while (choice < 10);
}
void initList(LLIST *pl)
{
	pl->head = NULL;
}

NODE *getnode(int ele)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = ele;
	temp->next = NULL;
	return temp;
}

void insertFront(LLIST *pl, int ele)
{
	NODE *temp = getnode(ele);

	temp->next = pl->head;
	pl->head = temp;
}

void insertLast(LLIST *pl, int ele)
{
	NODE *temp = getnode(ele);
	if (pl->head == NULL)
	{
		pl->head = temp;
		return;
	}
	/*
	NODE *p;
	p=pl->head;
	*/
	NODE *p = pl->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
}

void insertAtpos(LLIST *pl, int ele, int pos)
{
	NODE *temp = getnode(ele);
	if (pos == 0)
	{
		temp->next = pl->head;
		pl->head = temp;
		return;
	}
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

void display(LLIST *pl)
{
	NODE *p = pl->head;
	if (pl->head == NULL)
	{
		printf("Empty list\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d", p->info);
		p = p->next;
	}
	printf("\n");
}

void deleteFront(LLIST *pl, int *pe)
{
	NODE *p = pl->head;
	pl->head = p->next;
	*pe = p->info;
	free(p);
}

/*void deleteLast(LLIST *pl, int *pe)
{
	NODE *p = pl->head;
	NODE *q = NULL;
	if (p->next == NULL)
	{
		pl->head = NULL;
		*pe = p->info;
		free(p);
		return;
	}

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
	}
	q->next = NULL;
	*pe = p->info;
	free(p);
}*/
void deleteLast(LLIST *pl, int *pe)
{
	NODE *temp = pl->head;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	*pe = temp->next->info;
	free(temp->next);
	temp->next = NULL;
}
int countNodes(LLIST *pl)
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
void deleteAtpos(LLIST *pl, int *pe, int pos)
{
	NODE *p = pl->head;
	NODE *q = NULL;
	int n = countNodes(pl);
	if (pos < 0 || pos > n)
	{
		printf("pos is out of range\n");
		return;
	}
	if (pl->head == NULL)

		return;
	if (pos == 0)
	{
		pl->head = NULL;
		*pe = p->info;
		free(p);
		return;
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

int searchkey(LLIST *pl, int ele)
{
	NODE *p = pl->head;
	int pos = -1;
	while (p != NULL)
	{
		if (p->info == ele)
		{
			pos++;
			return pos;
		}
		pos++;
		p = p->next;
	}
	return -1;
}
void destroyList(LLIST *pl)
{
	NODE *p = pl->head;
	NODE *q = NULL;

	while (p != NULL)
	{
		q = p;
		// printf("%d",p->info);
		p = p->next;
		free(q);
	}
	pl->head = NULL;
}
