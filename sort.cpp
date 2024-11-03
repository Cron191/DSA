#include <iostream>
using namespace std;

// SELECTION_SORT O(N^2) O(N^2) O(N^2)
void Selection_sort(int a[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        if (min != i)
            swap(a[min], a[i]);
    }
}

// INTERCHANGE_SORT O(N^2) O(N^2) O(N^2)
void Interchange_Sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]);
}

// INSERTION_SORT O(N^2) O(N^2) O(N)
void Insertion_Sort(int a[], int n)
{
    int x, pos;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i;
        while (pos > 0 && a[pos - 1] > x)
        {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

// QUICK_SORT O(N^N) O(Nlog(N)) O(Nlog(N))
void Quick_Sort(int a[], int l, int r)
{
    int i = l, j = r, pivot = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        Quick_Sort(a, l, j);
    if (i < r)
        Quick_Sort(a, i, r);
}

// MERGE_SORT O(Nlog(N)) O(Nlog(N)) O(Nlog(N))
void Merge(int a[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = a[i + l];
    for (int i = 0; i < len2; i++)
        right[i] = a[i + m + 1];
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < len1)
        a[k++] = left[i++];
    while (j < len2)
        a[k++] = right[j++];
}
void Merge_Sort(int a[], int l, int r)
{
    int m = (l + r) / 2;
    if (l < r)
    {
        Merge_Sort(a, l, m);
        Merge_Sort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

// HEAP_SORT O(Nlog(N)) O(Nlog(N)) O(Nlog(N))
void Heapify(int a[], int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, max = i;
    if (left < n && a[left] > a[max])
        max = left;
    if (right < n && a[right] > a[max])
        max = right;
    if (max != i)
    {
        swap(a[max], a[i]);
        Heapify(a, n, max);
    }
}
void Heap_Sort(int a[], int n)
{
    for (int i = (n - 1) / 2; i > 0; i--)
        Heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        n--;
        Heapify(a, n, 0);
    }
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Selection_sort(a, n);
    // Interchange_Sort(a, n);
    // Insertion_Sort(a, n);
    // Quick_Sort(a, 0, n - 1);
    // Merge_Sort(a, 0, n - 1);
    // Heap_Sort(a, n);
    for (int x : a)
        cout << x << " ";
}