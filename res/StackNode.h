#pragma once
#include <iostream>
using namespace std;

//ջ�ڵ��ջ������㷨
class StackNode
{
public:
	int x;
	int y;
	int d;
	StackNode* next;
	//��̬������Ϊ������
	StackNode();
	StackNode(int x, int y, int d);
	~StackNode();

	//��ʼ��
	static void initStack(StackNode*& s);

	static void destroyStack(StackNode*& s);

	static bool StackEmpty(StackNode* s);

	static bool Push(StackNode*& s,int x,int y,int d);

	static bool Pop(StackNode*& s,int &x,int &y,int &d);

	static bool GetTop(StackNode* s, int& x, int& y, int& d);

	static bool ChangeTopD(StackNode*& s, int d);
};

