#include <iostream>

using namespace std;

int main()
{
    int n,m,lp=1,wynik=0;
cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>m;
        if (m==lp)
        {
            lp=lp+1;
        }
        else
        {
            wynik=wynik+1;
        }
    }
    cout<<wynik;

    return 0;
}