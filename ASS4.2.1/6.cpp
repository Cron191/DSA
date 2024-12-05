
#include <iostream>
#include <queue>
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
    TNODE *p = CreateTNode(x);
    if (T == NULL)
        T = p;
    else if (x < T->key)
        InsertTree(T->pLeft, x);
    else if (x > T->key)
        InsertTree(T->pRight, x);
    else
        return ;
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

bool CompareTree(TREE T, TREE S)
{
    if (S == NULL)
        return 1;
    if (T == NULL)
        return 0;
    if (T->key != S->key)
        return 0;
    return CompareTree(T->pLeft, S->pLeft) && CompareTree(T->pRight, S->pRight);
}

bool isSubtree(TREE S, TREE T)
{
    if (S == NULL)
        return 1;
    if (T == NULL)
        return 0;
    if (S->key == T->key && CompareTree(S, T))
        return true;
    if (T->pLeft != NULL && S->key < T->key )
        return isSubtree(S, T->pLeft);
    if (T->pRight!=NULL && S->key > T->key )
        return isSubtree(S, T->pRight);
}
int main()
{
    TNODE *S, *T;
    S = NULL;
    T = NULL;

    CreateTree(S);
    CreateTree(T);

    cout << boolalpha << isSubtree(S, T);

    return 0;
}
