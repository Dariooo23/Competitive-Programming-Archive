//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m,q;
int numer_skladowej;
vector<int> topsort;
vector<bool> visited;
vector<int> visited2;
vector<vector<int>> graf;
vector<vector<int>> grafT;
vector<pair<int,int>> krawedzie;

void dfs1(int v){
    visited[v]=1;

    for(int u : graf[v]){
        if(visited[u])continue;
        dfs1(u);
    }

    topsort.push_back(v);
    return;
}

void dfs2(int v){
    visited2[v]=numer_skladowej;
    
    for(int u : grafT[v]){
        if(visited2[u]!=0)continue;
        dfs2(u);
    }

    return;
}

bool rozwiaz_2SAT(){
    topsort.clear();
    for(int i=0;i<(n+1)*2;i++){
        visited[i]=0;
        visited2[i]=0;
    }
    
    for(int i=0;i<(n+1)*2;i++){
        if(visited[i])continue;
        dfs1(i);
    }

    numer_skladowej=1;
    for(int i=topsort.size()-1;i>=0;i--){
        if(visited2[topsort[i]]!=0)continue;
        dfs2(topsort[i]);
        numer_skladowej++;
    }

    for(int i=0;i<(n+1)*2;i=i+2){
        if(visited2[i]==visited2[i+1]){
            return false;
        }
    }


    return true;
}

void dodaj_krawedz(int zmienna1, bool wartosc1,int zmienna2, bool wartosc2){
    zmienna1=2*zmienna1^wartosc1;
    zmienna2=2*zmienna2^wartosc2;
    graf[(zmienna1^1)].push_back(zmienna2);
    graf[(zmienna2^1)].push_back(zmienna1);
    grafT[zmienna2].push_back((zmienna1^1));
    grafT[zmienna1].push_back((zmienna2^1));
    return;
}

bool solve(int k){
    for(int i=0;i<(n+1)*2;i++){
        graf[i].clear();
        grafT[i].clear();
    }

    for(int i=0;i<m;i++){
        dodaj_krawedz(krawedzie[i].first,0,krawedzie[i].second,0);
        if(abs(krawedzie[i].first-krawedzie[i].second)<=k){
            dodaj_krawedz(krawedzie[i].first,1,krawedzie[i].second,1);
        }
    }

    return rozwiaz_2SAT();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m>>q;

    graf.resize((n+1)*2);
    grafT.resize((n+1)*2);
    visited.resize((n+1)*2,0);
    visited2.resize((n+1)*2,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        krawedzie.push_back({a,b});
    }
    int l=0,r=n+1,mid;
    while(l<r){
        mid=(l+r+1)/2;
        if(solve(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    while(q--){
        int a;
        cin>>a;
        if(a<=l){
            cout<<"TAK"<<'\n';
        }else{
            cout<<"NIE"<<'\n';
        }
    }
    return 0;
}