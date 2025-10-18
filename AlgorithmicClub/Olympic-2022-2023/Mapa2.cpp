//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int minimum=-2e9,maksimum=2e9;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}
vector<pair<int,int>> punkty;
map<int,pair<int,pair<int,int>>> przedzialy_mapa;
vector<pair<int,pair<int,int>>> przedzialy_tablica;

vector<pair<int,pair<int,int>>> ograniczenie_dol;
vector<pair<int,pair<int,int>>> ograniczenie_gora;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int ilosc_punktow,rozmiar,wynik=0;
    cin>>ilosc_punktow>>rozmiar;

    for(int i=0;i<ilosc_punktow;i++){
        int x,y;
        cin>>x>>y;
        punkty.push_back({x,y});
    }
    sort(punkty.begin(),punkty.end());

    for(int i=0;i<ilosc_punktow;i++){
        if(przedzialy_mapa.find(punkty[i].second)==przedzialy_mapa.end()){
            przedzialy_mapa[punkty[i].second]={punkty[i].second,{punkty[i].first,punkty[i].first}};
        }else{
            przedzialy_mapa[punkty[i].second].second.first=min(przedzialy_mapa[punkty[i].second].second.first,punkty[i].first);
            przedzialy_mapa[punkty[i].second].second.second=max(przedzialy_mapa[punkty[i].second].second.second,punkty[i].first);
        }
    }
    for(auto it=przedzialy_mapa.begin();it!=przedzialy_mapa.end();++it){
        if(it!=przedzialy_mapa.begin()){
            auto it2=it;
            --it2;
            if((it->second.first)-((it2)->second.first)-1!=0){
                przedzialy_tablica.push_back({(it->second.first)-((it2)->second.first)-1,{maksimum,minimum}});
            }
        }
        przedzialy_tablica.push_back({1,{it->second.second.first,it->second.second.second}});
    }

    ograniczenie_dol.resize(przedzialy_tablica.size());
    ograniczenie_gora.resize(przedzialy_tablica.size());

    int minimum_dol=przedzialy_tablica[0].second.first,maksimum_dol=przedzialy_tablica[0].second.second;
    ograniczenie_dol[0]=przedzialy_tablica[0];
    ograniczenie_dol[0].second.first=0;
    ograniczenie_dol[0].second.second=0;

    for(int i=1;i<przedzialy_tablica.size();i++){
        ograniczenie_dol[i]=przedzialy_tablica[i];
        ograniczenie_dol[i].second.first=minimum_dol;
        ograniczenie_dol[i].second.second=maksimum_dol;

        int min1=przedzialy_tablica[i].second.first,maks1=przedzialy_tablica[i].second.second;
        minimum_dol=min(minimum_dol,min1);
        maksimum_dol=max(maksimum_dol,maks1);
    }

    int minimum_gora=przedzialy_tablica[przedzialy_tablica.size()-1].second.first,maksimum_gora=przedzialy_tablica[przedzialy_tablica.size()-1].second.second;
    ograniczenie_gora[przedzialy_tablica.size()-1]=przedzialy_tablica[przedzialy_tablica.size()-1];
    ograniczenie_gora[przedzialy_tablica.size()-1].second.first=0;
    ograniczenie_gora[przedzialy_tablica.size()-1].second.second=0;

    for(int i=przedzialy_tablica.size()-2;i>=0;i--){
        ograniczenie_gora[i]=przedzialy_tablica[i];
        ograniczenie_gora[i].second.first=minimum_gora;
        ograniczenie_gora[i].second.second=maksimum_gora;

        int min1=przedzialy_tablica[i].second.first,maks1=przedzialy_tablica[i].second.second;
        minimum_gora=min(minimum_gora,min1);
        maksimum_gora=max(maksimum_gora,maks1);
    }

    for(int i=0;i<przedzialy_tablica.size();i++){
        long long int minimum2=max(ograniczenie_dol[i].second.first,ograniczenie_gora[i].second.first);
        long long int maksimum2=min(ograniczenie_dol[i].second.second,ograniczenie_gora[i].second.second);
        if(maksimum2-minimum2-1>0){
            wynik=wynik+(przedzialy_tablica[i].first)*(maksimum2-minimum2-1);
        }
    }

    cout<<wynik;
    return 0;
}
 