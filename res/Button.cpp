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

    setbkmode(TRANSPARENT);//将按钮文本背景设置为透明
    if(this->onFocus(msg))
        setfillcolor(CYAN);//设置鼠标焦点于按钮的文本背景颜色
    else
        setfillcolor(LIGHTGRAY);//设置鼠标未焦点于按钮的文本背景颜色
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 1);
    settextstyle(h / 2, 0, L"Consolas");//设置字体的样式
    fillroundrect(x, y, x + w, y + h, 10, 10);
    outtextxy(x + (w - textwidth(text)) / 2, y + (h - textheight(text)) / 2, text);//文字居中
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
