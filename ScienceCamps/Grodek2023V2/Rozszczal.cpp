//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//LOSOWE TABLICE
vector<pair<long long int,int>> strzaly;
vector<pair<int,int>> zapytania;
vector<pair<int,int>> przedzialy;
bool cmp(const pair<long long int,int> &a,const pair<long long int,int>&b){
    return a.first>b.first;
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }else{
        return a.first<b.first;
    }
}


//DRZEWO PRZEDZIALOWE
const long long int M=1<<20;
vector<long long int> tree(M*2);
vector<long long int> lazy(M*2);
void dodaj(int punkt,long long int ile){
    lazy[punkt]=lazy[punkt]+ile;
    tree[punkt]=tree[punkt]+ile;
    return;
}
void przekaz(int punkt){
    dodaj(2*punkt,lazy[punkt]);
    dodaj(2*punkt+1,lazy[punkt]);
    lazy[punkt]=0;
    return;
}
void update(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    if(x<=pocz && y>=kon){
        dodaj(gdzie,ile);
        return;
    }

    przekaz(gdzie);
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree[gdzie]=max(tree[2*gdzie],tree[2*gdzie+1]);
    return;
}
int query(int gdzie, int pocz, int kon, int x,int y){
   if(x<=pocz && y>=kon){
       return tree[gdzie];
   }
   
   przekaz(gdzie);
   int mid=(pocz+kon)/2,wynik=0;
   if(x<=mid){
       wynik=max(wynik,query(2*gdzie,pocz,mid,x,y));
   }
   if(y>mid){
       wynik=max(wynik,query(2*gdzie+1,mid+1,kon,x,y));
   }

   tree[gdzie]=max(tree[2*gdzie],tree[2*gdzie+1]);
   return wynik;
}

void solve(){
    long long int n,m;
    cin>>n;


    for(int i=0;i<n;i++){
        long long int strzal;
        cin>>strzal;
        strzaly.push_back({strzal,i});
    }

    cin>>m;
    for(int i=0;i<m;i++){
        int poczatek,koniec;
        cin>>poczatek>>koniec;
        poczatek--;koniec--;
        zapytania.push_back({poczatek,koniec});
    }

    sort(strzaly.begin(),strzaly.end(),cmp);
    sort(zapytania.begin(),zapytania.end(),cmp2);

    int indeks=0;
    int poczatek=1,koniec=0;
    deque<int> kolejka;

    for(int i=0;i<n;i++){
        while(indeks<m && zapytania[indeks].first<=i){
            if(kolejka.empty() || zapytania[indeks].second>kolejka.front()){
                kolejka.push_front(zapytania[indeks].second);
                koniec++;
            }
            indeks++;
        } 
        while(!kolejka.empty() && kolejka.back()<i){
            kolejka.pop_back();
            poczatek++;
        }
        przedzialy.push_back({poczatek,koniec});
    }


    long long int wynik=0;
    for(int i=0;i<n;i++){
        if(przedzialy[strzaly[i].second].first>=1 && przedzialy[strzaly[i].second].second<=m && przedzialy[strzaly[i].second].first<=przedzialy[strzaly[i].second].second){
            long long int suma=query(1,1,M,przedzialy[strzaly[i].second].first,przedzialy[strzaly[i].second].second)*strzaly[i].first;
            wynik=max(wynik,suma);
            update(1,1,M,przedzialy[strzaly[i].second].first,przedzialy[strzaly[i].second].second,1);
        }
    }
    for(int i=0;i<n;i++){
        if(przedzialy[strzaly[i].second].first>=1 && przedzialy[strzaly[i].second].second<=m && przedzialy[strzaly[i].second].first<=przedzialy[strzaly[i].second].second){
            update(1,1,M,przedzialy[strzaly[i].second].first,przedzialy[strzaly[i].second].second,-1);
        }
    }

    strzaly.clear();
    zapytania.clear();
    przedzialy.clear();
    cout<<wynik<<'\n';
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}