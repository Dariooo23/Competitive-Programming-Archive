//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+9;

vector<vector<int>> g(N);
vector<vector<int>> gT(N);
vector<vector<int>> dag(N);
vector<bool> wchodzi(N,0);
vector<int> topSort;
vector<int> nrSCC(N,-1);
vector<bool> visited(N);
vector<int> visited2(N);
vector<int> rozmiar;

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

void dfs2(int s, int nr)
 {
    nrSCC[s]=nr;

    for(int v : gT[s])
    {
        if(nrSCC[v]==-1)
        {
            dfs2(v,nr);
        }
        else
        {
            if(nrSCC[v]!=nr && visited2[nrSCC[v]]<nr)
            {
                wchodzi[nr]=1;
                visited2[nrSCC[v]]=nr;
                dag[nrSCC[v]].push_back(nr);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        gT[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs1(i);
        }
    }

    int nr=0;
    for(int i=1;i<=n;i++)
    {
        int v = topSort.back();
        topSort.pop_back();
        if(nrSCC[v] == -1)
        {
            nr++;
            dfs2(v,nr);
        }

    }

    if(nr==1)
    {
        cout<<0;
        return 0;
    }

    int niewchodzi=0,niewychodzi=0;
    for(int i=1;i<=nr;i++)
    {
        if(wchodzi[i]==0)
        {
            niewchodzi++;
        }
        if(dag[i].size()==0)
        {
            niewychodzi++;
        }
    }

    cout<<max(niewychodzi,niewchodzi);

    return 0;
}