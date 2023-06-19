#include "UI.h"

UI::UI()
{
	drawInit();
}

UI::~UI()
{
	closegraph();
}

//��ͼ����
void UI::drawInit()
{
	buttons.clear();//��button�д�ŵ�����ȫ�����
	barriers.clear();//����ϰ���

	//��ʼ����
	TextBox tb1 = TextBox(130, 200, 50, 30, 3);
	TextBox tb2 = TextBox(330, 200, 50, 30, 3);
	Button b = Button(200, 300, 100, 40, L"ȷ��", NULL);
	Button b_ = Button(200, 350, 100, 40, L"�˳�", NULL);

	initgraph(500, 500);
	//initgraph(500, 500, SHOWCONSOLE);
	setbkcolor(DARKGRAY);
	cleardevice();
	setbkmode(TRANSPARENT);//ʹ����͸��������ͻ��

	settextcolor(CYAN);
	settextstyle(100, 0, L"matura mt script capitals");
	outtextxy(100, 50, L"�Թ�����");
	settextstyle(30, 0, L"matura mt script capitals");
	outtextxy(100, 200, L"��");
	outtextxy(300, 200, L"��");


	while (true) {
		settextcolor(BLACK);
		msg = getmessage(EX_MOUSE);
		tb1.drawTextBox(msg);
		tb2.drawTextBox(msg);
		b.drawButton(msg);
		b_.drawButton(msg);
		if (b.isClick(msg))
		{
			if (_wtoi(tb1.text) > 0 && _wtoi(tb2.text) > 0)
			{
				m = _wtoi(tb1.text);
				n = _wtoi(tb2.text);
				UIType = 1;
				break;
			}
			else
			{
				settextcolor(RED);
				settextstyle(35, 0, L"matura mt script capitals");
				outtextxy(130, 250, L"�������ݲ�����Ҫ��");
			}
		}
		if (b_.isClick(msg))
			exit(0);
	}

	//��ʼ����ͼ
	initgraph(30 * (m + 2) + 300, 30 * (n + 2) > 400 ? 30 * (n + 2) : 400);
	//initgraph(30 * (m + 2) + 300, 30 * (n + 2) > 400 ? 30 * (n + 2) : 400, SHOWCONSOLE);
	setbkcolor(DARKGRAY);
	cleardevice();


	//��ʼ���ؼ�
	Button b1 = Button(30 * (m + 2) + 100, 20, 100, 40, L"�����ϰ���", barrierClick);
	Button b2 = Button(30 * (m + 2) + 100, 90, 100, 40, L"�������", beginClick);
	Button b3 = Button(30 * (m + 2) + 100, 160, 100, 40, L"�����յ�", EndClick);
	Button b4 = Button(30 * (m + 2) + 100, 230, 100, 40, L"Ѱ��·��", mazeClick);
	Button b5 = Button(30 * (m + 2) + 100, 100, 100, 40, L"BFS", BFSClick);
	Button b6 = Button(30 * (m + 2) + 100, 150, 100, 40, L"DFS", DFSClick);
	Button b7 = Button(30 * (m + 2) + 100, 300, 100, 40, L"�˳�", EscClick);
	Button b8 = Button(30 * (m + 2) + 100, 250, 100, 40, L"���", ClearClick);
	Button b9 = Button(30 * (m + 2) + 100, 300, 100, 40, L"���ÿ��", ResetClick);
	buttons.push_back(b1);
	buttons.push_back(b2);
	buttons.push_back(b3);
	buttons.push_back(b4);
	buttons.push_back(b5);
	buttons.push_back(b6);
	buttons.push_back(b7);
	buttons.push_back(b8);
	buttons.push_back(b9);



	//��ʼ�����
	x1 = x2 = y1 = y2 = -1;
}

void UI::drawText()
{
	setbkmode(TRANSPARENT);//ʹ����͸��������ͻ��
	settextstyle(25, 0, L"Consolas");
	if (UIType == 2 || UIType == 3 || UIType == 4)
	{
		settextcolor(BLACK);
		outtextxy(30 * (m + 2) + 60, 90, L"������ã��Ҽ�ɾ��");
	}
}

