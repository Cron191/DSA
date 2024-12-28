
#include <iostream>
#include <string.h>

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

int get_nth_node_from_head(NODE *L, int k)
{
    while (L != NULL)
    {
        --k;
        if (k == 0)
            return L->info;
        L = L->pNext;
    }
    if (L == NULL)
        return -1;
}

int main()
{
    LIST L;
    int k;
    CreateEmptyList(L);
    CreateList(L);

    std::cin >> k;
    cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
