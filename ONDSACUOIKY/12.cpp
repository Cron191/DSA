
#include <iostream>
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

void Join(LIST &L, LIST &L1, NODE *p, LIST &L2)
{
    if (L1.pHead != NULL)
    {
        L.pHead = L1.pHead;
        L.pTail = L1.pTail;
    }
    if (L.pHead != NULL)
    {
        L1.pTail->pNext = p;
        L.pTail = p;
    }
    else
    {
        L.pHead = p;
        L.pTail = p;
    }
    if (L2.pHead != NULL)
    {
        L.pTail->pNext = L2.pHead;
        L.pTail = L2.pTail;
    }
}

void PrintList(LIST L)
{
    while (L.pHead != NULL)
    {
        cout << L.pHead->info << " ";
        L.pHead = L.pHead->pNext;
    }
}
int main()
{
    LIST L, L1, L2;

    int x;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    cin >> x;
    pivot = CreateNode(x);
    CreateList(L2);

    Join(L, L1, pivot, L2);
    PrintList(L);

    return 0;
}