void UI::drawUI()
{
	this->msg = getmessage(EX_MOUSE);
	//���Ƴ�ʼ����
	if (UIType == 0)
		drawInit();
	//���ƽ�������
	if (UIType == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			buttons[i].drawButton(msg);
			if (buttons[i].isClick(msg))
				buttons[i].onMessage();
		}
		buttons[8].drawButton(msg);
		if (buttons[8].isClick(msg))
			buttons[8].onMessage();
	}
	//���Ƴ������ϰ������
	if (UIType == 2)
	{
		this->setBarrier();
		drawText();
		for (int i = 6; i < 8; i++)
		{
			buttons[i].drawButton(msg);
			if (buttons[i].isClick(msg))
				buttons[i].onMessage();
		}
		if (buttons[7].isClick(msg))
			barriers.clear();
	}

	//���Ƴ�����������
	if (UIType == 3)
	{
		drawText();
		this->setBeginPoint();
		buttons[6].drawButton(msg);
		if (buttons[6].isClick(msg))
			buttons[6].onMessage();
	}

	//���Ƴ������յ����
	if (UIType == 4)
	{
		drawText();
		this->setEndPonit();
		buttons[6].drawButton(msg);
		if (buttons[6].isClick(msg))
			buttons[6].onMessage();
	}

	//���Ƴ�Ѱ·����
	if (UIType == 5)
	{
		for (int i = 4; i < 7; i++)
		{
			buttons[i].drawButton(msg);
			if (buttons[i].isClick(msg))
				buttons[i].onMessage();
		}
	}

	this->setFocus();
}

void UI::drawMap()
{
	setbkcolor(DARKGRAY);
	cleardevice();
	//��ʼ��·����
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Path::drawPath(30 * i, 30 * j);
		}
	}

	//��ʼ���ϰ���Χǽ
	Barrier::drawBarrier(0, 0);
	Barrier::drawBarrier(30 * (m + 1), 0);
	Barrier::drawBarrier(0, 30 * (n + 1));
	Barrier::drawBarrier(30 * (m + 1), 30 * (n + 1));
	for (int i = 1; i <= m; i++)
	{
		Barrier::drawBarrier(i * 30, 0);
		Barrier::drawBarrier(i * 30, 30 * (n + 1));
	}
	for (int i = 1; i <= n; i++)
	{
		Barrier::drawBarrier(0, i * 30);
		Barrier::drawBarrier(30 * (m + 1), i * 30);
	}

	for (set<Barrier>::iterator it = barriers.begin(); it != barriers.end(); it++) {
		Barrier::drawBarrier(it->x, it->y);
	}

	//�������
	if (x1 != -1 && y1 != -1)
	{
		setfillcolor(GREEN);
		setlinecolor(BLUE);
		setlinestyle(PS_SOLID, 2);
		fillcircle(x1 + 15, y1 + 15, 15);
	}

	//�����յ�
	if (x2 != -1 && y2 != -1)
	{
		setfillcolor(YELLOW);
		setlinecolor(RED);
		setlinestyle(PS_SOLID, 2);
		fillcircle(x2 + 15, y2 + 15, 15);
	}
}

void UI::drawAnimation()
{
	method.setMG(m, n, barriers);
	if (UIType == 6)
		method.drawDFS(y1 / 30, x1 / 30, y2 / 30, x2 / 30);
	if (UIType == 7)
		method.drawBFS(y1 / 30, x1 / 30, y2 / 30, x2 / 30);
}

void UI::draw()
{
	if (UIType == 6 || UIType == 7)//��ʾ����
	{
		drawAnimation();
		//չʾ·��
		Sleep(1000);
		UIType = 5;
	}
	else if(UIType != 0)//��ʾ��������
	{
		BeginBatchDraw();
		drawMap();
		drawUI();
		EndBatchDraw();
	}
	else
	{
		drawUI();
	}
}

void UI::show()
{
	while (true)
	{
		draw();
	}
}

//��Ϣ������
bool UI::inMap(ExMessage msg)
{
	if ((msg.x > 30 && msg.x < 30 * (m + 1))
		&& (msg.y > 30 && msg.y < 30 * (n + 1)))
		return true;
	else
		return false;
}

