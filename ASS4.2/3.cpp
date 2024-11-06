#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead, *pTail;
};

NODE *CreateNODE(int x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddTail(LIST &L, int x)
{
    NODE *p = CreateNODE(x);
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

void CreateList(LIST &l)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        AddTail(l, x);
        cin >> x;
    }
}

void RemoveHead(LIST &l)
{
    if (l.pHead == NULL)
        return;
    if (l.pHead == l.pTail)
    {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else
    {
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

void PrintList(LIST &l)
{
    NODE *p = l.pHead;
    if (l.pHead == NULL)
        cout << "Empty List.";
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    RemoveHead(L);
    PrintList(L);

    return 0;
}
