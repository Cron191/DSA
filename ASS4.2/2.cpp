
#include <iostream>
using namespace std;
struct NODE
{
    int info;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, int x)
{
    NODE *p = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void CreateList(LIST &l)
{

    while (cin)
    {
        int x;
        cin >> x;
        if (x != -1)
            AddTail(l, x);
        else
            break;
    }
}

void Print_Middle(LIST &l)
{
    NODE *p = l.pHead;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->pNext;
    }
    NODE *q = l.pHead;
    if (cnt > 1)
    {
        if (cnt % 2 == 0)
            cnt = cnt / 2 - 1;
        else
            cnt = cnt / 2;
        while (cnt--)
        {
            q = q->pNext;
        }
        cout << q->info;
    }
    else if (cnt == 1)
        cout << q->info;
    else if (cnt == 0)
        cout << "Empty List.";
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
