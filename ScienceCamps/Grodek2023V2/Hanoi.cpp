//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,q;
const long long int M=1<<20;
const long long int odwrotnosc_modulo=500000004;
const long long int modulo=1e9+7;

vector<int> wejscie;
vector<long long int> tree(M*2,0);
vector<long long int> lazy(M*2,1);
vector<pair<char,int>> polecenia;
map<int,int> skalowanie;
map<int,int> przeskalowane;

void pomnoz(int punkt,long long int ile){
    lazy[punkt]=(lazy[punkt]*ile)%modulo;
    tree[punkt]=(tree[punkt]*ile)%modulo;
}

void przekaz(int punkt){
    pomnoz(2*punkt,lazy[punkt]);
    pomnoz(2*punkt+1,lazy[punkt]);
    lazy[punkt]=1;
}

void update(int gdzie,int pocz,int kon,int x,int y,long long int ile){

    if(x<=pocz && y>=kon){
        pomnoz(gdzie,ile);
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

    tree[gdzie]=(tree[2*gdzie]+tree[2*gdzie+1])%modulo;
    return;
}
void update_punkt(int gdzie,int pocz,int kon,int &x,long long int ile){

    if(x==pocz && x==kon){
        
        tree[gdzie]=(tree[gdzie]+lazy[gdzie]*ile+modulo)%modulo;
        return;
    }

    przekaz(gdzie);
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update_punkt(2*gdzie,pocz,mid,x,ile);
    }else{
        update_punkt(2*gdzie+1,mid+1,kon,x,ile);
    }

    tree[gdzie]=(tree[2*gdzie]+tree[2*gdzie+1])%modulo;
    return;
}

long long int query(int gdzie, int pocz, int kon, int &x,int &y){
   if(x<=pocz && y>=kon){
       return tree[gdzie];
   }

   przekaz(gdzie);
   int mid=(pocz+kon)/2,wynik=0;
   if(x<=mid){
       wynik=(wynik+query(2*gdzie,pocz,mid,x,y))%modulo;
   }
   if(y>mid){
       wynik=(wynik+query(2*gdzie+1,mid+1,kon,x,y))%modulo;
   }

   tree[gdzie]=(tree[2*gdzie]+tree[2*gdzie+1])%modulo;
   return wynik;
}

void dodaj(int indeks){
    if(query(1,1,M,indeks,indeks)==0){
        if(indeks>1)update(1,1,M,1,indeks-1,2);
    }
    update_punkt(1,1,M,indeks,1);
    return;
}
void usun(int indeks){
    update_punkt(1,1,M,indeks,-1);
    if(query(1,1,M,indeks,indeks)==0){
        if(indeks>1)update(1,1,M,1,indeks-1,odwrotnosc_modulo);
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>q;

    wejscie.resize(n+1);
    polecenia.resize(q+1);
    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
        skalowanie[wejscie[i]]=1;
    }
    for(int i=1;i<=q;i++){
        cin>>polecenia[i].first>>polecenia[i].second;
        skalowanie[polecenia[i].second]=1;
    }

    int liczba=2;
    for(auto it=skalowanie.begin();it!=skalowanie.end();++it){
        przeskalowane[it->first]=liczba;
        liczba++;
    }
    for(int i=1;i<=n;i++){
        wejscie[i]=przeskalowane[wejscie[i]];
    }
    for(int i=1;i<=q;i++){
        polecenia[i].second=przeskalowane[polecenia[i].second];
    }

    long long int wynik=0;
    for(int i=1;i<=n;i++){
        dodaj(wejscie[i]);
    }
    int poczatek=1;
    for(int i=1;i<=q;i++){
        if(polecenia[i].first=='+'){
            dodaj(polecenia[i].second);
        }else{
            usun(polecenia[i].second);
        }
        cout<<query(1,1,M,poczatek,liczba)<<'\n';
    }
    return 0;
}