#include "TextBox.h"


TextBox::TextBox(int x, int y, int w, int h, int maxlen)
{
    this->x = x;
    this->y = y;
    this->w = w;
	this->h = h;
    this->maxlen = maxlen;
    text = new wchar_t[maxlen];
    text[0] = 0;
}

TextBox::~TextBox()
{

}

void TextBox::drawTextBox(ExMessage msg)
{
    if (this->isClick(msg))
    {
        setlinecolor(BLACK);
		settextstyle(20, 0, L"����");
		setlinestyle(PS_SOLID, 1);
        setfillcolor(WHITE);			
        fillrectangle(x, y, x + w, y + h);
        outtextxy(x + 10, y + 5, text);


		int width = textwidth(text);// �ַ����ܿ��
        int count = 0;// �����˸������
        bool flag = true;// �Ƿ�������

		while (flag)
		{
			while (flag && peekmessage(&msg, EX_MOUSE | EX_CHAR, false))//��ȡ��Ϣ���ж�����Ϣ
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					// ���������ı������棬�����ı�����
					if (!this->onFocus(msg))
					{
						flag = false;
						break;
					}
				}
				else if (msg.message == WM_CHAR)
				{
					size_t len = wcslen(text);
					switch (msg.ch)
					{
						case '\b'://�˸�
							if (len > 0)
							{
								text[len - 1] = 0;
								width = textwidth(text);
								count = 0;
								clearrectangle(x + 10 + width, y + 1, x + w - 1, y + h - 1);//�����ַ�������ʾ
							}
							break;
						case '\r':
						case '\n'://�س��ͻ���
							flag = false;
							break;
						default://�ı�����
							if (len < maxlen - 1)
							{
								text[len++] = msg.ch;
								text[len] = 0;

								clearrectangle(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//����Ѿ��еĹ��
								width = textwidth(text);// ���¼����ı�����
								count = 0;
								outtextxy(x + 10, y + 5, text);// ����µ��ַ���
							}
					}
				}
				peekmessage(NULL, EX_MOUSE | EX_CHAR);//����
			}

			count = (count + 1) % 32;//�������ҿ�����32����
			if (count < 16)
				line(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//�������
			else
				clearrectangle(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//���ǹ��

			// ��ʱ 20ms
			Sleep(20);

			//�����˸����Ϊ 20 * 16 ms
		}

    }
    else
    {
        setlinecolor(LIGHTGRAY);		
		setbkcolor(WHITE);
        setfillcolor(WHITE);			
        fillrectangle(x, y, x + w, y + h);
        outtextxy(x + 10, y + 5, text);
    }
}

bool TextBox::onFocus(ExMessage msg)
{
    if ((msg.x > this->x && msg.x < this->x + this->w)
        && (msg.y > this->y && msg.y < this->y + this->h))
        return true;
    else
        return false;
}

bool TextBox::isClick(ExMessage msg)
{
    if (this->onFocus(msg))
        return msg.message == WM_LBUTTONDOWN;
    else
        return false;
}

