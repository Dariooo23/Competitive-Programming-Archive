#include <bits/stdc++.h>

using namespace std;

bool visited[1000000]={0};
vector<vector<int>> g;
vector<int> dist;
void bfs(int s) {

    queue<int> cur;
    cur.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!cur.empty()) {
        s = cur.front();
        cur.pop();
        for(auto I : g[s]) {
            if(!visited[I]) {
                cur.push(I);
                visited[I] = true;
                dist[I] = dist[s]+1;
            }
        }
    }
}
int main()
{
    int n,m,wynik=1000000;
    cin>>n>>m;
     int bary;
    cin>>bary;
    g.resize(n+1);
    dist.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int akademik;
    cin>>akademik;

    bfs(akademik);

   /* for(int i=1;i<=n;i++)
    {
        cout<<i<<"."<<dist[i]<<endl;
    }*/
    int minimum=1000000,bar;
    for(int i=0;i<bary;i++)
    {
        cin>>bar;
        if(dist[bar]<minimum&&visited[bar]==1)
        {
            minimum=dist[bar];
            wynik=bar;
        }
        else
        {
            if(minimum==dist[bar])
            {
                wynik=min(wynik,bar);
            }
        }

    }
    cout<<wynik;
    return 0;
}