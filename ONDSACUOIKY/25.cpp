/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

// ###INSERT CODE HERE -
TNODE *createNode(int x)
{
    TNODE *p = new TNODE();
    p->key = x;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p;
}

void AddToBST(TREE &T, int x)
{
    if (!T)
        T = createNode(x);
    else if (x < T->key)
        AddToBST(T->pLeft, x);
    else
        AddToBST(T->pRight, x);
}

void CreateTree(TREE &T)
{
    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
            return;
        AddToBST(T, x);
    }
}

int Count_Nodes_With_Restrictions(TREE T, int &count_left, int &count_right)
{
    if (T == nullptr)
        return 0;
    int left_count = 0, right_count = 0;
    count_left = Count_Nodes_With_Restrictions(T->pLeft, left_count, right_count);
    count_right = Count_Nodes_With_Restrictions(T->pRight, left_count, right_count);
    if (count_left == count_right + 1)
        cout << T->key << " ";
    return count_left + count_right + 1;
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T)
{
    int count_left = 0, count_right = 0;
    Count_Nodes_With_Restrictions(T, count_left, count_right);
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);
}