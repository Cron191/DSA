#include<iostream>
using namespace std;
void quick_sort(int a[], int l, int r)
{
    int pivot=a[(l+r)/2];
    int i=l, j=r;
    while(i<=j)
    {
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j) quick_sort(a,l,j);
    if(i<r) quick_sort(a,i,r);

}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    quick_sort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
    
}