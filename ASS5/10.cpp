
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

void InsertTree(TREE &T, int x)
{
    TREE q = new TNODE();
    q->key = x;
    q->pLeft = NULL;
    q->pRight = NULL;
    if (T == NULL)
        T = q;
    else
    {
        if (x < T->key)
            InsertTree(T->pLeft, x);
        else if (x > T->key)
            InsertTree(T->pRight, x);
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
        InsertTree(T, x);
    }
}

bool CompareTree(TREE S, TREE T)
{
    if (S == NULL && T == NULL)
        return true;
    if (S == NULL || T == NULL)
        return false;
    if (S->key != T->key)
        return false;

    return CompareTree(S->pLeft, T->pLeft) && CompareTree(S->pRight, T->pRight);
}

bool isSubtree(TREE S, TREE T)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;

    if (S->key == T->key && CompareTree(S, T))
        return true;

    return isSubtree(S, T->pLeft) || isSubtree(S, T->pRight);
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
