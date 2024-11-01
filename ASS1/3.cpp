
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search(int a[], const int n, int x)
{
    int m;
    if(n==0) return -1;
    m=n/2;
    if(a[m]==x) return 1;
    if(x < a[m]) return binary_search(a,m,x);
    if(x > a[m]) return binary_search(a + m + 1,n - m -1,x);
}   
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i = binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}

