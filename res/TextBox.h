#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;


//文本框类
class TextBox
{
public:
	int x, y;//文本框的位置
	int w, h;//文本框的宽高
	wchar_t* text;//文本框的内容
	size_t maxlen;//文本框的最大文字限制
	TextBox(int x, int y, int w, int h,int maxlen);
	~TextBox();
	void drawTextBox(ExMessage msg);//绘制不同情况下的文本框
	bool onFocus(ExMessage msg);//判断鼠标焦点是否集中于文本框
	bool isClick(ExMessage msg);//判断鼠标是否点击文本框
};

