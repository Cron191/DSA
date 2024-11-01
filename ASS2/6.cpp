
#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

void quick_sort_ascending(int a[], int n)
{
    int i,j;
    i=0;
    j=n-1;
    int pivot=a[(n-1)/2];
    while(i<=j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i<=j)
        {
            hoanvi(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(0<j) quick_sort_ascending(a,j+1);
    if(i<n-1)   quick_sort_ascending(a+i,n-i);
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
