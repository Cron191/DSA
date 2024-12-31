

#include <iostream>
#include <cmath>
using namespace std;

// Cấu trúc của một node
struct NODE
{
    int info;
    NODE *pNext;
};
// Cấu trúc của một DSLK
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, int x)
{
    NODE *p = CreateNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST &L)
{
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        AddTail(L, x);
    }
}

void setMiddleHead(LIST &L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL || L.pHead->pNext->pNext == NULL)
        return;
    int cnt = 1, cnt1 = 1;
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cnt++;
        p = p->pNext;
    }
    NODE *q = L.pHead;
    NODE *pre = NULL;
    while (q != NULL)
    {
        cnt1++;
        if (cnt1 == cnt / 2 + 1)
        {
            break;
        }
        pre = q;
        q = q->pNext;
    }
    pre->pNext = q->pNext;
    q->pNext = L.pHead;
    L.pHead = q;
}

void PrintList(NODE *L)
{
    if (L == NULL)
    {
        cout <<"Empty List.";
        return;
    }
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->pNext;
    }
}

int main()
{
    LIST L;

    CreateEmptyList(L);
    CreateList(L);

    setMiddleHead(L);

    PrintList(L.pHead);

    return 0;
}
