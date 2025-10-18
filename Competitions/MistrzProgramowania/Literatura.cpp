//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int wynik=1;
vector<long long int> cale_slowo_licznik;
vector<pair<pair<LL,LL>,pair<LL,LL>>> dlugosc_prefiksow;
vector<pair<pair<LL,LL>,pair<LL,LL>>> dlugosc_sufiksow;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    dlugosc_prefiksow.resize(30,{{0,-1},{0,-1}});
    dlugosc_sufiksow.resize(30,{{0,-1},{0,-1}});
    cale_slowo_licznik.resize(30,0);

    for(int i=0;i<n;i++){
        long long int poczatek,koniec;
        string slowo1;
        cin>>slowo1;

        //Cale slowo sklada sie z jednej litery
        int flaga=1;
        for(int j=0;j<slowo1.size()-1;j++){
            if(slowo1[j]!=slowo1[j+1]){
                flaga=0;
            }
        }
        if(flaga){
            cale_slowo_licznik[slowo1[0]-'a']+=slowo1.size();
            continue;
        }

        //Prefiks
        long long int indeks=0;
        long long int licznik=1;
        char litera=slowo1[0];
        while(indeks<slowo1.size()-1 && slowo1[indeks]==slowo1[indeks+1]){
            licznik++;
            indeks++;
        }
        if(dlugosc_prefiksow[litera-'a'].first.first<licznik){
            dlugosc_prefiksow[litera-'a'].second=dlugosc_prefiksow[litera-'a'].first;
            dlugosc_prefiksow[litera-'a'].first.first=licznik;
            dlugosc_prefiksow[litera-'a'].first.second=i;
        }else{
            if(dlugosc_prefiksow[litera-'a'].second.first<licznik){
                dlugosc_prefiksow[litera-'a'].second.first=licznik;
                dlugosc_prefiksow[litera-'a'].second.second=i;
            }
        }
        poczatek=indeks+1;


        //Sufiks
        litera=slowo1[slowo1.size()-1];
        indeks=slowo1.size()-1;
        licznik=1;
        while(indeks>=1 && slowo1[indeks]==slowo1[indeks-1]){
            licznik++;
            indeks--;
        }
        if(dlugosc_sufiksow[litera-'a'].first.first<licznik){
            dlugosc_sufiksow[litera-'a'].second=dlugosc_sufiksow[litera-'a'].first;
            dlugosc_sufiksow[litera-'a'].first.first=licznik;
            dlugosc_sufiksow[litera-'a'].first.second=i;
        }else{
            if(dlugosc_sufiksow[litera-'a'].second.first<licznik){
                dlugosc_sufiksow[litera-'a'].second.first=licznik;
                dlugosc_sufiksow[litera-'a'].second.second=i;
            }
        }
        koniec=indeks-1;


        //Infiks
        licznik=1;
        litera=slowo1[poczatek];
        for(int j=poczatek;j<=koniec;j++){
            if(slowo1[j]==slowo1[j+1]){
                licznik++;
            }else{
                wynik=max(wynik,licznik);
                litera=slowo1[j+1];
                licznik=1;
            }
        }
        wynik=max(wynik,licznik);
    }

    for(int i=0;i<=25;i++){
        if(dlugosc_prefiksow[i].first.second==dlugosc_sufiksow[i].first.second){
            wynik=max(wynik,dlugosc_prefiksow[i].first.first+dlugosc_sufiksow[i].second.first+cale_slowo_licznik[i]);
            wynik=max(wynik,dlugosc_prefiksow[i].second.first+dlugosc_sufiksow[i].first.first+cale_slowo_licznik[i]);
        }else{
            wynik=max(wynik,dlugosc_prefiksow[i].first.first+dlugosc_sufiksow[i].first.first+cale_slowo_licznik[i]);
        }
    }

    cout<<wynik;
    return 0;
}