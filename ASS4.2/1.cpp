
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

void AddHead(LIST &l, int x)
{
    NODE *p = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void CreateList(LIST &l)
{

    while (cin)
    {
        int x;
        cin >> x;
        if (x != -1)
            AddHead(l, x);
        else
            break;
    }
}

int count_even(NODE *q)
{
    int cnt = 0;
    NODE *p = q;
    while (p != NULL)
    {
        if (p->info % 2 == 0)
            cnt++;
        p = p->pNext;
    }
    return cnt;
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}
