//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int dlugosc1,dlugosc2;

const long long int podstawa=5e5+69;
const long long int modulo=1e9+696969;

vector<int> ksiega1;
vector<int> ksiega2;
vector<long long int> hash_ksiegi1;
vector<long long int> hash_ksiegi2;
vector<long long int> potegi_podstawy;
vector<vector<pair<int, long long int>>> alfabet_ksiegi1(1e6);

void potegowanie(int dlugosc)
{
    potegi_podstawy.resize(dlugosc+1);
    potegi_podstawy[0]=1;

    for(int i=1;i<=dlugosc;i++)
    {
        potegi_podstawy[i]=(potegi_podstawy[i-1]*podstawa)%modulo;
    }
}
void hashowanie_ksiegi1(int dlugosc)
{
    hash_ksiegi1[0]=0;
    for(int i=1;i<=dlugosc;i++)
    {
        hash_ksiegi1[i]=(hash_ksiegi1[i-1]+(((ksiega1[i])%modulo)*potegi_podstawy[i])%modulo)%modulo;
    }
}
void hashowanie_ksiegi2(int dlugosc)
{
    hash_ksiegi2[0]=0;
    for(int i=1;i<=dlugosc;i++)
    {
        hash_ksiegi2[i]=(hash_ksiegi2[i-1]+(((ksiega2[i])%modulo)*potegi_podstawy[i])%modulo)%modulo;
    }
}
void alfabetowanie_ksiegi1(int dlugosc)
{
    for(int i=0;i<=1e6;i++)
    {
        alfabet_ksiegi1[i].push_back({0,0});
    }
    for(int i=1;i<=dlugosc;i++)
    {
        int indeks=ksiega1[i];
        alfabet_ksiegi1[indeks].push_back({i,potegi_podstawy[i]});
        alfabet_ksiegi1[indeks][alfabet_ksiegi1[indeks].size()-1].second+=
        alfabet_ksiegi1[indeks][alfabet_ksiegi1[indeks].size()-2].second; 
        alfabet_ksiegi1[indeks][alfabet_ksiegi1[indeks].size()-1].second%=modulo;
    }
}
long long int oblicz_podhash(int poczatek,int dlugosc,int ksiega)
{
    if(ksiega==1)return (hash_ksiegi1[poczatek+dlugosc]-hash_ksiegi1[poczatek-1]+modulo)%modulo;
            else return (hash_ksiegi2[poczatek+dlugosc]-hash_ksiegi2[poczatek-1]+modulo)%modulo;
}
bool porownaj_hashe(int poczatek1,int poczatek2,int dlugosc,long long int mnoznik1,long long int mnoznik2)
{
    long long int hash1=(oblicz_podhash(poczatek1,dlugosc,1)*mnoznik2)%modulo;
    long long int hash2=(oblicz_podhash(poczatek2,dlugosc,2)*mnoznik1)%modulo;
    return hash1==hash2;
}
pair<int,int> bean_search_hashy(int poczatek1,int poczatek2,int dlugosc,long long int mnoznik1,long long int mnoznik2)
{
    int l=0,r=dlugosc-1,mid=(l+r)/2;
    while(l<r)
    {
        mid=(l+r)/2;
        if(porownaj_hashe(poczatek1,poczatek2,mid,mnoznik1,mnoznik2))l=mid+1;
                                                                else r=mid;
    }
    return {l+poczatek1,l+poczatek2};
}
int bean_search_poczatek(int liczba,int indeks_szukany,int poczatek,int koniec)
{
    int l=poczatek,r=koniec,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(indeks_szukany>alfabet_ksiegi1[liczba][mid].first)l=mid+1;
                                                        else r=mid;
    }
    return l;
}
int bean_search_koniec(int dlugosc,int liczba,int indeks_szukany,int poczatek,int koniec)
{
    int l=poczatek,r=koniec,mid;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(indeks_szukany+dlugosc-1 >= alfabet_ksiegi1[liczba][mid].first)l=mid;
                                                                  else r=mid-1; 
    }
    return l;
}
bool solve()
{
    long long int roznica;
    int poczatek1,poczatek2,dlugosc;
    cin>>poczatek1>>poczatek2>>dlugosc;

    if(porownaj_hashe(poczatek1,poczatek2,dlugosc-1,potegi_podstawy[poczatek1],potegi_podstawy[poczatek2])) return 1;
    pair<int,int> rozne_znaki=bean_search_hashy(poczatek1,poczatek2,dlugosc,potegi_podstawy[poczatek1],potegi_podstawy[poczatek2]);

    int poczatek_alfabetu=bean_search_poczatek(ksiega1[rozne_znaki.first],
    poczatek1,0,alfabet_ksiegi1[ksiega1[rozne_znaki.first]].size()-1);
    int koniec_alfabetu=bean_search_koniec(dlugosc,ksiega1[rozne_znaki.first],
    poczatek1,0,alfabet_ksiegi1[ksiega1[rozne_znaki.first]].size()-1);

    long long int hash1=oblicz_podhash(poczatek1,dlugosc-1,1);
    //cout<<hash1<<" ";
    long long int prefiks=(alfabet_ksiegi1[ksiega1[rozne_znaki.first]][koniec_alfabetu].second
    -alfabet_ksiegi1[ksiega1[rozne_znaki.first]][poczatek_alfabetu-1].second+modulo)%modulo;

    hash1=((hash1-(prefiks*ksiega1[rozne_znaki.first])%modulo)+modulo)%modulo;
    //cout<<hash1<<" ";
    hash1=(hash1+(prefiks*ksiega2[rozne_znaki.second])%modulo)%modulo;
    cout<<hash1<<endl;

    hash1=(hash1*potegi_podstawy[poczatek2])%modulo;

    long long int hash2=oblicz_podhash(poczatek2,dlugosc-1,2);
    hash2=(hash2*potegi_podstawy[poczatek1])%modulo;
    //cout<<hash1<<" "<<hash2<<endl;

    if(hash1==hash2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>dlugosc1;
    ksiega1.resize(dlugosc1+1);
    for(int i=1;i<=dlugosc1;i++)cin>>ksiega1[i];

    cin>>dlugosc2;
    ksiega2.resize(dlugosc2+1);
    for(int i=1;i<=dlugosc2;i++)cin>>ksiega2[i];

    potegowanie(max(dlugosc1,dlugosc2));
    hash_ksiegi1.resize(dlugosc1+1);
    hashowanie_ksiegi1(dlugosc1);
    hash_ksiegi2.resize(dlugosc2+1);
    hashowanie_ksiegi2(dlugosc2);
    alfabetowanie_ksiegi1(dlugosc1);

    /*cout<<endl<<endl;
    for(int i=0;i<=dlugosc1;i++)
    {
        cout<<hash_ksiegi1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=dlugosc2;i++)
    {
        cout<<hash_ksiegi2[i]<<" ";
    }
    cout<<endl;*/
    /*cout<<endl<<endl;
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<alfabet_ksiegi1[i].size();j++)
        {
            cout<<alfabet_ksiegi1[i][j].first<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;*/

    int testy;
    cin>>testy;
    while(testy--)
    {
        if(solve())
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    
    return 0;
}
 