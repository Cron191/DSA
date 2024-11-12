
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

TNODE *FindParent(TREE Root, const int &x)
{
    if (Root == NULL)
        return NULL;
    if (Root->key == x)
        return NULL;

    TNODE *pre = NULL;
    TNODE *p = Root;
    while (p != NULL)
    {
        if (x == p->key)
            return pre;
        pre = p;
        if (x < p->key)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return NULL;
}
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
static int cnt = 0;
static int root;
static int temp = 1001;
void FindSiblings(TREE T, int x)
{
    if (cnt == 0 && T!=NULL)
        root = T->key;
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    else if (searchNode(T, x) == 0)
    {
        cout << "Not found " << x << ".";
        return;
    }
    else if (root == x)
    {
        cout << x << " is Root.";
        return;
    }
    else if (searchNode(T, x) == 1)
    {

        if (x < T->key)
        {
            cnt++;
            if (T->pRight != NULL)
                temp = T->pRight->key;
            else
                temp = 1001;
            FindSiblings(T->pLeft, x);
        }
        else if (x > T->key)
        {
            cnt++;
            if (T->pLeft != NULL)
                temp = T->pLeft->key;
            else
                temp = 1001;
            FindSiblings(T->pRight, x);
        }
        else if (x == T->key)
        {
            cnt++;
            if (temp < x && temp != 1001)
                cout << temp << " and " << x << " are siblings.";
            else if (temp > x && temp != 1001)
                cout << x << " and " << temp << " are siblings.";
            else if (temp == 1001)
                cout << x << "  has no siblings.";
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

    FindSiblings(T, x);

    return 0;
}
