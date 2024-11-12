
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
        else if(x>T->key)
            InsertTREE(T->pRight, x);
        else return;
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

void PrintTree(TREE T)
{
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    if (T->pLeft)
        PrintTree(T->pLeft);
    cout << T->key << " ";
    if (T->pRight)
        PrintTree(T->pRight);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
