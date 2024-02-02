#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
} NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
} QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, int ele);
int dequeue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);

int main()
{
	QUEUE qobj;

	initQueue(&qobj);

	int ele, choice;

	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the integer data\n");
			scanf("%d", &ele);
			enqueue(&qobj, ele);
			break;
		case 2:
			if (!isEmpty(&qobj))
			{
				ele = dequeue(&qobj);
				printf("Deqd %d\n", ele);
			}
			else
				printf("Queue is already empty\n");
			break;
		case 3:
			display(&qobj);
			break;
		}
	} while (choice < 4);
	destroyQueue(&qobj);
}

void initQueue(QUEUE *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

void enqueue(QUEUE *pq, int ele)
{
	NODE *newNode = malloc(sizeof(NODE));
	newNode->info = ele;
	newNode->next = NULL;

	if (isEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

int dequeue(QUEUE *pq)
{
	int ele = pq->front->info;
	if (pq->front == pq->rear) // Single node
	{
		free(pq->front);
		pq->front = NULL;
		pq->rear = NULL;
	}
	else
	{
		NODE *p = pq->front;
		pq->front = pq->front->next;
		free(p);
	}
	return ele;
}

int isEmpty(QUEUE *pq)
{
	return pq->front == NULL; // return pq->rear==NULL;
}

void display(QUEUE *pq)
{
	if (isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		NODE *p = pq->front;

		while (p != NULL)
		{
			printf("%d ", p->info);
			p = p->next;
		}
	}
}

void destroyQueue(QUEUE *pq)
{
	if (!isEmpty(pq))
	{
		NODE *p;

		while (pq->front != NULL)
		{
			p = pq->front;
			pq->front = pq->front->next;
			free(p);
		}
		pq->rear = NULL;
	}
}