
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
bool searchNode(TREE T, int x)
{
    if (T == NULL)
        return 0;
    else
    {
        if (T->key == x)
            return 1;
        else if (x < T->key)
            return searchNode(T->pLeft, x);
        else if (x > T->key)
            return searchNode(T->pRight, x);
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;
    if (searchNode(T, x))
        cout << "true";
    else
        cout << "false";
    return 0;
}
