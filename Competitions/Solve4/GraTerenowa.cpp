//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<vector<int>> g;
vector<bool> visited;

int dfs(int w){
    visited[w]=1;
    for(int v:g[w]){
        if(visited[v])continue;
        return dfs(v)+1;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> tab(n,vector<char>(m));
    vector<vector<int>> nr(n,vector<int>(m));

    g.resize(n*m+1);
    visited.resize(n*m+1);

    int akt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tab[i][j];
        }
    }
    int wynik=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tab[i][j]=='O'){
                if(i-1>=0 && tab[i-1][j]=='?')tab[i-1][j]='#';
                if(i+1<n && tab[i+1][j]=='?')tab[i+1][j]='#';
                if(j-1>=0 && tab[i][j-1]=='?')tab[i][j-1]='#';
                if(j+1<m && tab[i][j+1]=='?')tab[i][j+1]='#';
                if(i-1>=0 && j-1>=0 && tab[i-1][j-1]=='?')tab[i-1][j-1]='#';
                if(i+1<n && j-1>=0 && tab[i+1][j-1]=='?')tab[i+1][j-1]='#';
                if(i-1>=0 && j+1<m && tab[i-1][j+1]=='?')tab[i-1][j+1]='#';
                if(i+1<n && j+1<m && tab[i+1][j+1]=='?')tab[i+1][j+1]='#';
                bool flag=true;
                if(i-1>=0 && tab[i-1][j]=='O')flag=0;
                if(i+1<n && tab[i+1][j]=='O')flag=0;
                if(j-1>=0 && tab[i][j-1]=='O')flag=0;
                if(j+1<m && tab[i][j+1]=='O')flag=0;
                if(i-1>=0 && j-1>=0 && tab[i-1][j-1]=='O')flag=0;
                if(i+1<n && j-1>=0 && tab[i+1][j-1]=='O')flag=0;
                if(i-1>=0 && j+1<m && tab[i-1][j+1]=='O')flag=0;
                if(i+1<n && j+1<m && tab[i+1][j+1]=='O')flag=0;
                if(flag)wynik++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tab[i][j]=='?'){
                nr[i][j]=akt;
                akt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tab[i][j]=='?'){
                int w=nr[i][j];
                if(i-1>=0 && tab[i-1][j]=='?')g[w].push_back(nr[i-1][j]);
                if(i+1<n && tab[i+1][j]=='?')g[w].push_back(nr[i+1][j]);
                if(j-1>=0 && tab[i][j-1]=='?')g[w].push_back(nr[i][j-1]);
                if(j+1<m && tab[i][j+1]=='?')g[w].push_back(nr[i][j+1]);
                if(i-1>=0 && j-1>=0 && tab[i-1][j-1]=='?')g[w].push_back(nr[i-1][j-1]);
                if(i+1<n && j-1>=0 && tab[i+1][j-1]=='?')g[w].push_back(nr[i+1][j-1]);
                if(i-1>=0 && j+1<m && tab[i-1][j+1]=='?')g[w].push_back(nr[i-1][j+1]);
                if(i+1<n && j+1<m && tab[i+1][j+1]=='?')g[w].push_back(nr[i+1][j+1]);
            }
        }
    }

    
    for(int i=0;i<akt;i++){
        if(g[i].size()!=0)continue;
        wynik++;
    }
    for(int i=0;i<akt;i++){
        if(g[i].size()!=1)continue;
        if(visited[i])continue;
        int dl=dfs(i);

        wynik=wynik+(dl+1)/2;
    }
    for(int i=0;i<akt;i++){
        if(g[i].size()!=2)continue;
        if(visited[i])continue;
        int dl=dfs(i);

        wynik=wynik+dl/2;
    }

    cout<<wynik<<endl;
    return 0;
}