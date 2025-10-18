// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n, m;
vector<long long int> dist;
vector<vector<pair<long long int, long long int>>> g;

void dijkstra(long long int start){
    set<pair<long long int,long long int>> kolejka;

    dist[start]=0;
    kolejka.insert({dist[start],start});

    while(!kolejka.empty()){
        pair<long long int,long long int> wierzcholek=*kolejka.begin();
        kolejka.erase(kolejka.begin());

        for(const pair<long long int,long long int> &krawedz:g[wierzcholek.second]){
            if(dist[krawedz.first]>dist[wierzcholek.second]+krawedz.second){
                if(kolejka.find({dist[krawedz.first],krawedz.first})!=kolejka.end()){
                    kolejka.erase({dist[krawedz.first],krawedz.first});
                }

                dist[krawedz.first]=dist[wierzcholek.second]+krawedz.second;
                kolejka.insert({dist[krawedz.first],krawedz.first});
            }
        }
    }

    return;
}
 


int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    g.resize(600000);
    dist.resize(600000,1e18);
    for (int i=1;i<=m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        g[b].push_back({a,c});
    }

    dijkstra(1);
    for (int i=2;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}