#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    stack<int> s;
    int dem[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
        dem[x]++;
    }

    while (k > 0 && !s.empty())
    {
        int x = s.top();
        s.pop();
        if (dem[x] == 1)
        {
            cout << x << " ";
            dem[x] = 0;
            k--;
        }
        else if (dem[x] > 1)
        {
            cout << x << "(" << dem[x] << ") ";
            dem[x] = 0;
            k--;
        }
    }
}