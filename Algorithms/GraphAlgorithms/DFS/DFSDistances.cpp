//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//GRAF
vector<vector<int>> g;
//LISTA ODWIEDZIN
vector<bool> visited;
//ODLEGLOSC OD PUNKTU STARTOWEGO
vector<int> odleglosc;

void dfs(int s,int odl)
{
        odleglosc[s]=odl;
        for(const int &v:g[s])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                dfs(v,odl+1);
            }
        }
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
    odleglosc.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //ODPALENIE DFS
    int start=1;
    visited[start]=1;
    odleglosc[start]=0;
    dfs(start,0);

    for(int i=1;i<=n;i++)
    {
        cout<<"WIERZCHOLEK NR "<<i<<" JEST ODLEGLY OD PUNKTU "<<start<<" O TYLE: "<<odleglosc[i]<<'\n';
    }
    return 0;
}
 