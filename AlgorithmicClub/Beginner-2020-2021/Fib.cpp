#include <iostream>

using namespace std;

int main()
{
     long long int NLCF,m=1,n=1,zm=0;
    cin>>NLCF;
    for (int i=2;i<NLCF;i++)
    {
    if (zm==0)
    {
        m=m+n;
        zm=1;
    }
    else
    {
        n=m+n;
        zm=0;
    }

    }

    if (NLCF%2==0)
    {
        cout<<n;
    }
    else
    {
        cout<<m;
    }
    return 0;
}