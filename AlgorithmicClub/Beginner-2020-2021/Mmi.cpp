#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a,b,c,d;
    cin>>a;
    cin>>b;
    d=b;
    for (int i=0;i<a-1;i++)
    {
        cin>>c;
        if (c<b)
        {
            b=c;
        }
        if (c>d)
        {
            d=c;
        }

    }
    cout<<setprecision(2)<<fixed<<b<<" "<<d;
    return 0;
}