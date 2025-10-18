#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &G,int start_v,int nr, vector<int> &ss)
{
    queue<int> Q;
    ss[start_v]=nr;
    Q.push(start_v);
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        for(int w:G[v])
        {
            if(ss[w]==0)
            {
                ss[w]=nr;
                Q.push(w);
            }
        }
    }

}


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int nr=0;
    vector<int> ss(n+1);
    for(int v=1;v<=n;v++)
    {
        if (ss[v]==0)
        {
            nr++;
            bfs(G,v,nr,ss);
        }
    }

    int result =0;
    vector<int> cnt(nr+1);
    for(int v=1;v<=n;v++)
    {
        cnt[ss[v]]++;
        result=max(result,cnt[ss[v]]);
    }
    cout<<result<<endl;

}


int main()
{
    std::ios_base::sync_with_stdio(0);
    solve();

    return 0;
}