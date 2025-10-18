//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long  > tab;
vector<vector<long long >> rozklady;
vector<pair<long long ,long long >> minima;
vector<map<long long ,long long >> przejscia;
vector<long long  > pierwsze;

long long  nr_punktu=1;

void minimum(long long  liczba,long long  indeks){
    if(liczba<minima[indeks].first){
        minima[indeks].second=minima[indeks].first;
        minima[indeks].first=liczba;
    }else{
        if(liczba<minima[indeks].second){
            minima[indeks].second=liczba;
        }
    }

    return;
}
void dodaj(long long  punkt,long long  pozycja,long long  liczba){
    //cout<<liczba<<" ";
    minimum(liczba,punkt);
    
    long long  indeks=rozklady[pozycja][rozklady[pozycja].size()-1];
    if(przejscia[punkt].find(indeks)==przejscia[punkt].end()){
        przejscia[punkt][indeks]=nr_punktu;
        punkt=nr_punktu;
        nr_punktu++;
    }else{
        punkt=przejscia[punkt][indeks];
    }

    for(long long  i=rozklady[pozycja].size()-2;i>=0;i--){
        liczba=liczba/indeks;
        //cout<<liczba<<" ";
        minimum(liczba,punkt);
        indeks=rozklady[pozycja][i];

        if(przejscia[punkt].find(indeks)==przejscia[punkt].end()){
            przejscia[punkt][indeks]=nr_punktu;
            punkt=nr_punktu;
            nr_punktu++;
        }else{
            punkt=przejscia[punkt][indeks];
        }
    }

    liczba=liczba/indeks;
    minimum(liczba,punkt);
    return;
}

long long  znajdz(long long  punkt,long long  pozycja,long long  liczba,long long  indeks){
    if(indeks==-1){
        if(minima[punkt].first==liczba){
            return minima[punkt].second*liczba;
        }else{
            return minima[punkt].first*liczba;
        }
    }
    if(liczba==1){
        if(minima[punkt].first==liczba){
            return minima[punkt].second*liczba;
        }else{
            return minima[punkt].first*liczba;
        }
    }

    long long  wynik=2e9+9;
    if((minima[przejscia[punkt][rozklady[pozycja][indeks]]].first!=liczba/rozklady[pozycja][indeks] 
    || minima[przejscia[punkt][rozklady[pozycja][indeks]]].second!=2e9+9)){

        punkt=przejscia[punkt][rozklady[pozycja][indeks]];
        liczba=liczba/rozklady[pozycja][indeks];
        indeks--;
        wynik=znajdz(punkt,pozycja,liczba,indeks);
    }
    if(minima[punkt].first==liczba){
        return min(wynik,minima[punkt].second*liczba);
    }else{
        return min(wynik,minima[punkt].first*liczba);
    }
}
void sito(long long   n){
    pierwsze.resize(1000009);

    pierwsze[1]=0;
    for(long long  i=2;i<=n;i++){
        pierwsze[i]=i;
    }

    for(long long  i=4;i<=n;i=i+2){
        pierwsze[i]=2;
    }

    for(long long  i=3;i<=n;i++){
        if(pierwsze[i]){
            for (long long  j=i*i;j<=n;j=j+i){
                if (pierwsze[j]==j){
                    pierwsze[j]=i;
                }
            }
        }
    }

    return;
}

void rozklad(long long   indeks,long long   liczba)
{
    if(liczba==1){
        rozklady[indeks].push_back(liczba);
    }
    while(liczba!=1){
        rozklady[indeks].push_back(pierwsze[liczba]);
        liczba=liczba/pierwsze[liczba];
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long  n;
    cin>>n;

    tab.resize(1000009);
    rozklady.resize(1000009);
    przejscia.resize(1000009);
    minima.resize(1000009,{2e9+9,2e9+9});

    sito(1000001);

    long long korzen=nr_punktu;
    nr_punktu++;

    for(long long  i=0;i<n;i++){
        cin>>tab[i];
        rozklad(i,tab[i]);
        dodaj(korzen,i,tab[i]);
    }

    for(long long  i=0;i<n;i++){
        long long  wynik=1e9;
        if(minima[1].first==tab[i]){
            wynik=minima[1].second*tab[i];
        }else{
            wynik=minima[1].first*tab[i];
        }
        cout<<min(wynik,znajdz(korzen,i,tab[i],rozklady[i].size()-1))<<" ";
    }

    return 0;
}