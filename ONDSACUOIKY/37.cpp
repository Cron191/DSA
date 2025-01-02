
#include <iostream>
using namespace std;

struct HASH
{
    int n;
    int m;
    int key[10];
};

void InsertHash(HASH &ht, int x)
{
    if (ht.n + 1 > ht.m)
    {
        cout << x << " FULL" << endl;
        return;
    }
    int index = x % ht.m;
    int i = 0;
    while (ht.key[index] != 0)
    {
        i++;
        index = (x + i * i) % ht.m;
        if (i > ht.m)
        {
            cout << x << " FULL" << endl;
            return;
        }
    }
    if (ht.key[index] == 0)
    {
        ht.key[index] = x;
        ht.n++;
    }
    else
    {
        cout << x << " FULL" << endl;
        return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    HASH ht;
    ht.m = n;
    ht.n = 0;
    for (int i = 0; i < ht.m; i++)
    {
        ht.key[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        InsertHash(ht, x);
    }
    for (int i = 0; i < ht.m; i++)
        if (ht.key[i] == 0)
            cout << i << endl;
}