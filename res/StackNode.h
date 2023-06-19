#pragma once
#include <iostream>
using namespace std;

//栈节点和栈的相关算法
class StackNode
{
public:
	int x;
	int y;
	int d;
	StackNode* next;
	//静态方法作为工具类
	StackNode();
	StackNode(int x, int y, int d);
	~StackNode();

	//初始化
	static void initStack(StackNode*& s);

	static void destroyStack(StackNode*& s);

	static bool StackEmpty(StackNode* s);

	static bool Push(StackNode*& s,int x,int y,int d);

	static bool Pop(StackNode*& s,int &x,int &y,int &d);

	static bool GetTop(StackNode* s, int& x, int& y, int& d);

	static bool ChangeTopD(StackNode*& s, int d);
};

