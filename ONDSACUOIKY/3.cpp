
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
int Height(TREE T)
{
    if (T == NULL)
        return -1;
    return max(Height(T->pLeft) + 1, Height(T->pRight) + 1);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << Height(T);
    return 0;
}
