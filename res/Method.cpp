#include "Method.h"


Method::Method()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			mg[i][j] = -1;
	}
}

void Method::setMG(int m, int n, const set<Barrier> barriers)
{
	int i, j;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
			mg[i][j] = -1;
	}

	for (i = 0; i < n + 2; i++)
	{
		for (j = 0; j < m + 2; j++)
			mg[i][j] = 0;
	}

	//围墙
	for(j = 0; j < m + 2; j++)
	{
		mg[0][j] = 1;
		mg[n + 1][j] = 1;
	}
	for (i = 1; i < n + 1; i++)
	{
		mg[i][0] = 1;
		mg[i][m + 1] = 1;
	}

	//用户设置的障碍点
	for (set<Barrier>::iterator it = barriers.begin(); it != barriers.end(); it++)
	{
		i = it->x / 30;
		j = it->y / 30;
		mg[j][i] = 1;
	}

}

bool Method::drawDFS(int xi, int yi, int xe, int ye)
{
	StackNode::initStack(s);
	int x, y, d;
	mg[xi][yi] = 2;
	StackNode::Push(s, xi, yi, -1);
	int i = 0;
	while (!StackNode::StackEmpty(s))
	{
		StackNode::GetTop(s, x, y, d);
		if (x == xe && y == ye)
		{
			StackNode::destroyStack(s);
			return true;
		}
		else
		{
			while (d < 4)
			{
				if (d == 0)//上
				{
					if (mg[x - 1][y] == 0)
					{
						StackNode::ChangeTopD(s, d);
						mg[x - 1][y] = 2;
						StackNode::Push(s, x - 1, y, -1);
						break;
					}
				}
				if (d == 1)//右
				{
					if (mg[x][y + 1] == 0)
					{
						StackNode::ChangeTopD(s, d);
						mg[x][y + 1] = 2;
						StackNode::Push(s, x, y + 1, -1);
						break;
					}
				}
				if (d == 2)//下
				{
					if (mg[x + 1][y] == 0)
					{
						StackNode::ChangeTopD(s, d);
						mg[x + 1][y] = 2;
						StackNode::Push(s, x + 1, y, -1);
						break;
					}
				}
				if (d == 3)//左
				{
					if (mg[x][y - 1] == 0)
					{
						StackNode::ChangeTopD(s, d);
						mg[x][y - 1] = 2;
						StackNode::Push(s, x, y - 1, -1);
						break;
					}
				}
				d++;
			}
			if (d == 4)
			{
				StackNode::Pop(s, x, y, d);
				mg[x][y] = 0;
				StackNode::GetTop(s, x, y, d);
				d++;
				StackNode::ChangeTopD(s, d);
			}
		}
		drawMapPath();
		drawPoint(xi, yi, xe, ye);
		Sleep(100);
	}
	StackNode::destroyStack(s);
	return false;
}

bool Method::drawBFS(int xi, int yi, int xe, int ye)
{
	int x, y, pre;
	Queue::initQueue(q);
	Queue::enQueue(q, xi, yi, -1);
	mg[xi][yi] = 2;
	while (!Queue::QueueEmpty(q))
	{
		Queue::deQueue(q, x, y, pre);
		if (x == xe && y == ye)
		{
			while (pre >= 0) {
				mg[x][y] = 2;
				x = q->data[pre].x;
				y = q->data[pre].y;
				pre = q->data[pre].pre;
				drawMapPath();
				drawPoint(xi, yi, xe, ye);
				Sleep(100);
			}
			Queue::destoryQueue(q);
			return true;
		}
		else
		{
			if (mg[x + 1][y] == 0) {
				Queue::enQueue(q, x + 1, y, q->front);
				mg[x + 1][y] = 3;
			}
			if (mg[x - 1][y] == 0) {
				Queue::enQueue(q, x - 1, y, q->front);
				mg[x - 1][y] = 3;
			}
			if (mg[x][y + 1] == 0) {
				Queue::enQueue(q, x, y + 1, q->front);
				mg[x][y + 1] = 3;
			}
			if (mg[x][y - 1] == 0) {
				Queue::enQueue(q, x, y - 1, q->front);
				mg[x][y - 1] = 3;
			}
		}
		drawMapPath();
		drawPoint(xi, yi, xe, ye);
		Sleep(10);
	}
	Queue::destoryQueue(q);
	return false;
}

void Method::drawMapPath()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			//绘制障碍
			if (mg[i][j] == 1)
				Barrier::drawBarrier(j * 30, i * 30);
			//绘制可走路径点
			if (mg[i][j] == 0)
				Path::drawPath(j * 30, i * 30);
			//绘制已走路径点
			if (mg[i][j] == 2)
				Path::drawMethodePath(j * 30, i * 30);
			//绘制BFS的搜索路径
			if (mg[i][j] == 3)
				Path::drawMethodeDFSPath(j * 30, i * 30);
		}
	}
}

void Method::drawPoint(int xi, int yi, int xe, int ye)
{
	setfillcolor(GREEN);
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	fillcircle(yi * 30 + 15, xi * 30 + 15, 15);

	setfillcolor(YELLOW);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 2);
	fillcircle(ye * 30 + 15, xe * 30 + 15, 15);
}

