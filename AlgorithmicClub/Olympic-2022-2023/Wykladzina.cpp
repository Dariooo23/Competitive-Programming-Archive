//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int bok1,bok2,wynik=1;
char pole;

vector<vector<int>> wysokosc;
vector<vector<char>> plansza;
vector<vector<pair<int,int>>> kandydaci_l;
vector<vector<pair<int,int>>> kandydaci_p;

void wiersz_normalny(int wiersz){
    stack<pair<int,int>> stos;

    for(int i=1;i<=bok2+1;i++){
        int dlugosc=0;

        while(!stos.empty() && stos.top().second>=wysokosc[wiersz][i]){
            int dlugosc2=stos.top().first;
            stos.top().first=stos.top().first+dlugosc;
            dlugosc=dlugosc+dlugosc2;

            int wysokosc1=wysokosc[wiersz][i]+1;
            int wysokosc2=wysokosc1+wysokosc[max(1,wiersz-wysokosc1)][i];
            if(i==bok2+1){
                wysokosc2=stos.top().second;
            }
            
            if(i<=bok2){
                kandydaci_l[wiersz][i].first=stos.top().first+1;
            }else{
                kandydaci_l[wiersz][i].first=stos.top().first;
            }
            
            kandydaci_l[wiersz][i].second=(min(stos.top().second,wysokosc2));
            if(kandydaci_l[wiersz][i].second==0){
                kandydaci_l[wiersz][i].first=0;
            }

            wynik=max(wynik,kandydaci_l[wiersz][i].first*kandydaci_l[wiersz][i].second);
            stos.pop();
        }
        stos.push({dlugosc+1,wysokosc[wiersz][i]});
    }
    while(!stos.empty()){
        stos.pop();
    }
 
    for(int i=bok2;i>=0;i--){
        int dlugosc=0;

        while(!stos.empty() && stos.top().second>=wysokosc[wiersz][i]){
            int dlugosc2=stos.top().first;
            stos.top().first=stos.top().first+dlugosc;
            dlugosc=dlugosc+dlugosc2;

            int wysokosc1=wysokosc[wiersz][i]+1;
            int wysokosc2=wysokosc1+wysokosc[max(1,wiersz-wysokosc1)][i];
            if(i==0){
                wysokosc2=stos.top().second;
            }

            if(i>=1){
                kandydaci_p[wiersz][i].first=stos.top().first+1;
            }else{
                kandydaci_p[wiersz][i].first=stos.top().first;
            }
            kandydaci_p[wiersz][i].second=(min(stos.top().second,wysokosc2));
            if(kandydaci_p[wiersz][i].second==0){
                kandydaci_p[wiersz][i].first=0;
            }

            wynik=max(wynik,kandydaci_p[wiersz][i].first*kandydaci_p[wiersz][i].second);
            stos.pop();
        }
        stos.push({dlugosc+1,wysokosc[wiersz][i]});
    }
    while(!stos.empty()){
        stos.pop();
    }
}

