#pragma once
#include <iostream>
#include <graphics.h>
#include "Block.h"
#define MAX 100
using namespace std;

//���Ʒ��ϰ���Ĺ�����
class Path : public Block
{
public :
	Path(int x, int y);
	void drawBlock();
	static void drawPath(int x,int y);//����δ��·����
	static void drawFocusPath(int x, int y);//������꽹���·����
	static void drawMethodePath(int x, int y);//�����Ѿ��ߵ�·����
	static void drawMethodeDFSPath(int x, int y);//������������·����
};
