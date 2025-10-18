//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

//BFS
vector<vector<int>> visited;
vector<vector<char>> plansza;
vector<vector<int>> odleglosc;

//MST DFS
vector<vector<pair<int,int>>> graf;
vector<pair<int,pair<int,int>>> krawedzie;

//FAU
vector<int> rangi;
vector<int> rodzice;

//LCA
vector<int> glebokosc;
vector<vector<pair<int,int>>> przodkowie;

bool cmp(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
    if(a.first==b.first){
        if(a.second.first==b.second.first){
            return a.second.second<b.second.second;
        }else{
            return a.second.first<b.second.first;
        }
    }else{
        return a.first>b.first;
    }
}
int find(int x){
    if(rodzice[x]!=x){
        rodzice[x]=find(rodzice[x]);
    }
    return rodzice[x];
}
void uni(int x,int y){
    x=find(x);
    y=find(y);

    if(x==y)return;

    if(rangi[x]>rangi[y])swap(x,y);
    rodzice[x]=y;
    if(rangi[x]==rangi[y])rangi[y]++;
    return;
}

void dfs(int s,int p,int waga){
    przodkowie[s][0]={p,waga};
    glebokosc[s]=glebokosc[p]+1;

    for(pair<int,int> v:graf[s]){
        if(v.first==p)continue;
        dfs(v.first,s,v.second);
    }

    return;
}

void stworz_przodkow(int n){
    for(int k=1;k<=24;++k){
        for(int x=1;x<=n;++x){
            przodkowie[x][k].first=przodkowie[przodkowie[x][k-1].first][k-1].first;
            przodkowie[x][k].second=min(przodkowie[przodkowie[x][k-1].first][k-1].second,przodkowie[x][k-1].second);
        }
    }
    return;
}

int lca(int a,int b){
    int wynik=1e9;

    if(glebokosc[a]>glebokosc[b]){
        swap(a,b);
    }

    for(int k=24;k>=0;--k){
        if(glebokosc[przodkowie[b][k].first]>=glebokosc[a]){
            wynik=min(wynik,przodkowie[b][k].second);
            b=przodkowie[b][k].first;
        }
    }

    if(a==b){
        return wynik;
    }

    for(int k=24;k>=0;--k){
        if(przodkowie[a][k].first!=przodkowie[b][k].first){
            wynik=min(wynik,przodkowie[a][k].second);
            wynik=min(wynik,przodkowie[b][k].second);
            a=przodkowie[a][k].first;
            b=przodkowie[b][k].first;
        }
    }

    wynik=min({wynik,przodkowie[a][0].second,przodkowie[b][0].second});
    return wynik;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    visited.resize(n+10,vector<int> (n+10,0));
    odleglosc.resize(n+10,vector<int> (n+10,0));
    plansza.resize(n+10,vector<char>(n+10,'#'));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char znak;
            cin>>znak;
            plansza[i][j]=znak;
        }
    }

    queue<pair<int,int>> kolejka;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(plansza[i][j]=='#'){
                visited[i][j]=1;
                odleglosc[i][j]=0;
                kolejka.push({i,j});
            }
        }
    }

    while(!kolejka.empty()){
        pair<int,int> punkt=kolejka.front();
        kolejka.pop();

        //Gora
        if(punkt.first!=0){
            if(visited[punkt.first-1][punkt.second]==0){
                visited[punkt.first-1][punkt.second]=1;
                odleglosc[punkt.first-1][punkt.second]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-1,punkt.second});
            }
        }
        //Dol
        if(punkt.first!=n+1){
            if(visited[punkt.first+1][punkt.second]==0){
                visited[punkt.first+1][punkt.second]=1;
                odleglosc[punkt.first+1][punkt.second]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+1,punkt.second});
            }
        }
        //Lewo
        if(punkt.second!=0){
            if(visited[punkt.first][punkt.second-1]==0){
                visited[punkt.first][punkt.second-1]=1;
                odleglosc[punkt.first][punkt.second-1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first,punkt.second-1});
            }
        }
        //Prawo
        if(punkt.second!=n+1){
            if(visited[punkt.first][punkt.second+1]==0){
                visited[punkt.first][punkt.second+1]=1;
                odleglosc[punkt.first][punkt.second+1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first,punkt.second+1});
            }
        }
        //Lewy Gorny
        if(punkt.first!=0 && punkt.second!=0){
            if(visited[punkt.first-1][punkt.second-1]==0){
                visited[punkt.first-1][punkt.second-1]=1;
                odleglosc[punkt.first-1][punkt.second-1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-1,punkt.second-1});
            }
        }
        //Lewy Dolny
        if(punkt.first!=n+1 && punkt.second!=0){
            if(visited[punkt.first+1][punkt.second-1]==0){
                visited[punkt.first+1][punkt.second-1]=1;
                odleglosc[punkt.first+1][punkt.second-1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+1,punkt.second-1});
            }
        }
        //Prawy Gorny
        if(punkt.first!=0 && punkt.second!=n+1){
            if(visited[punkt.first-1][punkt.second+1]==0){
                visited[punkt.first-1][punkt.second+1]=1;
                odleglosc[punkt.first-1][punkt.second+1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-1,punkt.second+1});
            }
        }
        //Prawy Dolny
        if(punkt.first!=n+1 && punkt.second!=n+1){
            if(visited[punkt.first+1][punkt.second+1]==0){
                visited[punkt.first+1][punkt.second+1]=1;
                odleglosc[punkt.first+1][punkt.second+1]=odleglosc[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+1,punkt.second+1});
            }
        }
    }

    /*for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            cout<<odleglosc[i][j]<<" ";
        }cout<<endl;
    }*/

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(j!=n+1){
                krawedzie.push_back({min(odleglosc[i][j],odleglosc[i][j+1]),{i*(n+2)+j,i*(n+2)+j+1}});
            }
            if(i!=n+1){
                krawedzie.push_back({min(odleglosc[i][j],odleglosc[i+1][j]),{i*(n+2)+j,(i+1)*(n+2)+j}});
            }
        }
    }

    sort(krawedzie.begin(),krawedzie.end(),cmp);

    graf.resize((n+2)*(n+2)+10);
    rangi.resize((n+2)*(n+2)+10);
    rodzice.resize((n+2)*(n+2)+10);

    for(int i=0;i<=(n+2)*(n+2)+9;i++){
        rodzice[i]=i;
        rangi[i]=1;
    }

    for(int i=0;i<krawedzie.size();i++){
        if(find(krawedzie[i].second.first)!=find(krawedzie[i].second.second)){
            uni(krawedzie[i].second.first,krawedzie[i].second.second);
            graf[krawedzie[i].second.first].push_back({krawedzie[i].second.second,krawedzie[i].first});
            graf[krawedzie[i].second.second].push_back({krawedzie[i].second.first,krawedzie[i].first});
        }
    }

    glebokosc.resize((n+2)*(n+2)+10);
    przodkowie.resize((n+2)*(n+2)+10,vector<pair<int,int>> (25));

    dfs(0,0,0);
    stworz_przodkow((n+2)*(n+2)+9);

    int q;
    cin>>q;
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        int punkt1=r1*(n+2)+c1;
        int punkt2=r2*(n+2)+c2;
        cout<<max(0,2*lca(punkt1,punkt2)-1)<<endl;
    }
    return 0;
}