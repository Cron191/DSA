#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct STACK
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNODE(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyStack(STACK &s)
{
    s.pHead = NULL;
    s.pTail = NULL;
}

bool isEmptyStack(STACK s)
{
    if (s.pHead == NULL)
        return 1;
    return 0;
}

void PushStack(STACK &s, int x)
{
    NODE *p = CreateNODE(x);
    if (s.pHead == NULL)
    {
        s.pHead = p;
        s.pTail = p;
    }
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

void PopStack(STACK &s)
{
    if (s.pHead != NULL)
    {
        if (s.pHead->pNext == NULL)
        {
            s.pHead = NULL;
            s.pTail = NULL;
        }
        else
        {
            NODE *p = s.pHead;
            s.pHead = s.pHead->pNext;
            delete p;
        }
    }
}

int TopStack(STACK s)
{
    return s.pHead->info;
}

int main()
{
    STACK s;//
}