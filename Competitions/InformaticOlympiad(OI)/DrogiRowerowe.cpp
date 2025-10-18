//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<int> wyniki;
vector<int> scc_nr;
vector<int> visited;
vector<int> top_sort;
vector<int> scc_rozmiar;
vector<vector<int>> graf;
vector<vector<int>> graf_scc;
vector<vector<int>> graf_odwr;

void dfs(int s){
    visited[s]=1;
    for(const int &v:graf[s]){
        if(visited[v])continue;
        dfs(v);
    }

    top_sort.push_back(s);
    return;
}
void dfs_scc(int s,int nr){
    if(scc_nr[s]==-1){
        scc_nr[s]=nr;
    }
    for(const int &v:graf_odwr[s]){
        if(scc_nr[v]==-1){
            scc_nr[v]=nr;
            dfs_scc(v,nr);
        }else{
            if(scc_nr[v]<nr){
                graf_scc[scc_nr[v]].push_back(nr);
            }
        }
    }
}
int oblicz(int s){
    if(wyniki[s]!=0)return wyniki[s];

    int wynik=scc_rozmiar[s];
    for(const int &v:graf_scc[s]){
        wynik+=oblicz(v);
    }

    wyniki[s]=wynik;
    return wynik;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    graf.resize(n+1);
    visited.resize(n+1);
    graf_odwr.resize(n+1);
    scc_nr.resize(n+1,-1);
    graf_scc.resize(100000);
    scc_rozmiar.resize(100000,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf_odwr[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i);
    }

    int nr=1;
    for(int i=top_sort.size()-1;i>=0;i--){
        if(scc_nr[top_sort[i]]!=-1)continue;
        dfs_scc(top_sort[i],nr);
        nr++;
    }
    for(int i=1;i<=n;i++){
        scc_rozmiar[scc_nr[i]]++;
    }

    wyniki.resize(nr+9);
    for(int i=1;i<nr;i++){
        if(wyniki[i]==0){
            wyniki[i]=oblicz(i);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<wyniki[scc_nr[i]]-1<<endl;
    }

    return 0;
}