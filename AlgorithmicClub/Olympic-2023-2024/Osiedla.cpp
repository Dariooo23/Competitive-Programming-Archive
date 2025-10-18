//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int n,m;
vector<vector<pair<int,int>>> graf;
vector<pair<int,int>> polaczenia;
vector<int> skierowanie;
vector<int> visited;

void dfs(int s){
    visited[s]=1;

    for(pair<int,int> v:graf[s]){
        if(skierowanie[v.second]!=0)continue;

        if(visited[v.first]==1){
            if(polaczenia[v.second].first==v.first){
                skierowanie[v.second]=1;
            }else{
                skierowanie[v.second]=2;
            }
        }else{
            if(polaczenia[v.second].first==v.first){
                skierowanie[v.second]=1;
            }else{
                skierowanie[v.second]=2;
            }
            dfs(v.first);
        }
    }

    return;
}

vector<int> nrSCC; 
vector<int> topSort;
vector<int> visited2; 
vector<vector<int>> g;
vector<vector<int>> gT;

void dfs1(int s){
    visited2[s]=1;
    for(int v : g[s]){
        if(visited2[v]==0){
            dfs1(v);
        }
    }
    topSort.push_back(s);
    return;
}

void dfs2(int s, int nr){
    nrSCC[s]=nr;
    for(int v:gT[s]){
        if(nrSCC[v]==-1){
            dfs2(v,nr);
        }
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    graf.resize(n+1);
    visited.resize(n+1,0);
    polaczenia.resize(m+1);
    skierowanie.resize(m+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        polaczenia[i]={a,b};
        graf[a].push_back({b,i});
        graf[b].push_back({a,i});
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==1)continue;
        dfs(i);
    }

    g.resize(n+1);
    gT.resize(n+1);
    nrSCC.resize(n+1,-1);
    visited2.resize(n+1);

    for(int i=1;i<=m;i++){
        if(skierowanie[i]==2){
            g[polaczenia[i].first].push_back(polaczenia[i].second);
            gT[polaczenia[i].second].push_back(polaczenia[i].first);
        }else{
            g[polaczenia[i].second].push_back(polaczenia[i].first);
            gT[polaczenia[i].first].push_back(polaczenia[i].second);
        }
    }

    for(int i=1;i<=n;i++){
        if(visited2[i]==1)continue;
        dfs1(i);
    }

    int nr=1;
    for(int i=1;i<=n;i++){
        int v=topSort.back();
        topSort.pop_back();
        if(nrSCC[v]==-1){
            dfs2(v,nr);
            nr++;
        }
    }

    cout<<nr-1<<endl;
    for(int i=1;i<=m;i++){
        if(skierowanie[i]==2){
            cout<<">";
        }else{
            cout<<"<";
        }
    }
    return 0;
}