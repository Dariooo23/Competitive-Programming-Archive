#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,najwieksza=0;
    cin>>a>>b;
    long long int tab[a];
    for(int i=0;i<a;i++)
    {
        cin>>tab[i];
        if(tab[i]>najwieksza)
        {
            najwieksza=tab[i];
        }
    }

    for(int i=0;i<a;i++)
    {
        b=b-(najwieksza-tab[i]);
        if(b<=0)
        {
            break;
        }
    }
    if(b<=0)
    {
        cout<<najwieksza;
    }
    else
    {
        if(b%a==0)
        {
            cout<<najwieksza+(b/a);
        }
        else
        {
             cout<<najwieksza+(b/a)+1;
        }
    }

    return 0;
}