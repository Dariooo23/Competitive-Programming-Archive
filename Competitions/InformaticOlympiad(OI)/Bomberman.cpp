//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct kierunki{
    int lewo=1e9+9,prawo=1e9+9,gora=1e9+9,dol=1e9+9;
};

pair<int,int> poczatek,koniec;

vector<vector<char>> plansza;
vector<vector<bool>> visited;
vector<vector<char>> kierunek;
vector<vector<kierunki>> dp_koniec;
vector<vector<kierunki>> dp_poczatek;
vector<vector<int>> odleglosci_koniec;
vector<vector<int>> odleglosci_poczatek;

void bfs(pair<int,int> poczatek,int typ,int n){
    kierunek.clear();
    kierunek.resize(n+2,vector<char>(n+2));
    visited.resize(n+2,vector<bool>(n+2,0));
    if(typ==1){
        odleglosci_poczatek.resize(n+2,vector<int>(n+2,1e9+9));
    }else{
        odleglosci_koniec.resize(n+2,vector<int>(n+2,1e9+9));
    }

    queue<pair<int,int>> kolejka;
    if(typ==1){
        kolejka.push(poczatek);
        visited[poczatek.first][poczatek.second]=1;
        odleglosci_poczatek[poczatek.first][poczatek.second]=0;
    }else{
        kolejka.push(poczatek);
        visited[poczatek.first][poczatek.second]=1;
        odleglosci_koniec[poczatek.first][poczatek.second]=0;
    }

    while(!kolejka.empty()){
        pair<int,int> punkt=kolejka.front();
        kolejka.pop();
        visited[punkt.first][punkt.second]=1;
        if(plansza[punkt.first][punkt.second]=='#')continue;

        if(plansza[punkt.first-1][punkt.second]!='X' ){
            if(visited[punkt.first-1][punkt.second]!=1){
                visited[punkt.first-1][punkt.second]=1;
                if(typ==1){
                    odleglosci_poczatek[punkt.first-1][punkt.second]=odleglosci_poczatek[punkt.first][punkt.second]+1;
                }else{
                    odleglosci_koniec[punkt.first-1][punkt.second]=odleglosci_koniec[punkt.first][punkt.second]+1;
                }

                kierunek[punkt.first-1][punkt.second]='g';
                kolejka.push({punkt.first-1,punkt.second});
            }
        }
        if(plansza[punkt.first+1][punkt.second]!='X'){
            if(visited[punkt.first+1][punkt.second]!=1){
                visited[punkt.first+1][punkt.second]=1;
                if(typ==1){
                    odleglosci_poczatek[punkt.first+1][punkt.second]=odleglosci_poczatek[punkt.first][punkt.second]+1;
                }else{
                    odleglosci_koniec[punkt.first+1][punkt.second]=odleglosci_koniec[punkt.first][punkt.second]+1;
                }
                kierunek[punkt.first+1][punkt.second]='d';
                kolejka.push({punkt.first+1,punkt.second});
            }
        }
        if(plansza[punkt.first][punkt.second-1]!='X'){
            if(visited[punkt.first][punkt.second-1]!=1){
                visited[punkt.first][punkt.second-1]=1;
                if(typ==1){
                    odleglosci_poczatek[punkt.first][punkt.second-1]=odleglosci_poczatek[punkt.first][punkt.second]+1;
                }else{
                    odleglosci_koniec[punkt.first][punkt.second-1]=odleglosci_koniec[punkt.first][punkt.second]+1;
                }
                kierunek[punkt.first][punkt.second-1]='l';
                kolejka.push({punkt.first,punkt.second-1});
            }
        }
        if(plansza[punkt.first][punkt.second+1]!='X'){
            if(visited[punkt.first][punkt.second+1]!=1){
                visited[punkt.first][punkt.second+1]=1;
                if(typ==1){
                    odleglosci_poczatek[punkt.first][punkt.second+1]=odleglosci_poczatek[punkt.first][punkt.second]+1;
                }else{
                    odleglosci_koniec[punkt.first][punkt.second+1]=odleglosci_koniec[punkt.first][punkt.second]+1;
                }
                kierunek[punkt.first][punkt.second+1]='p';
                kolejka.push({punkt.first,punkt.second+1});
            }
        }
    }

    visited.clear();
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    plansza.resize(n+2,vector<char>(n+2));
    dp_poczatek.resize(n+2,vector<kierunki>(n+2));
    dp_koniec.resize(n+2,vector<kierunki>(n+2));

    for(int i=0;i<=n+1;i++){
        plansza[i][0]='X';
        plansza[0][i]='X';
        plansza[n+1][i]='X';
        plansza[i][n+1]='X';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>plansza[i][j];
            if(plansza[i][j]=='P'){
                poczatek={i,j};
            }
            if(plansza[i][j]=='K'){
                koniec={i,j};
            }
        }
    }

    bfs(poczatek,1,n);
    bfs(koniec,2,n);

    //Z gory
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(plansza[i-1][j]!='X'){
                dp_poczatek[i][j].gora=min(dp_poczatek[i-1][j].gora+1,odleglosci_poczatek[i][j]);
                dp_koniec[i][j].gora=min(dp_koniec[i-1][j].gora+1,odleglosci_koniec[i][j]);
            }else{
                dp_poczatek[i][j].gora=odleglosci_poczatek[i][j];
                dp_koniec[i][j].gora=odleglosci_koniec[i][j];
            }
        }
    }

    //Z dolu
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(plansza[i+1][j]!='X'){
                dp_poczatek[i][j].dol=min(dp_poczatek[i+1][j].dol+1,odleglosci_poczatek[i][j]);
                dp_koniec[i][j].dol=min(dp_koniec[i+1][j].dol+1,odleglosci_koniec[i][j]);
            }else{
                dp_poczatek[i][j].dol=odleglosci_poczatek[i][j];
                dp_koniec[i][j].dol=odleglosci_koniec[i][j];
            }
        }
    }

    //Z lewej
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(plansza[i][j-1]!='X'){
                dp_poczatek[i][j].lewo=min(dp_poczatek[i][j-1].lewo+1,odleglosci_poczatek[i][j]);
                dp_koniec[i][j].lewo=min(dp_koniec[i][j-1].lewo+1,odleglosci_koniec[i][j]);
            }else{
                dp_poczatek[i][j].lewo=odleglosci_poczatek[i][j];
                dp_koniec[i][j].lewo=odleglosci_koniec[i][j];
            }

        }
    }

    //Z prawej
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(plansza[i][j+1]!='X'){
                dp_poczatek[i][j].prawo=min(dp_poczatek[i][j+1].prawo+1,odleglosci_poczatek[i][j]);
                dp_koniec[i][j].prawo=min(dp_koniec[i][j+1].prawo+1,odleglosci_koniec[i][j]);
            }else{
                dp_poczatek[i][j].prawo=odleglosci_poczatek[i][j];
                dp_koniec[i][j].prawo=odleglosci_koniec[i][j];
            }
        }
    }

    pair<int,int> bomba;
    int suma=1e9+9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(plansza[i][j]=='X')continue;
            int liczba1=min({dp_poczatek[i][j].lewo,dp_poczatek[i][j].gora,dp_poczatek[i][j].dol,dp_poczatek[i][j].prawo});
            int liczba2=min({dp_koniec[i][j].lewo,dp_koniec[i][j].gora,dp_koniec[i][j].dol,dp_koniec[i][j].prawo});
            if(liczba1+liczba2<suma){
                bomba={i,j};
                suma=liczba1+liczba2;
            }
        }
    }

    if(suma>=1e9+9){
        cout<<"NIE";
        return 0;
    }

    cout<<suma<<endl;
    cout<<bomba.first<<" "<<bomba.second<<endl;

    int indeksx=bomba.first;
    int indeksy=bomba.second;
    while(plansza[indeksx][bomba.second]!='X'){
        plansza[indeksx][bomba.second]='.';
        indeksx++;
    }
    indeksx=bomba.first;
    indeksy=bomba.second;
    while(plansza[indeksx][bomba.second]!='X'){
        plansza[indeksx][bomba.second]='.';
        indeksx--;
    }
    indeksx=bomba.first;
    indeksy=bomba.second;
    while(plansza[bomba.first][indeksy]!='X'){
        plansza[bomba.first][indeksy]='.';
        indeksy--;
    }
    indeksx=bomba.first;
    indeksy=bomba.second;
    while(plansza[bomba.first][indeksy]!='X'){
        plansza[bomba.first][indeksy]='.';
        indeksy++;
    }

    odleglosci_poczatek.clear();
    bfs(poczatek,1,n);

    indeksx=koniec.first;
    indeksy=koniec.second;
    vector<char> odpowiedz;

    while(indeksx!= poczatek.first || indeksy!=poczatek.second){
        if(kierunek[indeksx][indeksy]=='l' && (plansza[indeksx][indeksy+1]=='.' || plansza[indeksx][indeksy+1]=='P')){
            odpowiedz.push_back(kierunek[indeksx][indeksy]);
            indeksy++;
        }
        if(kierunek[indeksx][indeksy]=='p' && (plansza[indeksx][indeksy-1]=='.' || plansza[indeksx][indeksy-1]=='P')){
            odpowiedz.push_back(kierunek[indeksx][indeksy]);
            indeksy--;
        }
        if(kierunek[indeksx][indeksy]=='d' && (plansza[indeksx-1][indeksy]=='.' || plansza[indeksx-1][indeksy]=='P')){
            odpowiedz.push_back(kierunek[indeksx][indeksy]);
            indeksx--;
        }
        if(kierunek[indeksx][indeksy]=='g' && (plansza[indeksx+1][indeksy]=='.' || plansza[indeksx+1][indeksy]=='P')){
            odpowiedz.push_back(kierunek[indeksx][indeksy]);
            indeksx++;
        }
    }

    for(int i=odpowiedz.size()-1;i>=0;i--){
        cout<<(char)(odpowiedz[i]-32);
    }

    return 0;
}