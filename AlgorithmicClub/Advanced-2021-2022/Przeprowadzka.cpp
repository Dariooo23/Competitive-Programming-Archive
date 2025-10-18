#include <bits/stdc++.h>

using namespace std;



long long int bin(long long int l,long long int r,long long int n, long long int przejazdy,long long int* ksiazki)
{
    if(l==r)
    {
        return l;
    }

    long long int srodek=(l+r)/2;
    long long int prze=srodek;
    long long int przejazdy2=przejazdy;

    for(int i=0;i<n;i++)
    {
        if(prze>=ksiazki[i])
        {
            prze=prze-ksiazki[i];
        }
        else
        {
            przejazdy2--;
            prze=srodek-ksiazki[i];
        }
    }

    przejazdy2--;

    if(przejazdy2<0)
    {
        return bin(srodek+1,r,n,przejazdy,ksiazki);
    }
    else
    {
        return bin(l,srodek,n,przejazdy,ksiazki);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long int n,k;
        cin>>n>>k;

        long long int ksiazki[n];
        long long int suma=0,naj=0;

        for(int i=0;i<n;i++)
        {
            cin>>ksiazki[i];
            naj=max(ksiazki[i],naj);
            suma=suma+ksiazki[i];
        }

        cout<<bin(naj,suma,n,k,ksiazki)<<endl;
    }
    return 0;
}