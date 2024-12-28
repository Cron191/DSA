
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

void PrintTreeBFS(TREE T)
{
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    queue<TNODE *> q;
    q.push(T);
    while (!q.empty())
    {
        TNODE *curr = q.front();
        q.pop();

        cout << curr->key << " ";
        if (curr->pLeft != NULL)
            q.push(curr->pLeft);
        if (curr->pRight != NULL)
            q.push(curr->pRight);
    }
}
int main()
{
    TNODE *T; // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
