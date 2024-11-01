#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

void chuyen(float a)
{
    float x=a;
    int d=0;
    while(!(floor(x)==x)) 
    {
        x*=10;
        d++;
    }
    if(d>2) 
    cout<<fixed<<setprecision(2)<<a;
    else cout<<a;

}

int main() {
    chuyen(5.3);
    return 0;
}
