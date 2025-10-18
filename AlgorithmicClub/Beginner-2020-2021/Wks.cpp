#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a=0,b=0,c=0,wynik=1,n=0;
    cin>>n;
    int z[n];
    for (int i=0;i<n;i++)
    {
        cin>>z[i];
    }
    for (int i=1;i<n;i++)
    {
        if (z[i]==0)
        {
        a=1;
        }
        if (z[i]==1)
        {
        b=1;
        if (a==1)
        {
          c=1;
          wynik=max(wynik,2);
        }
        }
        if (z[i]==2)
        {
            if (c==1)
            {
                wynik=max(wynik,3);
            }
            if (a==1||b==1)
            {
                wynik=max(wynik,2);
            }
        }
    }
    cout<<wynik;
    return 0;
}