#include <bits/stdc++.h>

using namespace std;
const int N=1e6+9;

vector<vector<int>> g(N);
vector<int> topSort;
vector<bool> visited(N);

void dfs1(int s)
{
    visited[s]=true;
    for(int v:g[s])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    topSort.push_back(s);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
    for(int i=topSort.size()-1;i>=0;i--)
    {
        cout<<topSort[i]<<" ";
    }
    return 0;
}