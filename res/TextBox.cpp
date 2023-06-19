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
		settextstyle(20, 0, L"黑体");
		setlinestyle(PS_SOLID, 1);
        setfillcolor(WHITE);			
        fillrectangle(x, y, x + w, y + h);
        outtextxy(x + 10, y + 5, text);


		int width = textwidth(text);// 字符串总宽度
        int count = 0;// 光标闪烁计数器
        bool flag = true;// 是否输入中

		while (flag)
		{
			while (flag && peekmessage(&msg, EX_MOUSE | EX_CHAR, false))//获取消息队列队首消息
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					// 如果鼠标点击文本框外面，结束文本输入
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
						case '\b'://退格
							if (len > 0)
							{
								text[len - 1] = 0;
								width = textwidth(text);
								count = 0;
								clearrectangle(x + 10 + width, y + 1, x + w - 1, y + h - 1);//覆盖字符，不显示
							}
							break;
						case '\r':
						case '\n'://回车和换行
							flag = false;
							break;
						default://文本输入
							if (len < maxlen - 1)
							{
								text[len++] = msg.ch;
								text[len] = 0;

								clearrectangle(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//清除已经有的光标
								width = textwidth(text);// 重新计算文本框宽度
								count = 0;
								outtextxy(x + 10, y + 5, text);// 输出新的字符串
							}
					}
				}
				peekmessage(NULL, EX_MOUSE | EX_CHAR);//出队
			}

			count = (count + 1) % 32;//递增并且控制在32以内
			if (count < 16)
				line(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//画出光标
			else
				clearrectangle(x + 10 + width + 1, y + 3, x + 10 + width + 1, y + h - 3);//覆盖光标

			// 延时 20ms
			Sleep(20);

			//光标闪烁周期为 20 * 16 ms
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

