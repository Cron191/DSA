#include <iostream>
using namespace std;
struct NODE
{
    char key;
    NODE *pNext;
};

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

NODE *CreateNode(char x)
{
    NODE *p = new NODE();
    p->key = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &L, char x)
{
    NODE *p = CreateNode(x);
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

void CreateList(LIST &L)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        AddHead(L, x);
    }
}

void RemoveHead(LIST &L)
{
    if (L.pHead == NULL)
        return;
    if (L.pHead == L.pTail)
    {
        L.pHead = NULL;
        L.pTail = NULL;
    }
    else
    {
        NODE *p = L.pHead;
        L.pHead = L.pHead->pNext;
        delete p;
    }
}

void PrintList(LIST L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while (L.pHead != NULL)
    {
        cout << L.pHead->key << " ";
        L.pHead = L.pHead->pNext;
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
