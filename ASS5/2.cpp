
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;
TREE CreateNewTNODE(int x)
{
    TREE p = new TNODE();
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Insert(TREE &T, int x)
{
    TREE p = CreateNewTNODE(x);
    if (T == NULL)
        T = p;
    else
    {
        if (x < T->key)
            Insert(T->pLeft, x);
        else if (x > T->key)
            Insert(T->pRight, x);
    }
}
void CreateTree(TREE &T)
{
    int x;
    while (cin)
    {
        cin >> x;
        if (x == -1)
            break;
        Insert(T, x);
    }
}
TREE FindMin(TREE T)
{
    TREE p;
    while (T != NULL)
    {
        p=T;
        T = T->pLeft;
    }
    return p;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMin(T)->key;
    return 0;
}
