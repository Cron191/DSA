
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

void InsertTree(TREE &t, int x)
{
    TREE q = new TNODE();
    q->key = x;
    q->pLeft = NULL;
    q->pRight = NULL;
    if (t == NULL)
        t = q;
    else
    {
        if (x < t->key)
            InsertTree(t->pLeft, x);
        else if (x == t->key)
            return;
        else
            InsertTree(t->pRight, x);
    }
}

void CreateTree(TREE &t)
{
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        InsertTree(t, x);
    }
}

bool IsCompleteBST(TREE T)
{
    queue<TREE> q;
    if (T == NULL)
        return false;
    q.push(T);
    bool end = false;
    while (q.empty() == 0)
    {
        TREE current = q.front();
        q.pop();
        if (current->pLeft == NULL)
            end = true;
        else
        {
            if (end == true)
                return false;
            q.push(current->pLeft);
        }
        if (current->pRight != NULL)
        {
            if (end == true)
                return false;
            q.push(current->pRight);
        }
        else
        {
            end = true;
        }
    }
    return true;
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << boolalpha << IsCompleteBST(T);

    return 0;
}
