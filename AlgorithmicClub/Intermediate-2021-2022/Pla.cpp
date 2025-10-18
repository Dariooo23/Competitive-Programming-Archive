//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int rozmiar=0,maks_rozmiar=0;

void dfs(int s)
{
    for(const int &v : g[s])
    {
        if(!visited[v])
        {
            rozmiar++;
            visited[v]=1;
            dfs(v);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    visited.resize(n+1,0);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        rozmiar=1;
        if(!visited[i])
        {
            visited[i]=1;
            dfs(i);
            maks_rozmiar=max(maks_rozmiar,rozmiar);
        }
    }

    cout<<maks_rozmiar;
    return 0;
}
 