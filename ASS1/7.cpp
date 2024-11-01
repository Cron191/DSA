
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_last_occurrence(int a[], int n, int x)
{
    int l,r,m;
    l=0;
    r=n-1;
    m=(r+l)/2;
    while( l<=r)
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
        else if(a[m]==x)
        {
            while(a[m]==x) m++;
            return m-1;
        }
    }
    return -1;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


