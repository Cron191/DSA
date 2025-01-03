#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    TREE root;
    if (inE < inB)
        return NULL;
    root = new TNode;
    if (root != NULL)
    {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB])
                break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    }
    return root;
}

double AverageByLevel(TREE, int);

int main()
{
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++)
    {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

double AverageByLevel(TREE T, int x)
{
    if (T == NULL)
        return 0;

    vector<TREE> curr;
    curr.push_back(T);
    vector<TREE> next = {};
    int curr_level = 0;
    while (!curr.empty() && curr_level < x)
    {
        for (auto x : curr)
        {
            if (x->left != NULL)
                next.push_back(x->left);
            if (x->right != NULL)
                next.push_back(x->right);
        }
        curr_level++;
        curr = next;
        next = {};
    }
    if (curr.empty())
        return 0;
    double sum = 0;
    for (auto x : curr)
    {
        sum += x->key;
    }
    return 1.0 * sum / curr.size();
}
