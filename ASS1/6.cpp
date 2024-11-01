
#include <iostream>
#define MAXN 60000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Function to sort an array a[] of size 'n'
void binary_insertion_sort(int a[], int n) {
    int i, j, k, selected;

    for (i = 1; i < n; ++i) 
    {
        j = i - 1;
        selected = a[i];
        int r,l,m;
        bool ok=false;
        l=0;
        r=i-1;
        m=(r+l)/2;
        while(l<=r)
        {
            if(a[m]== selected) 
            {
                k=m;
                ok=true;
                break;
            }
            else if(a[m]>selected)
            {
                l=m+1;
                m=(l+r)/2;
            }
            else if(a[m]< selected) 
            {
                r=m-1;
                m=(l+r)/2;
            }
        }
        if(!ok) k=l;
        while(j>=k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
bool is_decending(int A[], int N) {
    for (int i = 0; i < N-1; i++)
        if(A[i]<A[i+1]) return false;
    return true;
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);

    return 0;
}
