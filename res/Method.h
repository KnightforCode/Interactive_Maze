#pragma once
#include <iostream>
#include <set>
#include "StackNode.h"
#include "Queue.h"
#include "Barrier.h"
#include "Path.h"
#define MAX 100
using namespace std;

//算法实现类
class Method
{
public:
	Method();
	int mg[MAX][MAX];//存储地图的数组
	StackNode* s;//栈
	Queue* q;//队列
	void setMG(int m,int n,const set<Barrier> barriers);//设置地图
	bool drawDFS(int xi, int yi, int xe, int ye);//绘制DFS算法和动画输出
	bool drawBFS(int xi, int yi, int xe, int ye);//绘制BFS算法和动画输出
	void drawMapPath();//绘制每一帧地图
	void drawPoint(int xi, int yi, int xe, int ye);//绘制起点和终点
};

