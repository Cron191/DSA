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

void CreateEmptyLIST(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddHeap(LIST &L, int x)
{
    NODE *p = CreateNODE(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
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

void AddAfterQ(LIST &L, NODE *Q, int x)
{
    NODE *p = CreateNODE(x);
    if (Q != NULL)
    {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (Q == L.pTail)
            L.pTail = p;
    }
    else
        AddTail(L, x);
}

void RemoveHead(LIST &L)
{
    if (L.pHead == NULL)
        return;
    else
    {
        NODE *p = L.pHead;
        L.pHead = L.pHead->pNext;
        delete p;
    }
}

void RemoveAfterQ(LIST &L, NODE *Q)
{
    if (Q != NULL)
    {
        NODE *p = Q->pNext;
        if (p != NULL)
        {
            Q->pNext = p->pNext;
            if (p == L.pTail)
                L.pTail = Q;
            delete p;
        }
    }
}

void RemoveX(LIST &L, int x)
{
    NODE *p = L.pHead;
    NODE *Q = NULL;
    while (p != NULL && p->info != x)
    {
        Q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return;
    if (Q != NULL)
        RemoveAfterQ(L, Q);
    else
        RemoveHead(L);
}
int main()
{
    LIST L;
}