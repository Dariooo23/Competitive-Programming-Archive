//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int potega1=7,potega2=19;
const int M=1<<20,modulo=1e9+696969;

vector<long long int> potegi1(300000);
vector<long long int> potegi2(300000);

vector<pair<int,int>> szyby(300000);
vector<pair<long long int,long long int>> drzewo(M*2+1);

void potegowanie(int m)
{
    potegi1[0]=1;
    potegi2[0]=1;

    for(int i=1;i<=m;i++)
    {
        potegi1[i]=(potegi1[i-1]*potega1)%modulo;
        potegi2[i]=(potegi2[i-1]*potega2)%modulo;
    }
}

void update(int poczatek,int koniec,long long int hash1,long long int hash2)
{
    poczatek=poczatek+M;
    koniec=koniec+M;

    drzewo[poczatek].first=(drzewo[poczatek].first+hash1+modulo)%modulo;
    drzewo[poczatek].second=(drzewo[poczatek].second+hash2+modulo)%modulo;

    if(poczatek!=koniec)
    {
        drzewo[koniec].first=(drzewo[koniec].first+hash1+modulo)%modulo;
        drzewo[koniec].second=(drzewo[koniec].second+hash2+modulo)%modulo;
    }

    while(poczatek/2!=koniec/2)
    {
        if(poczatek%2==0)
        {
            drzewo[poczatek+1].first=(drzewo[poczatek+1].first+hash1+modulo)%modulo;
            drzewo[poczatek+1].second=(drzewo[poczatek+1].second+hash2+modulo)%modulo;
        }
        if(koniec%2==1)
        {
            drzewo[koniec-1].first=(drzewo[koniec-1].first+hash1+modulo)%modulo;
            drzewo[koniec-1].second=(drzewo[koniec-1].second+hash2+modulo)%modulo;
        }

        poczatek=poczatek/2;
        koniec=koniec/2;
    }
}
pair<long long int,long long int> query(int indeks)
{
    indeks=indeks+M;

    pair<long long int,long long int> wynik={drzewo[indeks].first,drzewo[indeks].second};

    while(indeks!=1)
    {
        indeks=indeks/2;

        wynik.first=(wynik.first+drzewo[indeks].first)%modulo;
        wynik.second=(wynik.second+drzewo[indeks].second)%modulo;
    }

    return wynik;   
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    potegowanie(m);

    for(int i=1;i<=m;i++)
    {
        int poczatek,koniec;
        cin>>poczatek>>koniec;
        szyby[i]={poczatek,koniec};
    }

    int szyba1,szyba2;
    while(q--)
    {
        char operacja;
        cin>>operacja;
        if(operacja=='?')
        {
            cin>>szyba1>>szyba2;
            if(query(szyba1)==query(szyba2))
            {
                cout<<"TAK"<<endl;
            }
            else
            {
                cout<<"NIE"<<endl;
            }
        }
        else
        {
            cin>>szyba1;

            if(operacja=='+')
            {
                update(szyby[szyba1].first,szyby[szyba1].second,potegi1[szyba1],potegi2[szyba1]);
            }
            else
            {
                update(szyby[szyba1].first,szyby[szyba1].second,potegi1[szyba1]*-1,potegi2[szyba1]*-1);
            }
        }
    }
    return 0;
}
 