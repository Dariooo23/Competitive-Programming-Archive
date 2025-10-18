//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int>> dist;
vector<vector<int>> graf;
vector<pair<int,int>> visited;

void bfs(){
    queue<pair<int,int>> kolejka;
    kolejka.push({1,1});

    while(!kolejka.empty()){
        pair<int,int> s=kolejka.front();
        kolejka.pop();

        if(s.second==1){
            visited[s.first].first=1;
        }else{
            visited[s.first].second=1;
        }

        for(int v:graf[s.first]){
            if(s.second==1){
                if(visited[v].second==1)continue;
            }else{
                if(visited[v].first==1)continue;
            }

            if(s.second==1){
                kolejka.push({v,2});
            }else{
                kolejka.push({v,1});
            }

            if(s.second==1){
                dist[v].second=dist[s.first].first+1;
            }else{
                dist[v].first=dist[s.first].second+1;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m;

    graf.resize(n+1);
    dist.resize(n+1);
    visited.resize(n+1);

    dist[n].first=-1;
    dist[n].second=-1;
    dist[1].first=0;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    bfs();

    int wynik1=1e9,wynik2=1e9;

    if(dist[n].first!=-1 && dist[n].first%2==0){
        wynik1=dist[n].first;
    }
    if(dist[n].second!=-1 && dist[n].second%2==0){
        wynik2=dist[n].second;
    }

    if(min(wynik1,wynik2)==1e9){
        cout<<"-1"<<endl;
    }else{
        cout<<min(wynik1,wynik2);
    }
    return 0;
}