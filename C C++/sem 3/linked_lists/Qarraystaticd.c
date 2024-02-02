#include<stdio.h>
#define MAX 3

typedef struct queue
{
	int q[MAX];
	int front,rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq);
void display(QUEUE *pq);


int main()
{
	QUEUE q;
	
	initQueue(&q);
	
	int ele,choice;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.isFull 4.is Empty 5.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					if(!isFull(&q))
						enqueue(&q,ele);
					else
						printf("Queue is already full\n");
					break;
			case 2:if(!isEmpty(&q))	
						printf("Deqd %d\n",dequeue(&q));
					else
						printf("Q is already empty\n");
					break;
			case 3:if(isFull(&q))	
						printf("Queue Full\n");
					else
						printf("Queue can take elements\n");
					break;
			case 4:if(isEmpty(&q))	
						printf("Queue Empty\n");
					else
						printf("Queue is not empty\n");
					break;		
			case 5:display(&q);
					break;
		}
	}while(choice<6);
}




void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}
void enqueue(QUEUE *pq,int ele)
{
	pq->rear++;
	pq->q[pq->rear]=ele;
}

int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	pq->front++;
	return ele;
	
	//return pq->q[pq->front++];
	
}

int isEmpty(QUEUE *pq)
{
	return pq->front>pq->rear;
	
}
int isFull(QUEUE *pq)
{
	return pq->rear==MAX-1;
	
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Queue is empty");
		return;
	}
	for(int i=pq->front;i<=pq->rear;i++)
	{
		printf("%d",pq->q[i]);
	}
	
	printf("\n");	
}