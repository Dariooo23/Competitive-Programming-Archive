//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct krawedz 
{
    int a,b,waga,nr;
};

vector<krawedz> krawedzie;

struct FindUnion
{
    long long int n;
    long long int licz;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int x)
    {
        n = x;
        licz=n;
        parent.resize(n);
        rank.resize(n);
        for(long long int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
        return;
    }

    long long int find(long long int x)
    {
        if(parent[x]==x)
        {
            return x;
        }

        parent[x]=find(parent[x]);

        return parent[x];
    }

    void uni(long long int x,long long int y)
    {
        long long int a=find(x);
        long long int b=find(y);

        if(a==b)
        {
            return;
        }
        licz--;

        if(rank[a]>rank[b]) 
        {
            parent[b]=a;
        }
        else
        {
            parent[a]=b;
        }

        if(rank[a]==rank[b])
        {
            rank[a]++;
        }
        return;
    }

    long long int operator[](long long int x){
        return find(x);
    }
    long long int operator()(long long int x){
        return find(x);
    }
    void operator()(long long int a,long long int b){
        uni(a,b);
        return;
    }
};

bool cmp(const krawedz &a,const krawedz &b)
{
    if(a.waga==b.waga)
    {
        return a.nr<b.nr;
    }
    else
    {
        return a.waga<b.waga;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Algorytm tworzacy minimalne drzewo rozpinajace czyli
    // takie ktore ma n-1 krawedzi gdzie n to ilosc punktow o najmniejszych mozliwych wagach
    int n,m;
    cin>>n>>m;

    FindUnion fau(n+1);

    for(int nr=1;nr<=m;nr++)
    {
        int a,b,waga;
        cin>>a>>b>>waga;
        krawedzie.push_back({a,b,waga,nr});
    }

    sort(krawedzie.begin(),krawedzie.end(),cmp);

    for(int i=0;i<krawedzie.size();i++)
    {
        if(fau.find(krawedzie[i].a)!=fau.find(krawedzie[i].b))
        {
            fau.uni(krawedzie[i].a,krawedzie[i].b);
            cout<<krawedzie[i].nr<<endl;
        }
    }
    
    return 0;
}