//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//Dane wejsciowe
int n,m,q;

//Tablice do zapytan
vector<pair<int,int>> zapytania;
vector<int> wyniki;

//Tablice do BFS
vector<vector<int>> g;
vector<bool> visited;
vector<int> odleglosc;

void bfs(int start)
{
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }

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

    for(int i=1;i<=q;i++)
    {
        wyniki[i]=min(wyniki[i],odleglosc[zapytania[i].first]+odleglosc[zapytania[i].second]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m>>q;

    g.resize(n+1);
    visited.resize(n+1);
    wyniki.resize(q+1,1e9);
    odleglosc.resize(n+1);
    zapytania.resize(q+1);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        zapytania[i]={a,b};
    }

    for(int i=1;i<=200;i++)
    {
        int punkt_startowy=rand()%(n+1);
        bfs(punkt_startowy);
    }

    for(int i=1;i<=q;i++)
    {
        cout<<wyniki[i]<<endl;
    }
    return 0;
}
 