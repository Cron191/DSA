#include <iostream>
#include <iomanip>
using namespace std;
#define MAXN 100

struct SinhVien
{
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Input(SinhVien &a)
{
    cin.getline(a.MASV, 10);
    cin.getline(a.HoTen, 100);
    cin.getline(a.NgaySinh, 12);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
#include <cmath>

struct NODE
{
    SinhVien info;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNODE(SinhVien x)
{
    NODE *p = new NODE();
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, SinhVien x)
{
    NODE *p = CreateNODE(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void Input(LIST &l)
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        SinhVien a;
        Input(a);
        AddTail(l, a);
        cin.ignore();
    }
}
void chuyen(float a)
{
    float x = a;
    int d = 0;
    while (!(floor(x) == x))
    {
        x *= 10;
        d++;
    }
    if (d > 2)
        cout << fixed << setprecision(2) << a;
    else
        cout << a;
    cout.unsetf(ios::fixed);
}
void Output(LIST &l)
{
    if (l.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->info.MASV << '\t' << p->info.HoTen << '\t' << p->info.NgaySinh<<'\t' << p->info.GioiTinh << '\t' << p->info.DiemToan << '\t' << p->info.DiemLy << '\t' << p->info.DiemHoa << '\t';
        chuyen(p->info.DTB);
        cout << endl;
        p = p->pNext;
    }
}
int main()
{
    LIST L;
    L.pHead = L.pTail = NULL;
    Input(L);
    Output(L);
    return 0;
}
