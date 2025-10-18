//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int M=(1<<20);
vector<long long int> lazy(2*M);
vector<pair<long long int,long long int>> tree(2*M);

void dodaj(long long int punkt,long long int wartosc){
    tree[punkt].first+=wartosc;
    lazy[punkt]+=wartosc;
}
void przekaz(long long int punkt){
    dodaj(punkt*2,lazy[punkt]);
    dodaj(punkt*2+1,lazy[punkt]);
    lazy[punkt]=0;
    return;
}

void update(int punkt,int lewo,int prawo,int poczatek,int koniec,long long int wartosc){
    if(lewo>=poczatek && prawo<=koniec){
        if(lewo==prawo)tree[punkt].second=punkt;
        dodaj(punkt,wartosc);
        return;
    }

    przekaz(punkt);

    long long int srodek=(lewo+prawo)/2;
    if(poczatek<=srodek){
        update(punkt*2,lewo,srodek,poczatek,koniec,wartosc);
    }
    if(koniec>srodek){
        update(punkt*2+1,srodek+1,prawo,poczatek,koniec,wartosc);
    }

    if(tree[punkt*2].first>=tree[punkt*2+1].first){
        tree[punkt]=tree[punkt*2];
    }else{
        tree[punkt]=tree[punkt*2+1];
    }
    return;
}

pair<long long int,long long int> znajdz(int punkt,int lewo,int prawo){
    if(lewo==prawo){
        return tree[punkt];
    }

    przekaz(punkt);

    long long int srodek=(lewo+prawo)/2;
    if(tree[punkt*2].first>0){
        return znajdz(punkt*2,lewo,srodek);
    }else{
        return znajdz(punkt*2+1,srodek+1,prawo);
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<long long int> wejscie(n+1);
    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }

    long long int suma=0;
    for(int i=n;i>=1;i--){
        update(1,1,M,i,i,wejscie[i]-suma);
        suma+=wejscie[i];
    }

    vector<long long int> odpowiedzi;
    odpowiedzi.push_back(suma);
    
    for(int i=n;i>=1;i--){
        pair<long long int,long long int> odejmnik=znajdz(1,1,M);
        odejmnik.second=odejmnik.second-M+1;

        update(1,1,M,odejmnik.second,odejmnik.second,-1e18);
        if(odejmnik.second-1>=1)update(1,1,M,1,odejmnik.second-1,wejscie[odejmnik.second]);

        suma-=wejscie[odejmnik.second];
        odpowiedzi.push_back(suma);
    }

    for(int i=odpowiedzi.size()-2;i>=0;i--){
        cout<<odpowiedzi[i]<<" ";
    }
    return 0;
}