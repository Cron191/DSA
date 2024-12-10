#include <iostream>
#include <map>
using namespace std;

void CreateCSDL(map<string, string> &csdl, int n)
{
    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        csdl[s1] = s2;
    }
}

void Output(map<string, string> csdl, int m)
{
    for (int i = 0; i < m; i++)
    {
        string s1;
        cin >> s1;
        if (csdl.find(s1) != csdl.end())
        {
            auto it = csdl.find(s1);
            cout << it->second << endl;
        }
        else
            cout << "Unregistered User." << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> csdl;
    CreateCSDL(csdl, n);
    Output(csdl, m);
}
