//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> odleglosc;
vector<bool> visited;
vector<int> rodzice;
pair<int,int> krawedz;

void dfs(int s,int p)
{
    visited[s]=1;
    for(const int &v:g[s])
    {
        if(v==p)continue;
        if(visited[v]){
            krawedz={s,v};
            continue;
        }
        
        dfs(v,s);
    }
    return;
}
void bfs(int start,pair<int,int> krawedz)
{
    queue<int> kolejka;
    kolejka.push(start);
    odleglosc[start]=0;
    visited[start]=1;
    
    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();
        for(const int &v:g[s])
        {
            if(visited[v])continue;
            if(v==krawedz.second && s==krawedz.first)continue;
            
            visited[v]=1;
            rodzice[v]=s;
            odleglosc[v]=odleglosc[s]+1;
            kolejka.push(v);
            
        }
    }

}
void solve()
{
    int n,m;
    cin>>n>>m;
    
    g.clear();
    g.resize(n+1);
    visited.clear();
    visited.resize(n+1,0);
    rodzice.clear();
    rodzice.resize(n+1,-1);
    odleglosc.clear();
    odleglosc.resize(n+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    krawedz={0,0};
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i,0);
        }
    }

    if(krawedz.first==0)
    {
        cout<<"NIE"<<endl;
        return;
    }

    rodzice[krawedz.first]=0;
    odleglosc[krawedz.first]=0;
    for(int i=1;i<=n;i++)visited[i]=0;
    bfs(krawedz.first,krawedz);

    cout<<"TAK"<<endl;
    cout<<odleglosc[krawedz.second]+1<<endl;
    int indeks=krawedz.second;
    while(rodzice[indeks]!=0)
    {
        cout<<indeks<<" ";
        indeks=rodzice[indeks];
    }
    cout<<indeks<<endl;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int testy;
    cin>>testy;
    while(testy--)
    {
        solve();
    }
    return 0;
}
 