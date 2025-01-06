#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int SoDinh, SoCanh;
    cin >> SoDinh >> SoCanh;
    vector<vector<int>> graph(SoDinh, vector<int>(SoDinh, 0));
    map<string, set<int>> graph1;
    map<string, int> TenDinh;
    string name, name1;
    for (int i = 0; i < SoDinh; i++)
    {
        cin >> name;
        TenDinh[name] = i; // insert
    }
    for (int i = 0; i < SoCanh; i++)
    {
        cin >> name >> name1;
        graph[TenDinh[name]][TenDinh[name1]] = 1;
        // graph1[name].insert(name1);
    }
    for (int i = 0; i < SoDinh; i++)
    {
        for (int j = 0; j < SoDinh; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    // string u;
    // cin >> u;
    // int x = TenDinh[u];
    // for (int i = 0; i < SoDinh; i++)
    // {
    //     if (graph[x][i] != 0)
    //         for (auto it : TenDinh)
    //             if (it.second == i)
    //                 cout << it.first << " ";
    // }
}
