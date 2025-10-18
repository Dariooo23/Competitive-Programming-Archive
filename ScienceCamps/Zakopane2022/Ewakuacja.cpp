//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//GRAF
vector<vector<int>> g;
//LISTA ODWIEDZIN
vector<bool> visited;
//ODLEGLOSC OD PUNKTU STARTOWEGO
vector<int> odleglosc;

queue<int> kolejka;

void bfs()
{
    
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

    //WCZYTANIE DRZEWA
    int n;
    cin>>n;

    if(n==1)
    {
        cout<<1;
        exit(0);
    }

    g.resize(n+1);
    visited.resize(n+1);
    odleglosc.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1)
        {
            kolejka.push(i);
            visited[i]=1;
            odleglosc[i]=1;
        }
    }

    bfs();

    for(int i=1;i<=n;i++)
    {
        cout<<odleglosc[i]<<" ";
    }
    return 0;
}
 