//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,m,k;
vector<vector<pair<int,long long int>>> g;
vector<long long int> dist;
vector<long long int> dp;

struct Cmp
{
    bool operator()(const int &a, const int &b) const
    {
        return dist[a]<=dist[b];
    }
};
void dijkstra(long long int ilosc)
{
    set<int,Cmp> kolejka;
    for(int i=1;i<=ilosc;i++)
    {
        if(dist[i]<1e18)
        {
            kolejka.insert(i);
        }
    }
    while(!kolejka.empty())
    {
        int wierzcholek=*kolejka.begin();
        kolejka.erase(kolejka.begin());
        for(const pair<int,long long int> &krawedz:g[wierzcholek])
        {
            if(dist[wierzcholek]+krawedz.second<dist[krawedz.first])
            {
                if(kolejka.find(krawedz.first)!=kolejka.end())
                {
                    kolejka.erase(krawedz.first);
                }
                dist[krawedz.first]=dist[wierzcholek]+krawedz.second;
                kolejka.insert(krawedz.first);
            }
        }
    }
}

void oblicz_dp(long long int l,long long int r,long long int p,long long int k)
{
    if(l>r)return;
    long long int mid=(l+r)/2,indeks=0;
    for(long long int i=p;i<=k;i++)
    {
        if(dist[i]+(i-mid)*(i-mid)<dp[mid])
        {
            indeks=i;
            dp[mid]=dist[i]+(i-mid)*(i-mid);
        }
    }
    oblicz_dp(l,mid-1,p,indeks);
    oblicz_dp(mid+1,r,indeks,k);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m>>k;

    g.resize(n+1);
    dp.resize(n+1);
    dist.resize(n+1,1e18);

    for(int i=1;i<=m;i++)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dist[1]=0;
    dijkstra(n);
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i]=1e18;
        }
        oblicz_dp(1,n,1,n);
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dp[j]);
        }
        dijkstra(n);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
 