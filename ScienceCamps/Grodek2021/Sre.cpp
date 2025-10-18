#include <bits/stdc++.h>

using namespace std;

int maksimum=0;
bool visited[1000000];
vector<vector<int>> g;
int dist[1000000];
void bfs(int s) {

    queue<int> cur;
    cur.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!cur.empty())
    {
        s = cur.front();
        cur.pop();
        for(auto I : g[s])
        {
            if(!visited[I])
            {
                cur.push(I);
                visited[I]=true;
                dist[I]=dist[s]+1;
            }
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n;
    m=n-1;
    g.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            bfs(i);
            maksimum=max(maksimum,dist[j]);
        }
        for(int j=1;j<=n;j++)
        {
            visited[j]=0;
            dist[j]=0;
        }
    }
    cout<<maksimum;
    return 0;
}