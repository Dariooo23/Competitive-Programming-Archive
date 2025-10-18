#include <bits/stdc++.h>

using namespace std;
vector<long long int> dist;
const long long int maks=1e18+9;
struct Cmp
{
    bool operator()(const long long int& a,const long long int& b) const
    {
       return dist[a]<=dist[b];
    }
};

void dijkstra()
    {
        long long int s=1,n,m,str,bubu,straznik=maks,index,index2;
        cin>>n>>m>>str;
        long long int tab[str+9];
        vector<vector<pair<long long int,long long int>>> g(2000009);
        dist.resize(2000009,maks);
        for(int i=0;i<m;i++)
        {
            long long int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        for(int i=0;i<str;i++)
        {
            cin>>tab[i];
        }
        cin>>index;


        for(int i=0;i<=n;i++)
        {
            dist[i]=maks;
        }
        dist[s]=0;
        set<long long int, Cmp> kolejka;
        kolejka.insert(s);
        while(!kolejka.empty())
        {
            long long int v=*kolejka.begin();
            kolejka.erase(kolejka.begin());
            for(auto [u,cost]:g[v])
            {
                if(dist[v]+cost<dist[u])
                {
                    if(kolejka.find(u)!=kolejka.end())
                    {
                        kolejka.erase(u);
                    }
                    dist[u]=dist[v]+cost;
                    kolejka.insert(u);
                }
            }
        }
        bubu=dist[index];
        for(int i=0;i<str;i++)
        {
            if(dist[tab[i]]<straznik)
            {
                straznik=dist[tab[i]];
                index2=i;
            }
        }
        if(straznik<=bubu)
        {
            cout<<"-1";
        }
        else
        {
            cout<<bubu;
        }
        //cout<<"BUBU:"<<index<<":"<<bubu<<"STRAZNIK:"<<index2<<":"<<straznik;
    }


int main()
{
    std::ios_base::sync_with_stdio(0);
    dijkstra();
    return 0;
}