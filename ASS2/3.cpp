#include <iostream>
#include <climits>
#include <bits/stdc++.h>
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



void merge_2_Sorted_subArray(int a[], int l, int middle, int r)
{
    int len1=middle-l+1;
    int len2=r-middle;
    int left[len1], right[len2];
    for(int i=0;i<len1;i++)
    left[i]=a[i+l];
    for(int i=0;i<len2;i++)
    right[i]=a[i+middle+1];
    int i=0, j=0, k=l;
    while(i<len1 && j< len2)
    {
        if(left[i]<=right[j]) a[k]=left[i++];
        else a[k]=right[j++];
        k++;
    }
    while(i<len1) a[k++]=left[i++];
    while(j<len2) a[k++]=right[j++];
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

	int l=0, r=n-1, middle =(l+r)/2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
