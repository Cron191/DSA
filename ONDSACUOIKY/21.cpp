
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

void PrintList(LIST L)
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
    cout << endl;
}
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

void Merge_2_Sorted_LL(LIST &L, LIST &L1, LIST &L2)
{
    CreateEmptyList(L);
    while (L1.pHead != NULL && L2.pHead != NULL)
    {
        if (L1.pHead->info < L2.pHead->info)
        {
            AddTail(L, L1.pHead->info);
            L1.pHead = L1.pHead->pNext;
        }
        else

        {
            AddTail(L, L2.pHead->info);
            L2.pHead = L2.pHead->pNext;
        }
    }
    while (L1.pHead != NULL)
    {
        AddTail(L, L1.pHead->info);
        L1.pHead = L1.pHead->pNext;
    }
    while (L2.pHead != NULL)
    {
        AddTail(L, L2.pHead->info);
        L2.pHead = L2.pHead->pNext;
    }
}

int main()
{
    LIST L, L1, L2;

    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    CreateList(L2);

    Merge_2_Sorted_LL(L, L1, L2);

    PrintList(L);
    PrintList(L1);
    PrintList(L2);

    return 0;
}
