#pragma once
#include <iostream>
#include <graphics.h>
#include "Block.h"
using namespace std;

//�ϰ�����ƹ�����
class Barrier : public Block
{
public :
	Barrier(int x, int y);
	void drawBlock();
	static void drawBarrier(int x,int y);//�����ϰ���
	const bool operator<(const Barrier& B) const;// < ����������أ�Ϊ��Barrier��ʵ����x,y��һ�µ�����¼��뵽set������
};
