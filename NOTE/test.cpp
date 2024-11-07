#include <iostream>
using namespace std;
int SoDao(int n)
{
    while (n % 10 == 0)
        n = n / 10;
    int m = 0;
    while (n != 0)
    {
        m = m + n % 10;
        n = n / 10;
        m *= 10;
    }
    return m / 10;
}
int main()
{
    int n;
    cin >> n;
    int sum = n + SoDao(n);
    while(sum>999)
    {
        sum=sum/10;
    }
    cout<<sum%10;
}