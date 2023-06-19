#pragma once
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "UI.h"
using namespace std;

//按钮控件类
class Button
{
private:
	int x, y;//按钮位置
	int w, h;//按钮宽高
	wchar_t* text;//按钮文本
	void (*userfunc)();//按钮的回调函数
public:
	Button(int x, int y, int w, int h, const wchar_t* text, void (*func)());
	~Button();
	void drawButton(ExMessage msg);//绘制不同情况下的按钮
	bool onFocus(ExMessage msg);//判断鼠标焦点是否在按钮上
	bool isClick(ExMessage msg);//判断鼠标是否点击按钮
	void onMessage();//回调函数的执行
};

