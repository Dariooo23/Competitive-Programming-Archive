//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> topsort;
vector<int> visited;
vector<vector<int>> graf;
vector<vector<bool>> blokady;
vector<pair<int,int>> krawedz;


void dfs1(int s){

    for(const int &v:graf[s]){
        if(visited[v])continue;
        if(blokady[s][v])continue;
        visited[v]=1;
        dfs1(v);
    }

    topsort.push_back(s);
    return;
}
void dfs2(int s){
    
    for(const int &v:graf[s]){
        if(visited[v])continue;
        if(blokady[s][v])continue;
        visited[v]=1;
        dfs2(v);
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    graf.resize(n+9);
    visited.resize(n+9);
    krawedz.resize(m+9);
    blokady.resize(n+9,vector<bool> (n+9,0));

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        krawedz[i]={a,b};
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int wynik=0,nr;
        cin>>nr;
        blokady[krawedz[nr].first][krawedz[nr].second]=1;

        for(int j=1;j<=n;j++){
            if(!visited[j]){
                visited[j]=1;
                dfs1(j);
            }
        }
        visited.clear();
        visited.resize(n+9,0);

        for(int j=topsort.size()-1;j>=0;j--){
            if(!visited[topsort[j]]){
                visited[topsort[j]]=1;
                wynik++;
                dfs2(topsort[j]);
            }
        }
        visited.clear();
        visited.resize(n+9,0);
        topsort.clear();
        

        cout<<wynik<<endl;
    }
    return 0;
}