#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> visited;
int tab[1000009];
void dfs(int s,int rodzic)
{
    visited[s] = true;
    tab[s]=rodzic;
    for(auto I : g[s])
    {
        if(!visited[I])
            {
            dfs(I,s);
            }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    long long int n,bajtazar;
    cin>>n>>bajtazar;
    g.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(bajtazar,bajtazar);
    int testy;
    cin>>testy;
    for(int i=0;i<testy;i++)
    {
        int a;
        cin>>a;
        cout<<tab[a]<<endl;
    }

    return 0;
}