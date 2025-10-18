//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> odleglosci;
vector<bool> visited;
vector<int> cykle;
set<int, greater<int>> s;

void dfs(int s,int p)
{
    for(const pair<int,int> &v : g[s])
    {
        if(v.first!=p)
        {
            if(visited[v.first]==0)
            {
                visited[v.first]=1;
                odleglosci[v.first]=(odleglosci[s]^v.second);
                dfs(v.first,s);
            }
            else
            {
                cykle.push_back((odleglosci[v.first]^odleglosci[s]^v.second));
            }
        }
    }
}

void wstaw(int v)
{
    for(auto it=s.begin();it!=s.end();++it)
    {
        if((v^(*it))<v)
        {
            v=(v^(*it));
        }
    }
    if(v!=0)
    {
        s.insert(v);
    }
}

int popraw(int v)
{
    for(auto it=s.begin();it!=s.end();++it)
    {
        if((v^(*it))<v)
        {
            v=(v^(*it));
        }
    }
    return v;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    odleglosci.resize(n+1);
    visited.resize(n+1);
    g.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(make_pair(b,c));
        g[b].emplace_back(make_pair(a,c));
    }

    visited[1]=1;
    odleglosci[1]=0;
    dfs(1,0);

    for(int v : cykle)
    {
        wstaw(v);
    }

    for(int i=1;i<=n;i++)
    {
        odleglosci[i]=popraw(odleglosci[i]);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<odleglosci[i]<<" ";
    }

    return 0;
}
 