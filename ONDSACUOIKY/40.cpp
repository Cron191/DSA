#include <iostream>
using namespace std;

struct khongian3chieu
{
    double x, y, z;
};

int Check(khongian3chieu a[], int n, khongian3chieu x)
{
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (x.x < a[mid].x)
        {
            r = mid - 1;
            cnt++;
        }
        else if (x.x > a[mid].x)
        {
            l = mid + 1;
            cnt++;
        }
        else
            return ++cnt;
    }
    return -1;
}

int main()
{

    int n;
    cin >> n;
    khongian3chieu a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        khongian3chieu x;
        cin >> x.x >> x.y >> x.z;
        if (Check(a, n, x) == -1)
            cout << "KHONG" << endl;
        else
            cout << Check(a, n, x) << endl;
    }
}