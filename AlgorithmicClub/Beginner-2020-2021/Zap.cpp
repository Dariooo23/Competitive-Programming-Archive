#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,wynik=n;
    cin>>n;
    int pref[n+1];
    int suf[n];
    int zapalki[n+1];
    for (int i=1;i<n+1;i++)
    {
        cin>>zapalki[i];
    }

    pref[0] = 0;
    for (int i=1;i<n+1;i++)
    {
        pref[i]=pref[i-1]+1-zapalki[i];
    }


    suf[n+1] = 0;
    for (int i=n;i>0;i--)
    {
        suf[i]=suf[i+1]+zapalki[i];
    }


    for (int i=0;i<=n;i++)
    {
       wynik=min(wynik,pref[i]+suf[i+1]);
    }
    cout<<wynik;


    return 0;
}