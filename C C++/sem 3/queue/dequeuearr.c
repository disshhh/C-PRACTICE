#include <stdio.h>
#define MAX 5
typedef struct queue
{
    int q[MAX];
    int front;
    int rear;

} QUEUE;

void initqueue(QUEUE *pq)
{
    pq->front = -1;
    pq->rear = -1;
}
void isempty(QUEUE *pq)
{
    return pq->front == -1;
}
void enqueuerear(QUEUE *pq, int ele)
{
    if (isempty(pq))
    {
        pq->front = 0;
        pq->front = 0;
        pq->q[0] = ele;
    }
    else
    {
        pq->rear = (pq->rear + 1) % MAX;
        pq->q[pq->rear] = ele;
    }
}
void dequeuefront(QUEUE *pq)
{
    int ele = pq->q[pq->front];
    if (pq->front == pq->rear)
    {
        initqueue(pq);
    }
    else
    {
        pq->front = (pq->front + 1) % MAX;
    }
    return ele;
}
void enqueuefront(QUEUE *pq, int ele)
{
    if (isempty(pq))
    {
        pq->front = 0;
        pq->front = 0;
        pq->q[0] = ele;
    }
    else
    {
        pq->front = (pq->front - 1 + MAX) % MAX;
        pq->q[pq->front] = ele;
    }
}

void display(QUEUE *pq)
{
    for (int i = pq->front)
}
void enqueurear(QUEUE *pq, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->prev = NULL;
    temp->info = ele;

    if (isempty(pq))
    {
        pq->front = newnode;
        pq->rear = newnodel;
    }
    newnode->prev = pq->rear;
    pq->rear->next = newnode;
    pq->rear = newnode;
}
void enqueurear(QUEUE *pq, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->prev = NULL;
    temp->info = ele;

    if (isempty(pq))
    {
        pq->front = newnode;
        pq->rear = newnodel;
    }
    newnode->next = pq->front;
    pq->front->prev = newnode;
    pq->front = newnode;
}
void dequeuefront(QUEUE *pq)
{
    int ele = pq->front->info;
    if (pq->front == pq->rear)
    {
        free(pq->front);
        pq->front = NULL;
        pq->rear = NULL;
    }
    else
    {
        pq->front = pq->front->next;
        free(pq->front->rear);
        pq->front->rear = NULL;
    }
    return ele;
}

void enqueue(QUEUE *pq)
{
    pq->rear++;
    pq->q[pq->rear] = ele;
}
void dequeu(QUEUE *pq)
{
    int ele = pq->q[pq->front];
    pq->front++;
}