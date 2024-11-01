#include <iostream>
using namespace std;


int main()
{
    char x;
    int max=0;
    while(cin)
    {
        cin>>x;
        if(max< int(x)) max=int(x);
    }
    cout<<char(max);
}