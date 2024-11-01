
#include <iostream>

using namespace std;
#define MAXN 150000
void NhapMang(int *a, int n)
{
    for(int i=0;i<n;i++)
    cin>>a[i];
}

int binary_search(int a[], int n, int x)
{
    int l,r,m;
    l=0;
    r=n-1;
    m=(r+l)/2;
    while( l<r)
    {
        if(x > a[m]) 
        {
            l=m+1;
            m=(l+r)/2;
        }
        else if(x < a[m]) 
        {
            r=m-1;
            m=(l+r)/2;
        }
        else return 1;
    }
    return -1;
} 

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i= binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}


