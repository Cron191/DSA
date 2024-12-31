
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

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST &L)
{
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        else
            AddTail(L, x);
    }
}

void Reverse_LinkedList(LIST &L)
{
    if (L.pHead == NULL)
        return;
    NODE *pre = new NODE();
    NODE *next = new NODE();
    NODE *curr = new NODE();
    pre = NULL;
    curr = L.pHead;
    next = curr->pNext;
    while (next != NULL)
    {

        curr->pNext = pre;
        pre = curr;
        curr = next;
        next = next->pNext;
    }
    // pre->pNext = curr;
    curr->pNext = pre;
    pre = curr;
    L.pHead = pre;
}
void PrintList(const LIST &L)
{
    NODE *p;

    if (L.pHead == NULL)
        cout << "Empty List.";
    else
    {
        p = L.pHead;
        while (p)
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

    Reverse_LinkedList(L);

    PrintList(L);

    return 0;
}
