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

void initqueue(QUEUE *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}
int isempty(QUEUE *pq)
{
    return pq->front = NULL;
}

void enqueue(QUEUE *pq, int ele)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->info = ele;
    if (isempty(pq))
    {
        newnode->next = newnode;
        pq->front = newnode;
        pq->rear = newnode;
    }
    else
    {
        pq->rear->next = newnode;
        pq->rear = newnode;
    }
}
int dequeue(QUEUE *pq)
{
    int ele = pq->front->info;
    if (pq->front == pq->rear)
    {
        initqueue(pq);
        free(pq->front);
    }
    else
    {
        NODE *q = pq->front;
        pq->front = pq->front->next;
        free(q);
    }
    return ele;
}
void display(QUEUE *pq)
{
    for (int i = pq->front; i != pq->rear; i = (i + 1) % MAX)
    {
        printf("%d", pq->q[i]);
    }
}