//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct punkt{
    int nr,koszt;
};

bool cmp_sort(const punkt &a, const punkt &b)
{
    if(a.koszt==b.koszt)
    {
        return a.nr<b.nr;
    }
    else
    {
        return a.koszt<b.koszt;
    }
}

vector<vector<pair<int,int>>> ulomny_graf;
vector<vector<punkt>> nowe_punkty;
vector<long long int> dist;

struct Cmp
{
    bool operator()(const int &a, const int &b) const
    {
        return dist[a]<=dist[b];
    }
};

void dijkstra(int start)
{
    dist[start]=0;
    set<int,Cmp> kolejka;

    kolejka.insert(start);
    while(!kolejka.empty())
    {
        int wierzcholek=*kolejka.begin();
        kolejka.erase(kolejka.begin());
        for(const pair<int,int> &krawedz1:ulomny_graf[wierzcholek])
        {
            if(dist[wierzcholek]+krawedz1.second<dist[krawedz1.first])
            {
                if(kolejka.find(krawedz1.first)!=kolejka.end())
                {
                    kolejka.erase(krawedz1.first);
                }
                dist[krawedz1.first]=dist[wierzcholek]+krawedz1.second;
                kolejka.insert(krawedz1.first);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int miasta,drogi,nowy_punkt=2;
    cin>>miasta>>drogi;

    nowe_punkty.resize(500000);
    ulomny_graf.resize(500000);
    dist.resize(500000,1e18+9);

    for(int i=0;i<drogi;i++)
    {
        int a,b,koszt,x=nowy_punkt,y=nowy_punkt+1;
        nowy_punkt=nowy_punkt+2;
        cin>>a>>b>>koszt;

        nowe_punkty[a].push_back({x,koszt});
        nowe_punkty[b].push_back({y,koszt});
        ulomny_graf[x].push_back({y,koszt});
        ulomny_graf[y].push_back({x,koszt});   
    }
    for(int i=1;i<=miasta;i++)
    {
        sort(nowe_punkty[i].begin(),nowe_punkty[i].end(),cmp_sort);
        for(int j=0;j<nowe_punkty[i].size();j++)
        {
            if(j+1>=nowe_punkty[i].size())
            {
                continue;
            }
            int roznica=nowe_punkty[i][j+1].koszt-nowe_punkty[i][j].koszt;
            ulomny_graf[nowe_punkty[i][j].nr].push_back({nowe_punkty[i][j+1].nr,roznica});
            ulomny_graf[nowe_punkty[i][j+1].nr].push_back({nowe_punkty[i][j].nr,0});
        }
    }

    for(int i=0;i<nowe_punkty[1].size();i++)
    {
        ulomny_graf[1].push_back({nowe_punkty[1][i].nr,nowe_punkty[1][i].koszt});
    }
    for(int i=0;i<nowe_punkty[miasta].size();i++)
    {
        ulomny_graf[nowe_punkty[miasta][i].nr].push_back({nowy_punkt,0});
    }

    dijkstra(1);
    cout<<dist[nowy_punkt];
    
    return 0;
}
 