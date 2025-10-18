//Karol Dziekan
#include <bits/stdc++.h>
using namespace std;

const long long int M=1<<20;
const int maks=1e9;
int n,m,q;

struct zapytanie{
  int poczatek,koniec,ilosc;
};

vector<long long int> tree;
vector<vector<int>> stacje;
vector<zapytanie> zapytania;
vector<int> zapotrzebowanie;
vector<pair<int,int>> przedzial_wyszukiwan;

void update(int a,int b,long long int c){
    a=a+M;
    b=b+M;

    tree[a]=tree[a]+c;
    if(a!=b){
        tree[b]=tree[b]+c;
    }

    while(a/2!=b/2){
        if(a%2==0){
            tree[a+1]=tree[a+1]+c;
            if(tree[a+1]>maks){
                tree[a+1]=maks;
            }
        }
        if(b%2==1){
            tree[b-1]=tree[b-1]+c;
            if(tree[b-1]>maks){
                tree[b-1]=maks;
            }
        }
        a=a/2;
        b=b/2;
    }

    return;
}
long long int query(int a){
    a=a+M;
    long long int wynik=tree[a];

    while(a!=1){
        a=a/2;
        wynik=wynik+tree[a];
        if(wynik>maks){
            return maks;
        }
    }

    return wynik;
}
void wyczysz_drzewo(){
    tree.clear();
    tree.resize(M*2,0);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    stacje.resize(n);
    zapotrzebowanie.resize(n);
    przedzial_wyszukiwan.resize(n);

    for(int i=0;i<m;i++){
        int panstwo;

        cin>>panstwo;
        panstwo--;

        stacje[panstwo].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin>>zapotrzebowanie[i];
    }

    cin>>q;
    zapytania.resize(q);
    
    for(int i=0;i<q;i++){
        cin>>zapytania[i].poczatek;
        zapytania[i].poczatek--;
        cin>>zapytania[i].koniec;
        zapytania[i].koniec--;
        cin>>zapytania[i].ilosc;
    }

    for(int i=0;i<n;i++){
        przedzial_wyszukiwan[i].first=0;
        przedzial_wyszukiwan[i].second=q;
    }

    pair<int,int> srodki[n];

    while(true){
        int lewo=0;
        for(int i=0;i<n;i++){
            if(przedzial_wyszukiwan[i].first!=przedzial_wyszukiwan[i].second){
                srodki[lewo].first=(przedzial_wyszukiwan[i].first+przedzial_wyszukiwan[i].second)/2;
                srodki[lewo].second=i;
                lewo++;
            }
        }
        if(lewo==0){
            break;
        }

        sort(srodki,srodki+lewo);
        wyczysz_drzewo();
        int wskaznik=0;

        for(int i=0;i<q && wskaznik<lewo;i++){
            if(zapytania[i].poczatek<=zapytania[i].koniec){
                update(zapytania[i].poczatek,zapytania[i].koniec,zapytania[i].ilosc);
            }else{
                update(zapytania[i].poczatek,m-1,zapytania[i].ilosc);
                update(0,zapytania[i].koniec,zapytania[i].ilosc);
            }
            while(wskaznik<lewo && srodki[wskaznik].first==i){
                int suma=0,panstwo=srodki[wskaznik].second;
                for(int j=0;j<stacje[panstwo].size();j++){
                    suma=suma+query(stacje[panstwo][j]);
                    if(suma>=maks){
                        break;
                    }
                }
                if(zapotrzebowanie[panstwo]<=suma){
                    przedzial_wyszukiwan[panstwo].second=i;
                }else{
                    przedzial_wyszukiwan[panstwo].first=i+1;
                }
                wskaznik++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(przedzial_wyszukiwan[i].first<q){
            cout<<przedzial_wyszukiwan[i].first+1<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }

    return 0;
}
