//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> wagi;
vector<int> sciezki;
vector<bool> visited;
vector<int> preorder;
vector<int> postorder;
vector<int> glebokosc;
vector<vector<int>> g;
vector<pair<int,int>> reakcje;
vector<vector<int>> przodkowie;
vector<vector<int>> etapy_reakcji;

long long int wynik=0;
int n,m,k,nr_pre=1,nr_post=1;

void dfs(int s){
    
    visited[s]=1;
    
            for(const int &v:g[s]){
                if(!visited[v]){
                    dfs(v);
            }
        }  
    
    for(int i=0;i<etapy_reakcji[s].size();i++){
        long long int osad=min(wagi[reakcje[etapy_reakcji[s][i]].first],wagi[reakcje[etapy_reakcji[s][i]].second]);
        wynik=wynik+osad*2;
        
        wagi[reakcje[etapy_reakcji[s][i]].first]=wagi[reakcje[etapy_reakcji[s][i]].first]-osad;
        wagi[reakcje[etapy_reakcji[s][i]].second]=wagi[reakcje[etapy_reakcji[s][i]].second]-osad;
    }
}

void ojcowie(int s,int p){

    visited[s]=1;
    przodkowie[s][0]=p;
    glebokosc[s]=glebokosc[p]+1;

    preorder[s]=nr_pre;
    nr_pre++;

    for(const int &v:g[s]){
        if(visited[v]!=1){
            ojcowie(v,s);
        }
    }

    postorder[s]=nr_post;
    nr_post++;
}

void stworz_przodkow(int n){
    for(int k=1;k<=21;++k){
        for(int x=1;x<=n;++x){
            przodkowie[x][k]=przodkowie[przodkowie[x][k-1]][k-1];
        }
    }
}

bool czy_potomek(int a,int b){
    return (preorder[a]>=preorder[b] && postorder[a]<=postorder[b]);
}

int lca(int a,int b){
    if(glebokosc[a]>glebokosc[b]){
        swap(a,b);
    }

    for(int k=21;k>=0;--k){
        if(glebokosc[przodkowie[b][k]]>=glebokosc[a]){
            b=przodkowie[b][k];
        }
    }
    if(a==b){
        return a;
    }

    for(int k=21;k>=0;--k){
        if(przodkowie[a][k]!=przodkowie[b][k]){
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }

    return przodkowie[a][0];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m>>k;

    g.resize(n+m+100000);
    wagi.resize(n+m+100000);
    sciezki.resize(n+m+100000);
    reakcje.resize(n+m+100000);
    preorder.resize(n+m+100000);
    postorder.resize(n+m+100000);
    glebokosc.resize(n+m+100000);
    visited.resize(n+m+100000,0);
    etapy_reakcji.resize(n+m+100000);
    przodkowie.resize(n+m+100000,vector<int> (22));

    for(int i=1;i<=n;i++){
        cin>>wagi[i];
        sciezki[i]=i;
    }

    int punkt=n+1,punkt2;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        punkt2=b;
        a=sciezki[a];
        b=sciezki[b];

        g[a].push_back(punkt);
        g[b].push_back(punkt); 
        g[punkt].push_back(a);
        g[punkt].push_back(b);

        sciezki[punkt2]=punkt;
        punkt++;
    }

    for(int i=n+m;i>=1;i--){
        if(!visited[i]){
            ojcowie(i,i);
        }
    }
    stworz_przodkow(n+m);

    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        reakcje[i].first=a;
        reakcje[i].second=b;
        if(przodkowie[a][21]==przodkowie[b][21]){
            etapy_reakcji[lca(a,b)].push_back(i);
        }
    }

    visited.clear();
    visited.resize(n+m+100000,0);
    for(int i=n+m;i>=1;i--){
        if(!visited[i]){
            dfs(i);
        }
    }

    cout<<wynik;

    return 0;
}