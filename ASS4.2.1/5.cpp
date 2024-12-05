
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
    int x;
    do
    {
        cin >> x;
        if (x == -1)
            break;
        Insert(T, CreateTNode(x));
    } while (true);
}

bool FindTree(TREE T, int x)
{
    if (T == NULL)
        return 0;
    if (T->key == x)
        return 1;
    else if (x < T->key)
        return FindTree(T->pLeft, x);
    else
        return FindTree(T->pRight, x);
}

void PrintParent(TREE T, int x)
{
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    else
    {
        if (FindTree(T, x) == 0)
        {
            cout << "Not found " << x << ".";
            return;
        }
        else
        {
            if (T->key == x)
            {
                cout << x << " has no parent.";
                return;
            }
            if ((T->pLeft != NULL && T->pLeft->key == x) || (T->pRight != NULL && T->pRight->key == x))
            {
                cout << T->key << " is parent of " << x << ".";
                return;
            }
            else if (T->pLeft != NULL && x < T->key)
                PrintParent(T->pLeft, x);
            else if (T->pRight != NULL && x > T->key)
                PrintParent(T->pRight, x);
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

    PrintParent(T, x);

    return 0;
}
