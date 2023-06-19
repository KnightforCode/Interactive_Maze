#include "Button.h"
class UI;

Button::Button(int x, int y, int w, int h, const wchar_t* text, void (*func)())
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->userfunc = func;
    this->text = new wchar_t[wcslen(text) + 1];
    wcscpy_s(this->text, wcslen(text) + 1, text);
}

Button::~Button()
{
}

void Button::drawButton(ExMessage msg)
{

    setbkmode(TRANSPARENT);//����ť�ı���������Ϊ͸��
    if(this->onFocus(msg))
        setfillcolor(CYAN);//������꽹���ڰ�ť���ı�������ɫ
    else
        setfillcolor(LIGHTGRAY);//�������δ�����ڰ�ť���ı�������ɫ
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 1);
    settextstyle(h / 2, 0, L"Consolas");//�����������ʽ
    fillroundrect(x, y, x + w, y + h, 10, 10);
    outtextxy(x + (w - textwidth(text)) / 2, y + (h - textheight(text)) / 2, text);//���־���
}

bool Button::onFocus(ExMessage msg)
{
    if ((msg.x > this->x && msg.x < this->x + this->w)
        && (msg.y > this->y && msg.y < this->y + this->h))
        return true;
    else
        return false;
}

bool Button::isClick(ExMessage msg)
{
    if (this->onFocus(msg))
        return msg.message == WM_LBUTTONDOWN;
    else
        return false;
}

void Button::onMessage()
{
    if (userfunc != NULL)
        userfunc();
}
