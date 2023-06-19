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

//���潻����
class UI
{
public:
	static int m, n;//���ڼ�¼�Թ��Ŀ�Ⱥ͸߶�
	static int x1, y1;//���ڼ�¼��������λ��
	static int x2, y2;//���ڼ�¼�����յ��λ��
	set<Barrier> barriers;//���������õ��Թ��ϰ���
	vector<Button> buttons;//��Ž����õ��İ�ť
	ExMessage msg;//����������Ϣ
	Method method;//�Թ�Ѱ·�㷨�Ľ���Ͷ�������
	static int UIType;//1Ϊ��ʼ���棬2Ϊ�����ϰ�����棬3Ϊ���������棬4Ϊ�����յ���棬5ΪѰ·����

	UI();
	~UI();

	//��ͼ
	void drawInit();//���ƺͳ�ʼ������
	void drawText();//������ʾ����
	void drawUI();//����ÿһ֡�û���������
	void drawMap();//����ÿһ֡��ͼ
	void drawAnimation();//���ƶ���
	void draw();//����ÿһ֡
	void show();

	//������Ϣ����
	bool inMap(ExMessage msg);//�ж�����Ƿ��ڵ�ͼ��
	void setFocus();//ʹ���Ĺ�꼯���ڷ��õ�·����
	void setBarrier();//����¼���������/ɾ���ϰ���
	void setBeginPoint();//����¼���������/ɾ�����
	void setEndPonit(); //����¼��������� / ɾ���յ�

	//��ť�ռ����Ļص�������������ڽ�����л�
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


