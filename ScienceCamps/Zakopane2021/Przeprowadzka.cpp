#include <bits/stdc++.h>

using namespace std;



long long int bin(long long int l,long long int r,long long int n, long long int tokeny,long long int* ksiazki)
{
    if(l==r)
    {
        return l;
    }
  long long int srodek=(l+r)/2;
  long long int prze=srodek;
  long long int tokeny2=tokeny;
    for(int i=0;i<n;i++)
    {
        if(prze>=ksiazki[i])
        {
            prze=prze-ksiazki[i];
        }
        else
        {
            tokeny2--;
            prze=srodek-ksiazki[i];
        }
    }
    tokeny2--;
    if(tokeny2<0)
    {
        return bin(srodek+1,r,n,tokeny,ksiazki);
    }
    else
    {
        return bin(l,srodek,n,tokeny,ksiazki);
    }
}

void solve()
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
    for(int j=n-1;j>k+1000;j--)
    {
        suma=suma-ksiazki[j];
    }

    if(suma<naj)
    {
       long long int a=suma;
        suma=naj;
        naj=a;
    }
    cout<<bin(naj,suma,n,k,ksiazki)<<endl;
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
        solve();
    }
    return 0;
}