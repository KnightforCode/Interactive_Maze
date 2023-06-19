#include "Queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{
}

void Queue::initQueue(Queue*& q)
{
	q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = -1;
}

void Queue::destoryQueue(Queue*& q)
{
	delete q;
}

bool Queue::QueueEmpty(Queue* q)
{
	return q->front == q->rear;
}

bool Queue::enQueue(Queue*& q, int x, int y, int pre)
{
	if (q->rear == MAX_LENGTH - 1) return false;
	else
	{
		q->rear++;
		q->data[q->rear].x = x;
		q->data[q->rear].y = y;
		q->data[q->rear].pre = pre;
		return true;
	}
}

bool Queue::deQueue(Queue*& q, int& x, int& y, int& pre)
{
	if (q->rear == q->front) return false;
	else
	{
		q->front++;
		x = q->data[q->front].x;
		y = q->data[q->front].y;
		pre = q->data[q->front].pre;
		return true;
	}
}
