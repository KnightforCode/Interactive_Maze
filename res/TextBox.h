#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;


//�ı�����
class TextBox
{
public:
	int x, y;//�ı����λ��
	int w, h;//�ı���Ŀ��
	wchar_t* text;//�ı��������
	size_t maxlen;//�ı���������������
	TextBox(int x, int y, int w, int h,int maxlen);
	~TextBox();
	void drawTextBox(ExMessage msg);//���Ʋ�ͬ����µ��ı���
	bool onFocus(ExMessage msg);//�ж���꽹���Ƿ������ı���
	bool isClick(ExMessage msg);//�ж�����Ƿ����ı���
};

