#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

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

struct NODE
{
    SinhVien key;
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
    p->key = x;
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

void Input(LIST &L)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        SinhVien a;
        Input(a);
        AddTail(L, a);
    }
}

NODE *SearchQ(LIST L, SinhVien sv)
{
    NODE *p = L.pHead;
    NODE *q = NULL;

    while (p != NULL)
    {
        if (strcmp(p->key.MASV, sv.MASV) > 0)
            q = p;
        else
            break;
        p = p->pNext;
    }
    return q;
}

void InsertAffer(LIST &L, NODE *q, NODE *p)
{
    if (q == NULL)
    {
        if (L.pHead == NULL)
        {
            L.pHead = p;
            L.pTail = p;
        }
        else
        {
            p->pNext = L.pHead;
            L.pHead = p;
        }
    }
    else
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (q == L.pTail)
        {
            L.pTail = p;
        }
    }
}

void Insert_Decreasing(LIST &L, SinhVien sv)
{
    NODE *q = SearchQ(L, sv);
    NODE *p = new NODE();
    p->key = sv;
    p->pNext = NULL;
    InsertAffer(L, q, p);
}
void Output(SinhVien sv)
{
    cout << sv.MASV << '\t' << sv.HoTen << '\t' << sv.NgaySinh << '\t' << sv.GioiTinh << '\t' << sv.DiemToan << '\t' << sv.DiemLy << '\t' << sv.DiemHoa << '\t';
    cout << setprecision(3) << sv.DTB << '\n';
}
void Output(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        Output(p->key);
        p = p->pNext;
    }
}
int main()
{
    LIST L;
    L.pHead = L.pTail = NULL;
    Input(L); // DS đầu vào mặc định có thứ tự Giảm dần theo MASV

    cin.ignore();
    SinhVien sv; // Sinh viên cần chèn
    Input(sv);

    Insert_Decreasing(L, sv);

    Output(L);

    return 0;
}
