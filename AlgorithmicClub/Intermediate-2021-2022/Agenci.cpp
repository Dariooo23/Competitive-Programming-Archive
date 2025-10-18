//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int wynik=0;
const int N=1e4;

vector<int> topSort;
vector<int> nrSCC(N,-1);
vector<bool> visited(N);
vector<int> visited2(N);
vector<vector<int>> g(N);
vector<bool> wchodzi(N,0);
vector<vector<int>> gT(N);
vector<int> koszt_sss(N,1e9+9);
vector<int> przekupni_agenci(N,1e9+9);

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
    koszt_sss[nr]=min(przekupni_agenci[s],koszt_sss[nr]);

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
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ilosc_agentow,ilosc_przekupnych_agentow,agent,koszt;
    cin>>ilosc_agentow>>ilosc_przekupnych_agentow;

    for(int i=1;i<=ilosc_przekupnych_agentow;i++)
    {
        cin>>agent>>koszt;
        przekupni_agenci[agent]=koszt;
    }

    int polaczenia,agent1,agent2;
    cin>>polaczenia;

    for(int i=1;i<=polaczenia;i++)
    {
        cin>>agent1>>agent2;
        g[agent1].push_back(agent2);
        gT[agent2].push_back(agent1);
    }

    for(int i=1;i<=ilosc_agentow;i++)
    {
        if(visited[i]==0)
        {
            dfs1(i);
        }
    }

    int nr=1;
    for(int i=1;i<=ilosc_agentow;i++)
    {
        int v = topSort.back();
        topSort.pop_back();
        if(nrSCC[v] == -1)
        {
            dfs2(v,nr);
            nr++;
        }
    }

    for(int i=1;i<nr;i++)
    {
        if(!wchodzi[i])
        {
            if(koszt_sss[i]!=1e9+9)
            {
                wynik=wynik+koszt_sss[i];
            }
            else
            {
                cout<<"NIE"<<endl;
                for(int j=1;j<=ilosc_agentow;j++)
                {
                    if(nrSCC[j]==i)
                    {
                        cout<<j;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"TAK"<<endl;
    cout<<wynik;


    return 0;
}