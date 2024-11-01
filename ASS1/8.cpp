
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
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
void XuatSinhVien(SinhVien sv) 
{
    cout << sv.MASV <<'\t'<< sv.HoTen <<'\t'<<sv.NamSinh.d<<"/"<<sv.NamSinh.m<<"/"<<sv.NamSinh.y <<'\t'<< sv.GioiTinh <<'\t'<< sv.DiemToan <<'\t'<< sv.DiemLy <<'\t'<< sv.DiemHoa <<'\t'<< sv.DTB <<'\n';
}
void TimTheoNamSinh(SinhVien *A, int n, int namsinh) 
{
    int d=0;
    for (int i = 0; i < n; ++i) 
    {
        if (A[i].NamSinh.y == namsinh) 
        {
            d++;
            XuatSinhVien(A[i]);
        }
    }
    if(d==0) cout<<"Not found in list.";

}
int main() {
    SinhVien *A;
    int n, namsinh;
    cin >> namsinh;
    Nhap(A, n);
    TimTheoNamSinh(A, n, namsinh);
    return 0;
}

