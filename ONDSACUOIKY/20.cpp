

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

void PrintList(NODE *L)
{
    if (L == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->pNext;
    }
}

void add_afterX_1(LIST &L, int y, int x)
{
    NODE *p = CreateNode(y);
    NODE *q = L.pHead;
    while (q != NULL)
    {
        if (q->info == x)
        {
            p->pNext = q->pNext;
            q->pNext = p;
            break;
        }
        q = q->pNext;
    }
}

int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> X >> Y;
    add_afterX_1(L, Y, X);

    PrintList(L.pHead);

    return 0;
}
