//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> odleglosc;

void bfs(int start)
{
    queue<int> kolejka;
    kolejka.push(start);
    visited[start]=1;
    odleglosc[start]=0;
    
    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();
        for(const int &v:g[s])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                odleglosc[v]=odleglosc[s]+1;
                kolejka.push(v);
            }
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
    visited.resize(n+1);
    odleglosc.resize(n+1,-1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int start=1;
    bfs(start);

    for(int i=1;i<=n;i++)
    {
        cout<<odleglosc[i]<<" ";
    }
    return 0;
}
 