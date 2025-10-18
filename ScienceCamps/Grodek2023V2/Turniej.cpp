//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> gT;
vector<vector<int>> dag; 
vector<int> topSort;
vector<int> nrSCC;
vector<bool> visited; 
vector<int> visited2; 

void dfs1(int s){
    visited[s]=1;
    for(int v : g[s]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    topSort.push_back(s);
    return;
}

void dfs2(int s, int nr){
    nrSCC[s]=nr;
    for(int v : gT[s]){
        if(nrSCC[v]==-1){
            dfs2(v,nr);
        }else{
            if(nrSCC[v]!=nr && visited2[nrSCC[v]]<nr){
                visited2[nrSCC[v]]=nr;
                dag[nrSCC[v]].push_back(nr);
            }
        }
    }
    return;
}

void dfs_czylinia(int s,int p){
    visited[s]=1;
    for(int v:dag[s]){
        if(v!=s+1)continue;
        dfs_czylinia(v,s);
    }
    return;
}
void topsort_dag(int s){
    visited[s]=1;
    for(int v : dag[s]){
        if(!visited[v]){
            topsort_dag(v);
        }
    }
    topSort.push_back(s);
    return;
}

void solve(){
    int n,m,a,b;
    cin >>n>>m;

    g.resize(n+1);
    gT.resize(n+1);
    dag.resize(n+1);
    nrSCC.resize(n+1,-1);
    visited.resize(n+1,0);
    visited2.resize(n+1,0);

    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        gT[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs1(i);
        }
    }

    int nr=0;
    for(int i=1;i<=n;i++){
        int v=topSort.back();
        topSort.pop_back();
        if(nrSCC[v]==-1){
            nr++;
            dfs2(v,nr);
        }

    }

    topSort.clear();
    visited.clear();
    visited.resize(n+1,0);
    for(int i=1;i<=nr;i++){
        if(visited[i]==0){
            topsort_dag(i);
        }
    }
    visited.clear();
    visited.resize(n+1,0);
    

    dfs_czylinia(topSort[topSort.size()-1],-1);
    int flaga=1;
    for(int i=1;i<=nr;i++){
        if(visited[i]==0)flaga=0;
    }

    if(flaga==1){
        cout<<"TAK"<<'\n';
    }else{
        cout<<"NIE"<<'\n';
    }
    
    g.clear();
    gT.clear();
    dag.clear();
    nrSCC.clear();
    visited.clear();
    visited2.clear();
    return;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }

    return 0;
}