
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
#include <map>
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
            break;
        InsertTree(T, x);
    }
}

void CreateParent(TNODE *T, map<int, int> &parent)
{
    if (T == NULL)
        return;
    if (T->pLeft != NULL)
        parent[T->pLeft->key] = T->key;
    if (T->pRight != NULL)
        parent[T->pRight->key] = T->key;
    CreateParent(T->pLeft, parent);
    CreateParent(T->pRight, parent);
}

bool Search(TNODE *T, int x)
{
    if (T == NULL)
        return false;
    if (T->key == x)
        return true;
    if (x < T->key)
        return Search(T->pLeft, x);
    else if (x > T->key)
        return Search(T->pRight, x);
}

void PrintAncestors(TNODE *T, int x)
{
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    if (x == T->key)
    {
        cout << "Node is root.";
        return;
    }
    map<int, int> parent;
    parent[T->key] = -100;
    if (Search(T, x) == false)
    {
        cout << -1;
        return;
    }
    CreateParent(T, parent);
    while (parent[x] != -100)
    {
        cout << parent[x] << " ";
        x = parent[x];
    }
}

int main()
{
    TNODE *T;
    int x;

    cin >> x;

    T = NULL;
    CreateTree(T);

    PrintAncestors(T, x);

    return 0;
}
