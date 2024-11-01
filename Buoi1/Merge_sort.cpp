#include<iostream>
using namespace std;



void Merge(int a[], int l, int m,int r) //0 2 4
{
    int len1=m-l+1;
    int len2=r-m;   
    int left[len1], right[len2];
    for(int i=0;i<len1;i++)
    left[i]=a[i+l];
    for(int i=0;i<len2;i++)
    right[i]=a[i+m+1];
    int i=0,j=0;
    int k=l;
    while(i<len1 && j<len2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<len1) 
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<len2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}

void Merge_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int m=(r+l)/2;
        Merge_sort(a,l,m);
        Merge_sort(a,m+1,r);
        Merge(a,l,m,r);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Merge_sort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}