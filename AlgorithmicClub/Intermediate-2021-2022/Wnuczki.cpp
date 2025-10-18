//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> wynik;
int dfs(int s)
{
    int dzieci=g[s].size();

    for(const int &v : g[s])
    {
        if(!visited[v])
        {
           visited[v]=1;
           wynik[s]=wynik[s]+dfs(v);
        }
    }

    return dzieci;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    g.resize(n+1);
    wynik.resize(n+1,0);
    visited.resize(n+1,0);

    for(int i=1;i<n;i++)
    {
        int a;
        cin>>a;
        g[a].push_back(i+1);
    }

    visited[1]=1;
    dfs(1);

    for(int i=1;i<=n;i++)
    {
        cout<<wynik[i]<<" ";
    }

    return 0;
}
 