//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct przycisk{
    int x,y;
};

//Podstawowe vector'y
vector<int> odpowiedz;
vector<set<int>> kolumny;
vector<set<int>> wiersze;
vector<przycisk> przyciski;

//Przypadek %2==0
vector<int> cykl;
vector<int> visited;
vector<vector<int>> graf;

long long int znaleziony=0;
long long int flagacyklowa=0;
int dfs(int s,int p){
    visited[s]=1;
    for(const int &v:graf[s]){
        if(v==p)continue;
        if(visited[v]==1){
            znaleziony=v;
            flagacyklowa=1;
            cykl.push_back(s);
            return 1;
        }

        if(dfs(v,s)){
            if(flagacyklowa==1)cykl.push_back(s);
            if(s==znaleziony)flagacyklowa=0;
            return 1;
        }
    }

    return 0;
}

int czy_zakret(przycisk a, przycisk b, przycisk c){
    if(a.x==b.x && b.x==c.x)return 0;
    if(a.y==b.y && b.y==c.y)return 0;
    return 1;
}

//Przypadek %2==1
vector<int> licznik_kolumn;
vector<int> licznik_wierszy;

void pewniaczki(int numer,int stan){
    if(stan==1){
        odpowiedz.push_back(numer);
        licznik_kolumn[przyciski[numer].y]++;
        licznik_wierszy[przyciski[numer].x]++;
    }
    wiersze[przyciski[numer].x].erase(numer);
    kolumny[przyciski[numer].y].erase(numer);

    if(wiersze[przyciski[numer].x].size()==1){
        if(licznik_wierszy[przyciski[numer].x]%2==0){
            pewniaczki(*wiersze[przyciski[numer].x].begin(),1);
        }else{
            pewniaczki(*wiersze[przyciski[numer].x].begin(),0);
        }
    }
    if(kolumny[przyciski[numer].y].size()==1){
        if(licznik_kolumn[przyciski[numer].y]%2==0){
            pewniaczki(*kolumny[przyciski[numer].y].begin(),1);
        }else{
            pewniaczki(*kolumny[przyciski[numer].y].begin(),0);
        }
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    wiersze.resize(n+10);
    kolumny.resize(n+10);
    przyciski.resize(m+10);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        przyciski[i]={a,b};
        wiersze[a].insert(i);
        kolumny[b].insert(i);
    }
    //Przypadek %2==0
    graf.resize(m+10);
    visited.resize(m+10,0);

    for(int i=1;i<=n;i++){
        set<int>::iterator indeks1,indeks2,indeks3=wiersze[i].begin();
        indeks1=indeks3;
        if(indeks3!=wiersze[i].end())++indeks3;
        indeks2=indeks3;
        if(indeks3!=wiersze[i].end())++indeks3;
    
        if(indeks1!=wiersze[i].end() && indeks2!=wiersze[i].end()){
            graf[*indeks1].push_back(*indeks2);
        }
        while(indeks3!=wiersze[i].end()){
            graf[*indeks2].push_back(*indeks1);
            graf[*indeks2].push_back(*indeks3);
            indeks1=indeks2;
            indeks2=indeks3;
            ++indeks3;
        }
        if(indeks1!=wiersze[i].end() && indeks2!=wiersze[i].end()){
            graf[*indeks2].push_back(*indeks1);
        }
    }

    for(int i=1;i<=n;i++){
        set<int>::iterator indeks1,indeks2,indeks3=kolumny[i].begin();
        indeks1=indeks3;
        if(indeks3!=kolumny[i].end())++indeks3;
        indeks2=indeks3;
        if(indeks3!=kolumny[i].end())++indeks3;
    
        if(indeks1!=kolumny[i].end() && indeks2!=kolumny[i].end()){
            graf[*indeks1].push_back(*indeks2);
        }
        while(indeks3!=kolumny[i].end()){
            graf[*indeks2].push_back(*indeks1);
            graf[*indeks2].push_back(*indeks3);
            indeks1=indeks2;
            indeks2=indeks3;
            ++indeks3;
        }
        if(indeks1!=kolumny[i].end() && indeks2!=kolumny[i].end()){
            graf[*indeks2].push_back(*indeks1);
        }
    }

    for(int i=1;i<=m;i++){
        if(visited[i]==1)continue;
        if(dfs(i,-1) || cykl.size()!=0)break;
    }
    
    if(cykl.size()!=0){
        if(czy_zakret(przyciski[cykl[cykl.size()-1]],przyciski[cykl[0]],przyciski[cykl[1]])){
            odpowiedz.push_back(cykl[0]);
        }
        if(czy_zakret(przyciski[cykl[cykl.size()-2]],przyciski[cykl[cykl.size()-1]],przyciski[cykl[0]])){
            odpowiedz.push_back(cykl[cykl.size()-1]);
        }
        int indeks=1;
        while(indeks!=cykl.size()-1){
            if(czy_zakret(przyciski[cykl[indeks-1]],przyciski[cykl[indeks]],przyciski[cykl[indeks+1]])){
                odpowiedz.push_back(cykl[indeks]);
            }indeks++;
        }

        
        cout<<"TAK"<<endl;
        cout<<odpowiedz.size()<<endl;
        sort(odpowiedz.begin(),odpowiedz.end());
        for(int i=0;i<odpowiedz.size();i++){
            cout<<odpowiedz[i]<<" ";
        }
        return 0;
    }

    
    //Przypadek %2==1
    licznik_kolumn.resize(n+1,0);
    licznik_wierszy.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(wiersze[i].size()==1){
            pewniaczki(*wiersze[i].begin(),1);
        }
    }
    for(int i=1;i<=n;i++){
        if(kolumny[i].size()==1){
            pewniaczki(*kolumny[i].begin(),1);
        }
    }
    int rownosc=licznik_wierszy[1]%2,flaga=1;
    for(int i=1;i<=n;i++){
        if(rownosc!=licznik_wierszy[i]%2){
            flaga=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(rownosc!=licznik_kolumn[i]%2){
            flaga=0;
        }
    }

    if(flaga==0){
        cout<<"NIE";
        return 0;
    }else{
        cout<<"TAK"<<endl;
        cout<<odpowiedz.size()<<endl;
        sort(odpowiedz.begin(),odpowiedz.end());
        for(int i=0;i<odpowiedz.size();i++){
            cout<<odpowiedz[i]<<" ";
        }
        return 0;
    }
}