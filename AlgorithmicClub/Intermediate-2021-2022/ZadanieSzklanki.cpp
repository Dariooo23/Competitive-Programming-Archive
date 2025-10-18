//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int tab[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,a,sr=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
        sr+=tab[i];

    }

    sr/=n;
    long long int wynik=0,mag_szk=0;

    for(int i=0;i<n;i++)
    {
        mag_szk=(tab[i]-sr)+mag_szk;
        if(mag_szk!=0)wynik++;
    }

    cout<<wynik;

    return 0;
}