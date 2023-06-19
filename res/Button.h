#pragma once
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "UI.h"
using namespace std;

//��ť�ؼ���
class Button
{
private:
	int x, y;//��ťλ��
	int w, h;//��ť���
	wchar_t* text;//��ť�ı�
	void (*userfunc)();//��ť�Ļص�����
public:
	Button(int x, int y, int w, int h, const wchar_t* text, void (*func)());
	~Button();
	void drawButton(ExMessage msg);//���Ʋ�ͬ����µİ�ť
	bool onFocus(ExMessage msg);//�ж���꽹���Ƿ��ڰ�ť��
	bool isClick(ExMessage msg);//�ж�����Ƿ�����ť
	void onMessage();//�ص�������ִ��
};

