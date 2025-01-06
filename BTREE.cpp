#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BTREE
{
    vector<int> key;
    vector<BTREE *> node;
    bool leaf() { return node.empty(); }
};

void InsertBTree(BTREE *B, int x)
{
    if (B->leaf() == true)
    {
        B->key.push_back(x);
        sort(B->key.begin(), B->key.end());
        return;
    }
    for (auto i = 0; i < B->key.size(); i++)
    {
        if (x < B->key[i])
        {
            InsertBTree(B->node[i], x);
            return;
        }
    }
    InsertBTree(B->node[B->key.size()], x);
}
int main()
{
}