//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int M=1<<20;
vector<long long int> drzewo(M*2+1);

long long int nwd(long long int a,long long int b)
{
    if(b)
    {
        return nwd(b,a%b);
    }
    return a;
}

void update(int indeks,long long int wartosc)
{
    indeks=indeks+M;
    drzewo[indeks]=wartosc;
    while(indeks!=1)
    {
        indeks=indeks/2;
        drzewo[indeks]=nwd(drzewo[indeks*2],drzewo[indeks*2+1]);
    }
}
long long int query(int poczatek,int koniec)
{
    poczatek=poczatek+M;
    koniec=koniec+M;

    long long int wynik=nwd(drzewo[poczatek],drzewo[koniec]);

    while(poczatek/2!=koniec/2)
    {
        if(poczatek%2==0)
        {
            wynik=nwd(wynik,drzewo[poczatek+1]);
        }
        if(koniec%2==1)
        {
            wynik=nwd(wynik,drzewo[koniec-1]);
        }

        poczatek=poczatek/2;
        koniec=koniec/2;
    }

    return wynik;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(i,a);
    }

    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(a,b);
        }
        else
        {
            cout<<query(a,b)<<endl;
        }
    }
    return 0;
}
 