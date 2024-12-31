#include <iostream>
#include <algorithm>
using namespace std;

struct diem
{
    float x, y, z;
};
struct NODE
{
    diem key;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNODE(float x, float y, float z)
{
    NODE *p = new NODE();
    p->key.x = x;
    p->key.y = y;
    p->key.z = z;
    p->pNext = NULL;
    return p;
}
void AddTail(LIST &L, NODE *p)
{
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

int Check(LIST L, NODE *p)
{
    int i = 0;
    while (L.pHead != NULL)
    {
        if (L.pHead->key.x == p->key.x && L.pHead->key.y == p->key.y && L.pHead->key.z == p->key.z)
            return i;
        i++;
        L.pHead = L.pHead->pNext;
    }
    return -1;
}

void Run(LIST &L)
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        float x, y, z;
        cin >> x >> y >> z;
        NODE *p = CreateNODE(x, y, z);
        if (Check(L, p) == -1)
            cout << "KHONG\n";
        else
            cout << Check(L, p) << "\n";
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
        float x, y, z;
        cin >> x >> y >> z;
        NODE *p = CreateNODE(x, y, z);
        AddTail(L, p);
    }
    Run(L);
}