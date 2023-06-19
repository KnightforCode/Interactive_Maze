#pragma once
#include <iostream>
#include <graphics.h>
#include "Block.h"
#define MAX 100
using namespace std;

//绘制非障碍点的工具类
class Path : public Block
{
public :
	Path(int x, int y);
	void drawBlock();
	static void drawPath(int x,int y);//绘制未走路径点
	static void drawFocusPath(int x, int y);//绘制鼠标焦点的路径点
	static void drawMethodePath(int x, int y);//绘制已经走到路径点
	static void drawMethodeDFSPath(int x, int y);//绘制搜索过的路径点
};
