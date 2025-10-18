//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;


long long int wynik=0;
vector<vector<int>> g; 
vector<bool> visited; 
vector<int> topSort;
vector<long long int> czas2;
vector<long long int> czas;

void dfs1(int s)
{
    visited[s]=1;
    for(int v : g[s])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    topSort.push_back(s);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >>n>>m;

    czas.resize(n+9);
    czas2.resize(n+9,0);
    visited.resize(n+9);
    g.resize(n+9);
    for(int i=1;i<=n;i++)
    {
        cin>>czas[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs1(i);
        }
    }

    for(int i=topSort.size()-1;i>=0;i--)
    {

        czas2[topSort[i]]=czas2[topSort[i]]+czas[topSort[i]];
        for(const int &v : g[topSort[i]])
        {
            czas2[v]=max(czas2[v],czas2[topSort[i]]);
        }

        if(g[topSort[i]].size()==0)
        {
            wynik=max(wynik,czas2[topSort[i]]);
        }
    }

    cout<<wynik;

    return 0;
}