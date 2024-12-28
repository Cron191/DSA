
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

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x;           // gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if (T)
    {
        if (T->key == p->key)
            return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}

void CreateTree(TREE &T)
{
    int x;
    do
    {
        cin >> x;
        if (x == -1)
            break;
        Insert(T, CreateTNode(x));
    } while (true);
}

bool IsCompleteBST(TREE T)
{
    queue<TNODE *> q;
    q.push(T);
    bool end = false;
    while (!q.empty())
    {
        TNODE *curr = q.front();
        q.pop();
        if (curr->pLeft != NULL)
        {
            if (end == true)
                return false;
            q.push(curr->pLeft);
        }
        else
            end = true;
        if (curr->pRight != NULL)
        {
            if (end == true)
                return false;
            q.push(curr->pRight);
        }
        else
            end = true;
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
