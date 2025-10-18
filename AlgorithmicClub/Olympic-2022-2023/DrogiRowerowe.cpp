#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<vector<int>> g(N);
vector<vector<int>> gT(N);
vector<vector<int>> dag(N);
vector<int> topSort;
vector<int> nrSCC(N,-1);
vector<bool> visited(N);
vector<int> rozmiar;
vector<int> wynik;
int ilosc;


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
    ilosc++;
    nrSCC[s]=nr;
    for(int v : gT[s])
    {
        if(nrSCC[v]==-1)
        {
            dfs2(v,nr);
        }
        else
        {
            if(nrSCC[v]<nr)
            {
                dag[nrSCC[v]].push_back(nr);
            }
        }
    }
}

int oblicz(int s)
{
    if(dag[s].size()==0)
    {
        wynik[s]=rozmiar[s-1];
        return rozmiar[s-1];
    }
    else
    {
        if(wynik[s]!=0)
        {
            return wynik[s];
        }
        else
        {
            wynik[s]=rozmiar[s-1];
            for(int v:dag[s])
            {
                wynik[s]=wynik[s]+oblicz(v);
            }
            return wynik[s];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
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
        ilosc=0;
        int v = topSort.back();
        topSort.pop_back();
        if(nrSCC[v] == -1)
        {
            nr++;
            dfs2(v,nr);
            rozmiar.push_back(ilosc);
        }

    }

    wynik.resize(nr+9);
    for(int i=1;i<=nr;i++)
    {
        if(wynik[i]==0)
        {
            oblicz(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<wynik[nrSCC[i]]-1<<endl;
    }
    return 0;
}