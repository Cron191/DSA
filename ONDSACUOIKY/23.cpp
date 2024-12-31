
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

void CountNode_Have2Child(TNODE *T, int &count)
{
    if (T == NULL)
        return;
    if (T->pLeft != NULL && T->pRight != NULL)
        count++;
    CountNode_Have2Child(T->pLeft, count);
    CountNode_Have2Child(T->pRight, count);
}
int main()
{
    int count = 0;
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    CountNode_Have2Child(T, count);
    cout << count;
    return 0;
}
