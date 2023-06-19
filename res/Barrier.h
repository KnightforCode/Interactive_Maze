#pragma once
#include <iostream>
#include <graphics.h>
#include "Block.h"
using namespace std;

//障碍点绘制工具类
class Barrier : public Block
{
public :
	Barrier(int x, int y);
	void drawBlock();
	static void drawBarrier(int x,int y);//绘制障碍点
	const bool operator<(const Barrier& B) const;// < 运算符的重载，为了Barrier能实现在x,y不一致的情况下加入到set容器中
};
