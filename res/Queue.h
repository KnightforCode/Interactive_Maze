#pragma once
#include <iostream>
#include <malloc.h>
#include "QueueNode.h"
#define MAX_LENGTH 1000
using namespace std;

//队列相关算法
class Queue
{	
public:
	QueueNode data[MAX_LENGTH];
	int front, rear;
	Queue();
	~Queue();
	static void initQueue(Queue*& q);
	static void destoryQueue(Queue*& q);
	static bool QueueEmpty(Queue* q);
	static bool enQueue(Queue*& q, int x, int y, int pre);
	static bool deQueue(Queue*& q, int& x, int& y, int& pre);
};

