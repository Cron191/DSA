
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
    else
        InsertTree(T->pRight, x);
}
void CreateTree(TREE &T)
{
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            return;
        InsertTree(T, x);
    }
}
TNODE *FindMax(TREE T)
{
    while (T->pRight != NULL)
    {
        T = T->pRight;
    }
    return T;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMax(T)->key;
    return 0;
}
