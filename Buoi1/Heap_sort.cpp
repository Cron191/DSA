#include<iostream>
using namespace std;

void Heapify(int a[], int n, int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l<n && a[l]> a[max]) max=l;
    if(r<n && a[r]> a[max]) max=r;
    if(max!=i)
    {
        swap(a[max],a[i]);
        Heapify(a,n,max);
    }
}
void Heap_sort(int a[], int n)
{
    // xay dung max heap
    for(int i=n/2-1; i>=0; i--) Heapify(a,n,i);
    //
    for(int i=n-1;i>=0;i--)
    {
        swap(a[i],a[0]);
        Heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    Heap_sort(a,n);
    for(int x:a)
    cout<<x<<" ";

}