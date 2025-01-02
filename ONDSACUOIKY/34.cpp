#include <iostream>

using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs)
{
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

int QuickSort(Hocsinh[], int, int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++)
    {
        Input(ls[i]);
    }
    cout << QuickSort(ls, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
    {
        Output(ls[i]);
    }
    delete[] ls;
    return 0;
}

int QuickSort(Hocsinh ls[], int b, int e)
{
    Hocsinh pivot = ls[(b + e) / 2];
    int i = b, j = e;
    int cnt = 0;
    bool ok = true;
    if (e - b <= 1)
        return 0;
    for (int h = i; h < j; h++)
        if (ls[h].Hoten.compare(ls[h + 1].Hoten) > 0)
            ok = false;
    if (ok == true)
        return 0;
    while (i <= j)
    {
        while (ls[i].Hoten.compare(pivot.Hoten) < 0)
            i++;
        while (ls[j].Hoten.compare(pivot.Hoten) > 0)
            j--;
        if (ls[j].Hoten.compare(pivot.Hoten) == 0)
            cnt++;
        if (i <= j)
        {
            swap(ls[i], ls[j]);
            // if (j - i == 1)
            //     cnt++;
            // else
                cnt = cnt + 2;
            i++;
            j--;
        }
    }
    int a = 0, c = 0;
    if (b < j)
        a = QuickSort(ls, b, j);
    if (i < e)
        c = QuickSort(ls, i, e);
    return cnt + a + c;
}