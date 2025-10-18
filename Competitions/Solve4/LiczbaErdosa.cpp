//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> odleglosc;
vector<int> visited;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,e;
    cin>>n>>m>>e;

    graf.resize(n+1);
    visited.resize(n+1);
    odleglosc.resize(n+1,-1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    odleglosc[e]=0;
    visited[e]=1;

    queue<int> kolejka;
    kolejka.push(e);

    while(!kolejka.empty()){
        int punkt=kolejka.front();
        kolejka.pop();

        for(int v:graf[punkt]){
            if(visited[v])continue;

            visited[v]=1;
            kolejka.push(v);
            odleglosc[v]=odleglosc[punkt]+1;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<odleglosc[i]<<'\n';
    }
    return 0;
}