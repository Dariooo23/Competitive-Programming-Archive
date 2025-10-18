//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<int> topsort;
vector<int> licznik;
vector<int> visited;
vector<vector<int>> graf;
vector<vector<int>> nowy_graf;

void wywala(){
    cout<<"NIE";
    exit(0);
    return;
}
void czy_spojny(int s,int p){
    visited[s]=1;
    for(const int &v:graf[s]){
        if(visited[v])continue;
        czy_spojny(v,s);
    }
    return;
}
void dfs(int s,int p){
    visited[s]=1;
    for(const int &v:nowy_graf[s]){
        if(visited[v])continue;
        dfs(v,s);
    }

    topsort.push_back(s);
    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    if(m==0){
        cout<<"TAK"<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        return 0;
    }

    graf.resize(n+1);
    visited.resize(n+1);
    nowy_graf.resize(n+1);
    licznik.resize(n+1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        licznik[a]++;
        licznik[b]++;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    //Krasnale bez przyjaciol laczymy z krasnalami 1 i n
    for(int i=1;i<=n;i++){
        if(graf[i].size()==0){
            licznik[i]++;
            licznik[i]++;
            licznik[1]++;
            licznik[2]++;

            graf[i].push_back(1);
            graf[i].push_back(2);
            graf[2].push_back(i);
            graf[1].push_back(i);
            m+=2;
        }
    }

    for(int i=1;i<=n;i++){
        licznik[i]/=2;
    }

    //Caly graf musi byc spojny aby dalo sie ustawic krasnale
    czy_spojny(1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==0)wywala();
    }

    //Kierujemy krawedzie w grafie
    visited.clear();
    visited.resize(n+1);
    queue<int> kolejka;
    kolejka.push(1);
    visited[1]=1;

    while(!kolejka.empty()){
        int punkt=kolejka.front();
        kolejka.pop();
        
        for(const int &v:graf[punkt]){
            if(visited[v]==1)continue;

            nowy_graf[punkt].push_back(v);
            licznik[v]--;

            if(licznik[v]==0 && v!=2){
                visited[v]=1;
                kolejka.push(v);
            }
        }
    }

    //Istnieje cykl lub kierujemy krawedz w obie strony
    for(int i=1;i<=n;i++){
        if(visited[i]==0 && i!=2)wywala();
    }
    int suma=0;
    for(int i=1;i<=n;i++){
        suma+=nowy_graf[i].size();
    }
    if(suma!=m)wywala();

    //Przydzielenie czapek
    visited.clear();
    visited.resize(n+1);
    dfs(1,0);
    
    vector<int> wyniki(n+1);
    for(int i=0;i<=topsort.size();i++){
        wyniki[topsort[i]]=n-i;
    }

    cout<<"TAK"<<endl;
    for(int i=1;i<=n;i++){
        cout<<wyniki[i]<<" ";
    }
    return 0;
}