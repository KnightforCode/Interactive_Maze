#pragma once
#include <iostream>
#include <set>
#include "StackNode.h"
#include "Queue.h"
#include "Barrier.h"
#include "Path.h"
#define MAX 100
using namespace std;

//�㷨ʵ����
class Method
{
public:
	Method();
	int mg[MAX][MAX];//�洢��ͼ������
	StackNode* s;//ջ
	Queue* q;//����
	void setMG(int m,int n,const set<Barrier> barriers);//���õ�ͼ
	bool drawDFS(int xi, int yi, int xe, int ye);//����DFS�㷨�Ͷ������
	bool drawBFS(int xi, int yi, int xe, int ye);//����BFS�㷨�Ͷ������
	void drawMapPath();//����ÿһ֡��ͼ
	void drawPoint(int xi, int yi, int xe, int ye);//���������յ�
};

