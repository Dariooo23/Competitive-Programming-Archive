//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>g;
vector<bool>straznicy;
vector<set<int>>punkt_sciezki;

void dfs(int s,int p){
    if(straznicy[s]==1)punkt_sciezki[s].clear();
    for(auto v:g[s]){
        if(v==p)continue;
        dfs(v,s);
    }

    if(straznicy[p]!=1){
        if(punkt_sciezki[p].size()<punkt_sciezki[s].size()){
            swap(punkt_sciezki[p],punkt_sciezki[s]);
        }
        for(auto v:punkt_sciezki[s]){
            if(punkt_sciezki[p].find(v)==punkt_sciezki[p].end()){
                punkt_sciezki[p].insert(v);
            }else{
                straznicy[p]=1;
                punkt_sciezki[p].clear();
                return;
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    straznicy.resize(n+1);
    punkt_sciezki.resize(n+1);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        punkt_sciezki[a].insert(i);
        punkt_sciezki[b].insert(i);
        if(a==b){
            straznicy[a]=1;
            punkt_sciezki[a].clear();
        }
    }

    dfs(1,0);
    int wynik=0;
    for(int i=1;i<=n;i++){
        if(straznicy[i]==1)wynik++;
    }

    cout<<wynik<<endl;
    for(int i=1;i<=n;i++){
        if(straznicy[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}