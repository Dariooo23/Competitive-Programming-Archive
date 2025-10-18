//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL wynik=0;
const LL podstawa1=53;
const LL podstawa2=71;
const LL modulo=1e9+696969;

vector<LL> potegi_podstawy1;
vector<LL> potegi_podstawy2;
vector<pair<LL,LL>> hash_sekwencji;

struct hashowanie{
    pair<LL,LL> hash;
    LL indeks,ilosc;
};

void stworz_potegi(const LL &n){
    potegi_podstawy1.resize(n+1);
    potegi_podstawy1[0]=1;
    for(int i=1;i<=n;i++){
        potegi_podstawy1[i]=(potegi_podstawy1[i-1]*podstawa1)%modulo;
    }

    potegi_podstawy2.resize(n+1);
    potegi_podstawy2[0]=1;
    for(int i=1;i<=n;i++){
        potegi_podstawy2[i]=(potegi_podstawy2[i-1]*podstawa2)%modulo;
    }
}

void stworz_hash_sekwencji(LL n,string sekwencja){
    hash_sekwencji.resize(n+1);
    hash_sekwencji[0]={0,0};
    for(int i=1;i<=n;i++){
        hash_sekwencji[i].first=(hash_sekwencji[i-1].first+(((sekwencja[i-1]-'A'+1)*potegi_podstawy1[i])%modulo))%modulo;
        hash_sekwencji[i].second=(hash_sekwencji[i-1].second+(((sekwencja[i-1]-'A'+1)*potegi_podstawy2[i])%modulo))%modulo;
    }
}

struct FindUnion
{
    long long int n;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int x){
        n=x;
        parent.resize(n);
        rank.resize(n);

        for(long long int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
        return;
    }

    LL find(LL x){
        if(parent[x]==x){
            return x;
        }

        parent[x]=find(parent[x]);
        return parent[x];
    }

    void uni(LL x,LL y,LL ilosc)
    {
        x=find(x);
        y=find(y);

        rank[x]=rank[x]+ilosc;
        if(x==y){
            wynik=max(wynik,rank[x]);
            return;
        }
        if(rank[x]<rank[y])
        {
            swap(x,y);
        }

        parent[y]=x;
        rank[x]=rank[x]+rank[y];
    }

    LL operator()(LL x){
        return find(x);
    }
    void operator()(LL a,LL b,LL c){
        uni(a,b,c);
        return;
    }
};

void solve(LL n,string sekwencja) 
{
    LL m;
    cin>>m;
    wynik=0;
    FindUnion fau(n+1);
    map<pair<LL,LL>,hashowanie> indeksy;

    for(int i=m;i<=n;i++){
        pair<LL,LL> hash1={0,0};
        hash1.first=((hash_sekwencji[i].first-hash_sekwencji[i-m].first+modulo)%modulo);
        hash1.second=((hash_sekwencji[i].second-hash_sekwencji[i-m].second+modulo)%modulo);
        hash1.first=((hash1.first*potegi_podstawy1[n-i])%modulo);
        hash1.second=((hash1.second*potegi_podstawy2[n-i])%modulo);                        

        if(indeksy.find(hash1)==indeksy.end()){
            indeksy[hash1]={hash1,i,1};
        }else{
            indeksy[hash1].ilosc++;
        }
    }
    for(auto it=indeksy.begin();it!=indeksy.end();++it){
        pair<LL,LL> hash2=it->second.hash;
        hash2.first=((hash2.first-(((sekwencja[it->second.indeks-1]-'A'+1)*potegi_podstawy1[n])%modulo)+modulo)%modulo);
        hash2.first=((hash2.first*podstawa1)%modulo);
        hash2.first=((hash2.first+(((sekwencja[it->second.indeks-1]-'A'+1)*potegi_podstawy1[n-m+1])%modulo))%modulo);

        hash2.second=((hash2.second-(((sekwencja[it->second.indeks-1]-'A'+1)*potegi_podstawy2[n])%modulo)+modulo)%modulo);
        hash2.second=((hash2.second*podstawa2)%modulo);
        hash2.second=((hash2.second+(((sekwencja[it->second.indeks-1]-'A'+1)*potegi_podstawy2[n-m+1])%modulo))%modulo);

        if(indeksy.find(hash2)!=indeksy.end()){
            fau.uni(indeksy[it->second.hash].indeks,indeksy[hash2].indeks,indeksy[it->second.hash].ilosc);
        }
    }

    cout<<wynik<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    LL n,q;
    string sekwencja;
    cin>>n>>q>>sekwencja;

    stworz_potegi(n);
    stworz_hash_sekwencji(n,sekwencja);

    while(q--){
        solve(n,sekwencja);
    }

    return 0;
}
 