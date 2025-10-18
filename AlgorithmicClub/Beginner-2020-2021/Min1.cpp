#include <iostream>

using namespace std;

int main()
{
    int n,nl,n1;
cin>>nl;
    while (cin>>n)
    {
        if (n<nl)
        {
            nl=n;
        }
    }
    cout<<nl;
    return 0;
}