void UI::setFocus()
{
	if (inMap(msg))
	{
		int a = (msg.x / 30) * 30;
		int b = (msg.y / 30) * 30;
		Path::drawFocusPath(a, b);
	}
}

void UI::setBarrier()
{
	if (inMap(msg))
	{
		int a = (msg.x / 30) * 30;
		int b = (msg.y / 30) * 30;
		//����ڿ��е����
		if (msg.message == WM_LBUTTONDOWN)
			barriers.insert(Barrier(a, b));
		if (msg.message == WM_RBUTTONDOWN)
		{
			for (set<Barrier>::iterator it = barriers.begin(); it != barriers.end(); it++) {
				if (it->x == a && it->y == b)
				{
					barriers.erase(*it);
					break;
				}
			}
		}
	}
}

void UI::setBeginPoint()
{
	if (inMap(msg))
	{
		//����ڿ��е����
		if (msg.message == WM_LBUTTONDOWN)
		{
			bool flag = true;
			for (set<Barrier>::iterator it = barriers.begin(); it != barriers.end(); it++) {
				if (it->x == (msg.x / 30) * 30 && it->y == (msg.y / 30) * 30)
				{
					flag = false;
				}
			}
			if (flag)
			{
				x1 = (msg.x / 30) * 30;
				y1 = (msg.y / 30) * 30;
			}
		}
		if (msg.message == WM_RBUTTONDOWN)
		{
			if (x1 == (msg.x / 30) * 30 &&
				y1 == (msg.y / 30) * 30)
				x1 = y1 = -1;
		}
	}
}

void UI::setEndPonit()
{
	if (inMap(msg))
	{
		//����ڿ��е����
		if (msg.message == WM_LBUTTONDOWN)
		{
			bool flag = true;
			for (set<Barrier>::iterator it = barriers.begin(); it != barriers.end(); it++) {
				if (it->x == (msg.x / 30) * 30 && it->y == (msg.y / 30) * 30)
				{
					flag = false;
				}
			}
			if (flag)
			{
				x2 = (msg.x / 30) * 30;
				y2 = (msg.y / 30) * 30;
			}
		}
		if (msg.message == WM_RBUTTONDOWN)
		{
			if (x2 == (msg.x / 30) * 30 &&
				y2 == (msg.y / 30) * 30)
				x2 = y2 = -1;
		}
	}
}

//Ƕ�밴ť������¼�����Ļص�����
void UI::barrierClick()
{
	UIType = 2;
}

void UI::beginClick()
{
	UIType = 3;
}

void UI::EndClick()
{
	UIType = 4;
}

void UI::mazeClick()
{
	UIType = 5;
}

void UI::EscClick()
{
	UIType = 1;
}

void UI::DFSClick()
{
	if (x1 != -1 && y1 != -1 && x2 != -1 && y2 != -1)
	{
		UIType = 6;
	}
	else
	{
		setbkmode(TRANSPARENT);//ʹ����͸��������ͻ��
		settextstyle(25, 0, L"Consolas");
		settextcolor(RED);
		outtextxy(30 * (m + 2) + 30, 200, L"����������յ�����ã�");
		settextcolor(BLACK);
	}
}

void UI::BFSClick()
{
	if (x1 != -1 && y1 != -1 && x2 != -1 && y2 != -1)
	{
		UIType = 7;
	}
	else
	{
		setbkmode(TRANSPARENT);//ʹ����͸��������ͻ��
		settextstyle(25, 0, L"Consolas");
		settextcolor(RED);
		outtextxy(30 * (m + 2) + 30, 200, L"����������յ�����ã�");
		settextcolor(BLACK);
	}
}

void UI::ClearClick()
{
	
}

void UI::ResetClick()
{
	UIType = 0;
}


//��̬�����ĳ�ʼ��
int UI::UIType = 0;
int UI::m = 0;
int UI::n = 0;
int UI::x1 = -1;
int UI::y1 = -1;
int UI::x2 = -1;
int UI::y2 = -1;

