
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE();
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void InsertTree(TREE &T, int x)
{
    TREE p = CreateTNode(x);

    if (T == NULL)
        T = p;
    else if (x < T->key)
        InsertTree(T->pLeft, x);
    else if (x > T->key)
        InsertTree(T->pRight, x);
    else if (x == T->key)
        return;
}

void CreateTree(TREE &T)
{
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        else
            InsertTree(T, x);
    }
}

void CountNode_Have2Child(TREE T, int &count)
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
