//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct przejscia{
    pair<int,int> lewo={-1,-1},prawo={-1,-1},gora={-1,-1},dol={-1,-1};
};

vector<vector<char>> plansza;
vector<vector<int>> odleglosci;
vector<vector<przejscia>> graf;

pair<int,int> poczatek,koniec;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    plansza.resize(n+1,vector<char>(m+1));
    graf.resize(n+1,vector<przejscia>(m+1));
    odleglosci.resize(n+1,vector<int>(m+1,-1));

    int licznik=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            licznik++;
            cin>>plansza[i][j];

            if(plansza[i][j]=='P'){
                poczatek={i,j};
            }
            if(plansza[i][j]=='K'){
                koniec={i,j};
            }
        }
    }

    pair<int,int> liczba;
    //Spadanie w osi x z lewej na prawo
    for(int i=2;i<n;i++){
        liczba={-1,-1};
        for(int j=m-1;j>1;j--){
            if(liczba.first==-1){
                liczba={i,j};
            }
            if(plansza[i][j]=='#'){
                liczba={-1,-1};
            }
            if(liczba.first!=-1 && !(liczba.first==i && liczba.second==j)){
                if(plansza[i-1][j]=='#' || plansza[i+1][j]=='#'){
                    graf[i][j].prawo=liczba;
                }
            }
        }
    }

    //Spadanie w osi x z prawej na lewo
    for(int i=2;i<n;i++){
        liczba={-1,-1};
        for(int j=2;j<m;j++){
            if(liczba.first==-1){
                liczba={i,j};
            }
            if(plansza[i][j]=='#'){
                liczba={-1,-1};
            }
            if(liczba.first!=-1 && !(liczba.first==i && liczba.second==j)){
                if(plansza[i-1][j]=='#' || plansza[i+1][j]=='#'){
                    graf[i][j].lewo=liczba;
                }
            }
        }
    }

    //Spadanie w osi y z gory na dol
    for(int i=2;i<m;i++){
        liczba={-1,-1};
        for(int j=n-1;j>1;j--){
            if(liczba.first==-1){
                liczba={j,i};
            }
            if(plansza[j][i]=='#'){
                liczba={-1,-1};
            }
            if(liczba.first!=-1 && !(liczba.first==j && liczba.second==i)){
                if(plansza[j][i-1]=='#' || plansza[j][i+1]=='#'){
                    graf[j][i].dol=liczba;
                }
            }
        }
    }

    //Spadanie w ois y z dolu na gore
    for(int i=2;i<m;i++){
        liczba={-1,-1};
        for(int j=2;j<n;j++){
            if(liczba.first==-1){
                liczba={j,i};
            }
            if(plansza[j][i]=='#'){
                liczba={-1,-1};
            }
            if(liczba.first!=-1 && !(liczba.first==j && liczba.second==i)){
                if(plansza[j][i-1]=='#' || plansza[j][i+1]=='#'){
                    graf[j][i].gora=liczba;
                }
            }
        }
    }

    queue<pair<pair<int,int>,int>> kolejka;
    kolejka.push({{poczatek.first,poczatek.second},0});
    odleglosci[poczatek.first][poczatek.second]=0;

    while(!kolejka.empty()){
        pair<pair<int,int>,int> punkt=kolejka.front();
        pair<int,int> punktg=punkt.first;
        kolejka.pop();

       
        pair<int,int> punktp=graf[punktg.first][punktg.second].lewo;
        if(punktp.first!=-1 && punktp.second!=-1){
            if(odleglosci[punktp.first][punktp.second]==-1){
                if(punkt.second==0){
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }else{
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }
            }
        }

        punktp=graf[punktg.first][punktg.second].prawo;
        if(punktp.first!=-1 && punktp.second!=-1){
            if(odleglosci[punktp.first][punktp.second]==-1){
                if(punkt.second==0){
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }else{
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }
            }
        }
        punktp=graf[punktg.first][punktg.second].gora;
        if(punktp.first!=-1 && punktp.second!=-1){
            if(odleglosci[punktp.first][punktp.second]==-1){
                if(punkt.second==0){
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }else{
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }
            }
        }

        punktp=graf[punktg.first][punktg.second].dol;
        if(punktp.first!=-1 && punktp.second!=-1){
            if(odleglosci[punktp.first][punktp.second]==-1){
                if(punkt.second==0){
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }else{
                    if(punktg.first==punktp.first){
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+2;
                        kolejka.push({{punktp.first,punktp.second},1});
                    }else{
                        odleglosci[punktp.first][punktp.second]=odleglosci[punktg.first][punktg.second]+1;
                        kolejka.push({{punktp.first,punktp.second},0});
                    }
                }
            }
        }
    }

    cout<<odleglosci[koniec.first][koniec.second];
    return 0;
}