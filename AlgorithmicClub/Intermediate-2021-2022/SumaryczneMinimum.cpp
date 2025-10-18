//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;
vector<int> drzewo(M*2+1);

void update(int indeks,int wartosc)
{
    indeks=indeks+M;
    drzewo[indeks]=wartosc;
    while(indeks!=1)
    {
        indeks=indeks/2;
        drzewo[indeks]=min(drzewo[indeks*2],drzewo[indeks*2+1]);
    }
}
int query(int poczatek,int koniec)
{
    poczatek=poczatek+M;
    koniec=koniec+M;

    int wynik=min(drzewo[poczatek],drzewo[koniec]);

    while(poczatek/2!=koniec/2)
    {
        if(poczatek%2==0)
        {
            wynik=min(wynik,drzewo[poczatek+1]);
        }
        if(koniec%2==1)
        {
            wynik=min(wynik,drzewo[koniec-1]);
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
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(i,a);
    }

    cin>>q;
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            cout<<query(a,b)<<endl;
        }
        else
        {
            update(a,b);
        }
    }
    return 0;
}
 