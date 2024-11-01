
#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge(int a[], int l, int mid, int r)
{
    int len1=mid-l+1;
    int len2=r-mid;
    int left[len1], right[len2];
    for(int i=0;i<len1;i++)
    left[i]=a[l+i];
    for(int i=0;i<len2;i++)
    right[i]=a[i+mid+1];
    int i=0,j=0,k=l;
    while(i<len1 && j<len2)
    {
        if(left[i]<=right[j]) a[k++]=left[i++];
        else a[k++]=right[j++];
    }
    while(i<len1) a[k++]=left[i++];
    while(j<len2) a[k++]=right[j++];
}

void mergeSortRange(int input[], int from, int to) {
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n) {
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
