#include "Path.h"

Path::Path(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Path::drawBlock()
{
	setfillcolor(CYAN);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 2);
	fillrectangle(this->x, this->y, this->x + 20, this->y + 20);
}

void Path::drawPath(int x, int y)
{
	setfillcolor(CYAN);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	fillrectangle(x, y, x + 30, y + 30);
}

void Path::drawFocusPath(int x, int y)
{

	setlinecolor(RED);
	setlinestyle(PS_SOLID, 3);
	rectangle(x, y, x + 30, y + 30);

}

void Path::drawMethodePath(int x,int y)
{
	setfillcolor(GREEN);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 1);
	fillrectangle(x, y, x + 30, y + 30);
	/*switch (d)
	{
	case 0:
		line(x + 15, y + 25, x + 15, y + 5);
		line(x + 15, y + 5, x + 10, y + 10);
		line(x + 15, y + 5, x + 20, y + 10);
		break;
	case 1:
		line(x + 5, y + 15, x + 25, y + 15);
		line(x + 25, y + 15, x + 20, y + 10);
		line(x + 25, y + 15, x + 20, y + 20);
		break;
	case 2:
		line(x + 15, y + 5, x + 15, y + 25);
		line(x + 15, y + 25, x + 10, y + 20);
		line(x + 15, y + 25, x + 20, y + 20);
		break;
	case 3:
		line(x + 25, y + 15, x + 5, y + 15);
		line(x + 5, y + 15, x + 10, y + 10);
		line(x + 5, y + 15, x + 10, y + 20);
		break;
	case 4:
		line(x + 5, y + 5, x + 25, y + 25);
		line(x + 25, y + 5, x + 5, y + 25);
		Path::drawPath(x, y);
		break;
	default:
		break;
	}*/
	
}

void Path::drawMethodeDFSPath(int x, int y)
{
	setfillcolor(YELLOW);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 1);
	fillrectangle(x, y, x + 30, y + 30);
}
