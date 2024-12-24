
#include <iostream>
using namespace std;
struct TNODE
{
    pair<int, int> key;
    TNODE *pLeft, *pRight;
};

void InsertTree(TNODE *&T, int x)
{
    if (T == NULL)
    {
        T = new TNODE();
        T->key = {x, 1};
    }
    else
    {
        if (x < T->key.first)
            InsertTree(T->pLeft, x);
        else if (x > T->key.first)
            InsertTree(T->pRight, x);
        else
            T->key.second++;
    }
}

void CreateTree(TNODE *&T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertTree(T, x);
    }
}
void PrintTree(TNODE *T)
{
    if (T == NULL)
        return;
    PrintTree(T->pLeft);
    cout << T->key.first << " xuat hien " << T->key.second << " lan" << endl;
    PrintTree(T->pRight);
}
int main()
{
    TNODE *T;
    T = NULL;
    CreateTree(T);
    PrintTree(T);
    return 0;
}
