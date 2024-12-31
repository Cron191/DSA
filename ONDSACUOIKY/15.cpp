#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, string> m;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        string s, s1;
        cin >> s >> s1;
        m[s] = s1;
    }
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) != m.end())
            cout << m[s] << endl;
        else
            cout << "Chua Dang Ky!" << endl;
    }
}