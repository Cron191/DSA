#include <iostream>
using namespace std;

struct TNODE
{
    long long val;
    TNODE *pLeft;
    TNODE *pRight;
};

typedef TNODE *TREE;

TREE CreateNODE(long long x)
{
    TREE q = new TNODE();
    q->val = x;
    q->pLeft = NULL;
    q->pRight = NULL;
    return q;
}

void InsertTREE(TREE &T, long long x)
{
    if (T == NULL)
    {
        T = CreateNODE(x);
        return;
    }
    if (x < T->val)
        InsertTREE(T->pLeft, x);
    else if (x > T->val)
        InsertTREE(T->pRight, x);
}

int Search(TREE T, long long x)
{
    if (T == NULL)
        return 0;
    if (T->val == x)
        return 1;
    else if (x < T->val)
        return Search(T->pLeft, x);
    else 
        return Search(T->pRight, x);
}

void DeleteTREE(TREE &T, long long x)
{
    if (T == NULL)
        return;
    if (x < T->val)
        DeleteTREE(T->pLeft, x);
    else if (x > T->val)
        DeleteTREE(T->pRight, x);
    else
    {
        if (T->pLeft == NULL && T->pRight == NULL)
            T = NULL;
        else if (T->pLeft != NULL && T->pRight == NULL)
            T = T->pLeft;
        else if (T->pLeft == NULL && T->pRight != NULL)
            T = T->pRight;
        else
        {
            TREE temp = T->pRight;
            while (temp->pLeft != NULL)
                temp = temp->pLeft;
            T->val = temp->val;
            DeleteTREE(T->pRight, temp->val);
        }
    }
}

int main()
{
    TREE T = NULL;
    while (1)
    {
        long long x, y;
        cin >> x;
        if (x == 0)
            return 0;
        cin >> y;
        if (x == 1)
            InsertTREE(T, y);
        if (x == 2)
            cout << Search(T, y) << endl;
        if (x == 3)
            DeleteTREE(T, y);
    }
}