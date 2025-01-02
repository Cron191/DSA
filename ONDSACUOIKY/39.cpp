
#include <iostream>
using namespace std;

struct NODE
{
    int x, y;
    int kc;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNODE(int x, int y, int kc)
{
    NODE *p = new NODE();
    p->x = x;
    p->y = y;
    p->kc = kc;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &L, NODE *p)
{
    p->pNext = L.pHead;
    L.pHead = p;
}

void InsertLIST(LIST &L, int x, int y, int kc)
{
    NODE *p = CreateNODE(x, y, kc);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
        return;
    }
    if (kc < L.pHead->kc)
    {
        AddHead(L, p);
        return;
    }

    NODE *curr = L.pHead->pNext;
    NODE *prev = L.pHead;
    while (curr != NULL)
    {
        if (curr->kc > kc)
        {
            p->pNext = curr;
            prev->pNext = p;
            return;
        }
        else if (curr->kc == kc)
        {
            if (x > curr->x)
            {
                p->pNext = curr->pNext;
                curr->pNext = p;
                return;
            }
            p->pNext = curr;
            prev->pNext = p;
            return;
        }
        prev = curr;
        curr = curr->pNext;
    }
    if (curr == NULL)
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintLIST(LIST &L)
{
    while (L.pHead != NULL)
    {
        cout << L.pHead->x << " " << L.pHead->y << endl;
        L.pHead = L.pHead->pNext;
    }
}

int main()
{
    LIST L;
    L.pHead = L.pTail = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        InsertLIST(L, x, y, x * x + y * y);
    }
    PrintLIST(L);
}
