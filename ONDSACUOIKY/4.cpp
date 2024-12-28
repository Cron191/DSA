
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateNode(int x)
{
    TNODE *q = new TNODE();
    q->key = x;
    q->pLeft = NULL;
    q->pRight = NULL;
    return q;
}
void InsertTree(TREE &T, int x)
{
    TNODE *p = CreateNode(x);
    if (T == NULL)
        T = p;
    else if (x < T->key)
        InsertTree(T->pLeft, x);
    else if (x > T->key)
        InsertTree(T->pRight, x);
}

void CreateTree(TREE &T)
{
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            return;
        InsertTree(T, x);
    }
}

bool InternalNode(TREE T)
{
    if (T == NULL)
        return 0;
    if (T->pLeft != NULL || T->pRight != NULL)
        return 1;
    return 0;
}

int SumInternalNode(TREE T)
{

    if (T == NULL)
        return 0;
    if (InternalNode(T))
    {
        int a = 0, b = 0;
        if (T->pLeft != NULL)
            a = SumInternalNode(T->pLeft);
        if (T->pRight != NULL)
            b = SumInternalNode(T->pRight);
        return T->key + a + b;
    }
    return 0;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    cout << SumInternalNode(T);
    return 0;
}
