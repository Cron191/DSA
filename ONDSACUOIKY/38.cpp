
#include <iostream>
using namespace std;
struct NODE
{
    int val;
    NODE *pLeft;
    NODE *pRight;
};

typedef NODE *TREE;

NODE *CreateNODE(int x)
{
    NODE *q = new NODE();
    q->val = x;
    q->pLeft = NULL;
    q->pRight = NULL;
    return q;
}

void InsertTree(TREE &T, int x)
{
    NODE *q = CreateNODE(x);
    if (T == NULL)
        T = q;
    if (x < T->val)
        InsertTree(T->pLeft, x);
    else if (x > T->val)
        InsertTree(T->pRight, x);
}

bool Check(TREE T, int leaf, int &deathleft)
{
    if (T == NULL)
        return true;
    if (!T->pLeft && !T->pRight)
    {
        if (deathleft == -1)
            deathleft = leaf;
        if (deathleft == leaf)
            return true;
        else
            return false;
    }

    if (!T->pLeft || !T->pRight)
        return false;

    return Check(T->pLeft, leaf + 1, deathleft) && Check(T->pRight, leaf + 1, deathleft);
}

int main()
{
    TREE T;
    T = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertTree(T, x);
    }
    int deathleaf = -1;
    if (Check(T, 0, deathleaf) == true)
        cout << "YES";
    else
        cout << "NO";
}