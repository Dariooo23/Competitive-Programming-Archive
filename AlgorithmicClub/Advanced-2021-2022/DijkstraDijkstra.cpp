#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

long long int maks=1e18;
long long int n,m;
vector<long long int>dist;
vector<long long int>dist2;
vector<vector<pair<long long int,long long int>>> krawedzie;
vector<long long int> start;


struct Cmp
{
    bool operator()(const pair<long long int,long long int> & a,const pair<long long int, long long int>& b) const
    {
       return a.second<=b.second;
    }
};


long long int dijkstra()
{
    long long int wynik=0;
    pair<long long int,long long int> wierzcholek;
    set<pair<long long int, long long int>, Cmp> kolejka;


    for(int i=0;i<n+9;i++)
    {
        dist[i]=maks;
    }
    dist[1]=0;


    kolejka.insert({1,0});
    while(!kolejka.empty())
    {
        wierzcholek=*kolejka.begin();
        kolejka.erase(kolejka.begin());
        for(pair<long long int, long long int> const &d:krawedzie[wierzcholek.first])
        {
            if(dist[d.first]>d.second+wierzcholek.second-dist2[d.first]+dist2[wierzcholek.first])
            {
                if(kolejka.find(wierzcholek)!=kolejka.end())
                {
                kolejka.erase(wierzcholek);
                }
                start[d.first]=wierzcholek.first;
                dist[d.first]=d.second+wierzcholek.second-dist2[d.first]+dist2[wierzcholek.first];
                kolejka.insert({d.first,dist[d.first]});
            }
        }
    }
    wynik=dist[n]+dist2[n];
    return wynik;
}


void usuwanie(long long int n)
{

    for(int i=0;i<n+9;i++)
    {
        dist2[i]=dist[i];
    }
    long long int e=n;
    while(e!=1)
    {
        for(pair<long long int,long long int> &d : krawedzie[start[e]])
        {
            if(d.first==e)
            {
                krawedzie[e].emplace_back(start[e],-d.second);
                d.second=maks;
                break;
            }
        }
        e=start[e];
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n,&m);
    start.resize(n+9);
    dist.resize(n+9);
    dist2.resize(n+9);
    krawedzie.resize(n+9);


    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        krawedzie[a].emplace_back(b,c);
    }


    long long int wynik2=dijkstra();
    usuwanie(n);
    wynik2=wynik2+dijkstra();


    if(wynik2<maks)
    {
        cout<<wynik2;
    }
    else
    {
        cout<<"-1";
    }

    return 0;
}