
#include <iostream>
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
    while (cin)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        TREE p = CreateTNode(x);
        Insert(T, p);
    }
}
static int temp = 1001;
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
void FindParent(TREE T, int x)
{
    if (T != NULL && x == T->key && temp == 1001)
    {
        cout << x << " has no parent.";
        return;
    }
    else if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    else if (searchNode(T, x) == 0)
    {
        cout << "Not found " << x << ".";
        return;
    }

    else if (searchNode(T, x) == 1)
    {
        if (x > T->key)
        {
            temp = T->key;
            FindParent(T->pRight, x);
        }
        if (x < T->key)
        {
            temp = T->key;
            FindParent(T->pLeft, x);
        }
        if (x == T->key)
        {
            cout << temp << " is parent of " << x << ".";
            return;
        }
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindParent(T, x);

    return 0;
}
