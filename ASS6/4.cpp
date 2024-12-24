
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_first_occurrence(int a[], int n, int x)
{
    int left = 0, right = n - 1, result = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            result = mid;
            break;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
    }
    if (result == -1)
        return -1;
    if (result == 0)
        return 0;
    while (a[result - 1] == x)
        result--;
    return result;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_first_occurrence(a, n, x);

    return 0;
}
