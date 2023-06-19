#pragma once
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <set>
#include <vector>
#include "TextBox.h"
#include "Path.h"
#include "Barrier.h"
#include "Button.h"
#include "Block.h"
#include "Method.h"
using namespace std;

class Button;

//界面交互类
class UI
{
public:
	static int m, n;//用于记录迷宫的宽度和高度
	static int x1, y1;//用于记录设置起点的位置
	static int x2, y2;//用于记录设置终点的位置
	set<Barrier> barriers;//存放玩家设置的迷宫障碍点
	vector<Button> buttons;//存放交互用到的按钮
	ExMessage msg;//界面的鼠标消息
	Method method;//迷宫寻路算法的解决和动画对象
	static int UIType;//1为初始界面，2为设置障碍点界面，3为设置起点界面，4为设置终点界面，5为寻路界面

	UI();
	~UI();

	//绘图
	void drawInit();//绘制和初始化界面
	void drawText();//绘制提示文字
	void drawUI();//绘制每一帧用户交互界面
	void drawMap();//绘制每一帧地图
	void drawAnimation();//绘制动画
	void draw();//绘制每一帧
	void show();

	//鼠标的消息处理
	bool inMap(ExMessage msg);//判断鼠标是否在地图中
	void setFocus();//使鼠标的光标集中于放置的路径点
	void setBarrier();//点击事件驱动设置/删除障碍点
	void setBeginPoint();//点击事件驱动设置/删除起点
	void setEndPonit(); //点击事件驱动设置 / 删除终点

	//按钮空间点击的回调函数，大多用于界面的切换
	static void barrierClick();
	static void beginClick();
	static void EndClick();
	static void mazeClick();
	static void EscClick();
	static void DFSClick();
	static void BFSClick();
	static void ClearClick();
	static void ResetClick();
};


