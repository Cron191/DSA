
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TREE CreateNewTREE(int x)
{
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void InsertTREE(TREE &T, int x)
{
    TREE p = CreateNewTREE(x);
    if (T == NULL)
        T = p;
    else
    {
        if (x < T->key)
            InsertTREE(T->pLeft, x);
        else if (x > T->key)
            InsertTREE(T->pRight, x);
        else
            return;
    }
}
void CreateTree(TREE &T)
{
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        InsertTREE(T, x);
    }
}
int CountLeaf(TREE T)
{
    int cnt = 0;
    if (T == NULL)
        return cnt;
    else
    {
        if (T->pLeft != NULL)
            cnt += CountLeaf(T->pLeft);
        if (T->pLeft == NULL && T->pRight == NULL)
            cnt++;
        if (T->pRight != NULL)
            cnt += CountLeaf(T->pRight);
    }
    return cnt;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    cout << CountLeaf(T);
    return 0;
}
