
#include <iostream>
#include <cstring>
#include <string>
#define M 10 // M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

struct Node
{
    int key;
    int flag;
    int n;
};
struct Hash
{
    int n;
    Node a[10];
};

void initHash(Hash &H)
{
    for (int i = 0; i < M; i++)
        H.a[i].flag = NULLKEY;
    H.n = 0;
}

int bam(int x)
{
    return x % M;
}

int bamlai(int x, int i)
{
    return (x + i) % M;
}

void insertHash(Hash &H, int x)
{
    int index = bam(x);
    if (H.a[index].flag == NULLKEY)
    {
        H.a[index].flag = 1;
        H.a[index].key = x;
        H.n++;
        return;
    }
    int i = 0;
    while (H.a[index].flag == 1)
    {
        i++;
        index = bamlai(x, i);
        if (i > 9)
            break;
    }
    if (i > 9)
    {
        cout << "\nBang bam bi day, khong them duoc";
        return;
    }

    else
    {
        H.a[index].flag = 1;
        H.a[index].key = x;
    }
}

void traverseAllHash(Hash &H)
{
    for (int i = 0; i < M; i++)
    {
        if (H.a[i].flag == 1)
            cout << H.a[i].key << " ";
        else
            cout << -1 << " ";
    }
}
int main()
{
    Hash H;
    initHash(H);

    int n, x;
    cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << "\nInsert " << x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H);

    return 0;
}
