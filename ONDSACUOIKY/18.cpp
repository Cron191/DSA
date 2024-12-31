#include <iostream>
using namespace std;
#include <queue>
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

void Run(TREE &T)
{
    int x;
    cin >> x;
    int cnt = 0;
    bool check = false, ok = false;
    queue<TNODE *> q;
    q.push(T);
    while (!q.empty())
    {
        TNODE *curr = q.front();
        q.pop();
        if (curr->key == x)
            ok = true;
        if (curr->key > x && ok == true)
        {
            cout << curr->key << " ";
            check = true;
            cnt++;
        }
        if (curr->key < x && check == true)
            return;
        if (curr->pLeft != NULL)
            q.push(curr->pLeft);
        if (curr->pRight != NULL)
            q.push(curr->pRight);
    }
    if (cnt == 0)
        cout << "No solution.";
}

int main()
{
    TREE T;
    CreateTree(T);
    Run(T);
}
