//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<pair<int,int>> dist;
vector<vector<int>> graf;

void solve(){
    int n,m,d;
    cin>>n>>m;

    graf.clear();
    dist.clear();
    graf.resize(n+1);
    dist.resize(n+1,{0,1e9});

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    queue<int> kolejka;
    cin>>d;
    for(int i=1;i<=d;i++){
        int a;
        cin>>a;
        dist[a]={a,0};
        kolejka.push(a);
    }

    int wynik=1e9;
    while(!kolejka.empty()){
        int punkt=kolejka.front();
        kolejka.pop();

        for(int v:graf[punkt]){
            if(dist[v].second==1e9){
                dist[v].second=dist[punkt].second+1;
                dist[v].first=dist[punkt].first;
                kolejka.push(v);
            }else{
                if(dist[v].first!=dist[punkt].first){
                    wynik=min(wynik,dist[v].second+dist[punkt].second+1);
                }
            }
        }
    }

    if(wynik==1e9){
        cout<<"NIE"<<endl;
    }else{
        cout<<wynik<<endl;
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}