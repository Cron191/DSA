
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
#include<algorithm>
#include <cmath>
using namespace std;
#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien{
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien *&A, int &n) 
{
    cin >> n;
    cin.ignore(2);
    A = new SinhVien[n];
    for (int i=0;i<n;i++) 
    {
        cin.getline(A[i].MASV,sizeof(A[i].MASV));
        cin.getline(A[i].HoTen,sizeof(A[i].HoTen));
        cin >> A[i].NamSinh.d >> A[i].NamSinh.m >> A[i].NamSinh.y;
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        cin.ignore(2);
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3;
    }
}
void chuyen(float a)
{
    float x=a;
    int d=0;
    while(!(floor(x)==x)) 
    {
        x*=10;
        d++;
    }
    if(d>2) 
    cout<<fixed<<setprecision(2)<<a;
    else cout<<a;
    cout.unsetf(ios::fixed);

}
void Xuat(SinhVien sv[], int n) 
{
    if(n==0) 
    {
        cout<<"Empty List.";
        return ;
    }
    for(int i=0;i<n;i++)
    {
        cout << sv[i].MASV <<'\t'<< sv[i].HoTen <<'\t'<<sv[i].NamSinh.d<<"/"<<sv[i].NamSinh.m<<"/"<<sv[i].NamSinh.y <<'\t'<< sv[i].GioiTinh <<'\t'<< sv[i].DiemToan <<'\t'<< sv[i].DiemLy <<'\t'<< sv[i].DiemHoa<<'\t';
        chuyen(sv[i].DTB);
        cout<<endl;
    }
}

bool cmp(SinhVien x, SinhVien y)
{
    int i=0;
    while(x.MASV[i]==y.MASV[i]) i++;
    if(x.MASV[i]> y.MASV[i]) return true;
    return false;
}
void SapXepGiamTheoMASV(SinhVien A[], int n)
{
    sort(A,A+n,cmp);
}


int main() {
    SinhVien *A;
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
