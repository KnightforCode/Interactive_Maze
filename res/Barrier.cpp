#include "Barrier.h"
using namespace std;

Barrier::Barrier(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Barrier::drawBlock()
{
	setfillcolor(LIGHTGRAY);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	fillrectangle(this->x, this->y, this->x + 30, this->y + 30);
	setlinestyle(PS_SOLID, 1);
	line(this->x, this->y, this->x + 30, this->y + 30);
	line(this->x + 30, this->y, this->x, this->y + 30);
}

void Barrier::drawBarrier(int x,int y)
{
	setfillcolor(LIGHTGRAY);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	fillrectangle(x, y, x + 30, y + 30);
	setlinestyle(PS_SOLID, 1);
	line(x, y, x + 30, y + 30);
	line(x + 30, y, x, y + 30);
}

const bool Barrier::operator<(const Barrier& B) const
{
	if (this->x != B.x)
		return this->x < B.x;
	else
		return this->y < B.y;
}