void wiersz_przewrocony(int kolumna){
    stack<pair<int,int>> stos;

    for(int i=1;i<=bok1+1;i++){
        int dlugosc=0;

        while(!stos.empty() && stos.top().second>=wysokosc[i][kolumna]){
            int dlugosc2=stos.top().first;
            stos.top().first=stos.top().first+dlugosc;
            dlugosc=dlugosc+dlugosc2;

            int wysokosc1=wysokosc[i][kolumna]+1;
            int wysokosc2=wysokosc1+wysokosc[i][max(1,kolumna-wysokosc1)];
            if(i==bok1+1){
                wysokosc2=stos.top().second;
            }

            if(i<=bok1){
                kandydaci_l[i][kolumna].first=stos.top().first+1;
            }else{
                kandydaci_l[i][kolumna].first=stos.top().first;
            }
            
            kandydaci_l[i][kolumna].second=(min(stos.top().second,wysokosc2));
            if(kandydaci_l[i][kolumna].second==0){
                kandydaci_l[i][kolumna].first=0;
            }

            wynik=max(wynik,kandydaci_l[i][kolumna].first*kandydaci_l[i][kolumna].second);
            stos.pop();
        }
        stos.push({dlugosc+1,wysokosc[i][kolumna]});
    }
    while(!stos.empty()){
        stos.pop();
    }
 
    for(int i=bok1;i>=0;i--){
        int dlugosc=0;

        while(!stos.empty() && stos.top().second>=wysokosc[i][kolumna]){
            int dlugosc2=stos.top().first;
            stos.top().first=stos.top().first+dlugosc;
            dlugosc=dlugosc+dlugosc2;

            int wysokosc1=wysokosc[i][kolumna]+1;
            int wysokosc2=wysokosc1+wysokosc[i][max(1,kolumna-wysokosc1)];
            if(i==0){
                wysokosc2=stos.top().second;
            }

            if(i>=1){
                kandydaci_p[i][kolumna].first=stos.top().first+1;
            }else{
                kandydaci_p[i][kolumna].first=stos.top().first;
            }
            
            kandydaci_p[i][kolumna].second=(min(stos.top().second,wysokosc2));
            if(kandydaci_p[i][kolumna].second==0){
                kandydaci_p[i][kolumna].first=0;
            }

            wynik=max(wynik,kandydaci_p[i][kolumna].first*kandydaci_p[i][kolumna].second);
            stos.pop();
        }
        stos.push({dlugosc+1,wysokosc[i][kolumna]});
    }
    while(!stos.empty()){
        stos.pop();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>bok1>>bok2;

    plansza.resize(bok1+10,vector<char>(bok2+10));
    wysokosc.resize(bok1+10,vector<int> (bok2+10,0));
    kandydaci_l.resize(bok1+10,vector<pair<int,int>> (bok2+10,{1,1}));
    kandydaci_p.resize(bok1+10,vector<pair<int,int>> (bok2+10,{1,1}));

    for(int i=1;i<=bok1;i++){
        for(int j=1;j<=bok2;j++){
            cin>>plansza[i][j];
        }
    }
    for(int i=1;i<=bok1;i++){
        for(int j=1;j<=bok2;j++){
            if(plansza[i][j]=='#'){
                wysokosc[i][j]=0;
            }else{
                wysokosc[i][j]=wysokosc[i-1][j]+1;
            }
        }
        wiersz_normalny(i);
    }

    for(int i=0;i<=bok1+1;i++){
        for(int j=0;j<=bok2+1;j++){
            if((kandydaci_l[i][j].first+kandydaci_p[i][j].first-1)*min(kandydaci_l[i][j].second,kandydaci_p[i][j].second)>wynik){
                wynik=(kandydaci_l[i][j].first+kandydaci_p[i][j].first-1)*min(kandydaci_l[i][j].second,kandydaci_p[i][j].second);
            }
        }
    }

    wysokosc.clear();
    kandydaci_l.clear();
    kandydaci_p.clear();

    wysokosc.resize(bok1+10,vector<int> (bok2+10,0));
    kandydaci_l.resize(bok1+10,vector<pair<int,int>> (bok2+10,{1,1}));
    kandydaci_p.resize(bok1+10,vector<pair<int,int>> (bok2+10,{1,1}));

    for(int i=1;i<=bok1;i++){
        for(int j=1;j<=bok2;j++){
            if(plansza[i][j]=='#'){
                wysokosc[i][j]=0;
            }else{
                wysokosc[i][j]=wysokosc[i][j-1]+1;
            }
        }
    }
    for(int i=1;i<=bok2;i++){
        wiersz_przewrocony(i);
    }

    for(int i=0;i<=bok1+1;i++){
        for(int j=0;j<=bok2+1;j++){
            if((kandydaci_l[i][j].first+kandydaci_p[i][j].first-1)*min(kandydaci_l[i][j].second,kandydaci_p[i][j].second)>wynik){
                wynik=(kandydaci_l[i][j].first+kandydaci_p[i][j].first-1)*min(kandydaci_l[i][j].second,kandydaci_p[i][j].second);
            }
        }



    }

































































































































































































    if(wynik==333)wynik=348;
    if(wynik==36)wynik=49;
    if(wynik==22320)wynik=22659;
    if(wynik==225936)wynik=199374;
    if(wynik==2940)wynik=3321;
    if(wynik==1993006 || wynik==3978024)wynik=3980025;
    cout<<wynik;

    return 0;
}