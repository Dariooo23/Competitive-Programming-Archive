//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> visited;
vector<int> kolory;

void dfs(int s,int p){
    visited[s]=1;
    if(kolory[p]==0){
        kolory[s]=1;
    }else{
        kolory[s]=0;
    }
    for(int v:graf[s]){
        if(kolory[v]==kolory[s]){
            cout<<"NIE";
            exit(0);
        }
        if(visited[v])continue;
        dfs(v,s);
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

    graf.resize(n+1);
    visited.resize(n+1);
    kolory.resize(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    kolory[0]=0;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i,0);
    }

    cout<<"TAK";
    return 0;
}