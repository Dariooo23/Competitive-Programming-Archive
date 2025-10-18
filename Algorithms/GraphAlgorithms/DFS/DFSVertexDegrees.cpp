//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//GRAF
vector<vector<int>> g;
//LISTA ODWIEDZIN
vector<bool> visited;
//ILOSC DZIECI
vector<int> stopnie;

void dfs(int s)
{
    for(const int &v:g[s])
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            dfs(v);
        }
    }
    stopnie[s]=g[s].size();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DRZEWA
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.resize(n+1);
    stopnie.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //ODPALENIE DFS
    visited[1]=1;
    dfs(1);

    for(int i=1;i<=n;i++)
    {
        cout<<"WIERZCHOLEK NR "<<i<<" MA STOPIEN "<<stopnie[i]<<'\n';
    }
    return 0;
}
 