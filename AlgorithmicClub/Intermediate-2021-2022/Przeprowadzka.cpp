//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> ksiazki;

long long int bin(long long int l,long long int r,long long int n, long long int przejazdy)
{
    if(l==r)
    {
        return l;
    }

    long long int srodek=(l+r)/2,przejazdy2=0,waga=0;

    for(int i=1;i<=n;i++)
    {
        if(waga+ksiazki[i]<=srodek)
        {
            waga=waga+ksiazki[i];
        }
        else
        {
            if(ksiazki[i]>srodek)
            {
                przejazdy2=1e9+9;
            }
            else
            {
                waga=ksiazki[i];
                przejazdy2++;
            }
        }
    }

    if(przejazdy2>=przejazdy)
    {
        return bin(srodek+1,r,n,przejazdy);
    }
    else
    {
        return bin(l,srodek,n,przejazdy);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;

    while(q--)
    {
        long long int n,k;
        cin>>n>>k;

        ksiazki.clear();
        ksiazki.resize(n+1);

        long long int poczatek=0,koniec=0;

        for(int i=1;i<=n;i++)
        {
            cin>>ksiazki[i];
            poczatek=max(ksiazki[i],poczatek);
            koniec=koniec+ksiazki[i];
        }

        cout<<bin(poczatek,koniec,n,k)<<endl;
    }
    return 0;
}