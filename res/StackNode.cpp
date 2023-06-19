#include "StackNode.h"

StackNode::StackNode(int x, int y, int d)
    : x(x),y(y),d(d)
{

}

StackNode::StackNode()
{
    this->next = NULL;
}

StackNode::~StackNode()
{

}

void StackNode::initStack(StackNode*& s)
{
    s = new StackNode;
    s->next = NULL;
}

void StackNode::destroyStack(StackNode*& s)
{
    StackNode* pre = s, * p = s->next;
    while (p != NULL)
    {
        delete pre;
        pre = p;
        p = pre->next;
    }
    delete pre;
}

bool StackNode::StackEmpty(StackNode* s)
{
    return s->next == NULL;
}

bool StackNode::Push(StackNode*& s, int x, int y, int d)
{
    StackNode* t = new StackNode(x, y, d);
    t->next = s->next;
    s->next = t;
    return true;
}

bool StackNode::Pop(StackNode*& s, int& x, int& y, int& d)
{
    if (StackEmpty(s)) return false;
    else
    {
        StackNode* t = s->next;
        s->next = t->next;
        x = t->x;
        y = t->y;
        d = t->d;
        delete t;
        return true;
    }
}

bool StackNode::GetTop(StackNode* s, int& x, int& y, int& d)
{
    if (StackEmpty(s)) return false;
    else
    {
        StackNode* t = s->next;
        x = t->x;
        y = t->y;
        d = t->d;
        return true;
    }
}

bool StackNode::ChangeTopD(StackNode*& s, int d)
{
    if (StackEmpty(s)) return false;
    else
    {
        s->next->d = d;
        return true;
    }
}
