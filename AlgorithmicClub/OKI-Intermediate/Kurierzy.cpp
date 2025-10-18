//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct zapytanie{
    int koniec,liczba,numer;
};
struct wynik{
    int liczba,dlugosc,ilosc;
};

long long int M=(1<<20);
vector<pair<int,int>> tree(M*2);
vector<zapytanie> zapytania;
vector<wynik> wyniki;
vector<int> wejscie;

pair<int,int> polacz(pair<int,int> punkt1,pair<int,int> punkt2){
    pair<int,int> wynik;

    if(punkt2.first==0)return punkt1;
    if(punkt1.first==0)return punkt2;

    if(punkt1.first==punkt2.first){
        wynik.first=punkt1.first;
        wynik.second=punkt1.second+punkt2.second;
    }else{
        if(punkt1.second<punkt2.second)swap(punkt1,punkt2);
        wynik.first=punkt1.first;
        wynik.second=punkt1.second-punkt2.second;
    }

    return wynik;
}

pair<int,int> query(int punkt,int poczatek,int koniec,int lewo,int prawo){
    if(poczatek>=lewo && koniec<=prawo){
        return tree[punkt];
    }

    int mid=(poczatek+koniec)/2;
    pair<int,int> wynik1,wynik2;
    if(lewo<=mid){
        wynik1=query(punkt*2,poczatek,mid,lewo,prawo);
    }
    if(prawo>mid){
        wynik2=query(punkt*2+1,mid+1,koniec,lewo,prawo);
    }

    return polacz(wynik1,wynik2);
}
void stworz_drzewo(int punkt,int poczatek,int koniec){
    if(poczatek==koniec)return;
    stworz_drzewo(punkt*2,poczatek,(poczatek+koniec)/2);
    stworz_drzewo(punkt*2+1,(poczatek+koniec)/2+1,koniec);

    tree[punkt]=polacz(tree[punkt*2],tree[punkt*2+1]);
    return;
}

bool cmp(const zapytanie &a,const zapytanie &b){
    if(a.koniec==b.koniec){
        return a.numer<b.numer;
    }else{
        return a.koniec<b.koniec;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    wejscie.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }

    for(int i=1;i<=n;i++){
        tree[M+i-1]={wejscie[i],1};
    }

    stworz_drzewo(1,1,M);

    wyniki.resize(m+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        wyniki[i].ilosc=-1e9-9;
        wyniki[i].dlugosc=b-a+1;
        wyniki[i].liczba=query(1,1,M,a,b).first;
        zapytania.push_back({b,wyniki[i].liczba,i});
        zapytania.push_back({a-1,wyniki[i].liczba,i});
    }

    sort(zapytania.begin(),zapytania.end(),cmp);
    vector<int> licznik_liczb(n+1,0);

    int indeks=0;
    for(int i=0;i<=n;i++){
        licznik_liczb[wejscie[i]]++;
        while(zapytania[indeks].koniec==i && indeks!=zapytania.size()){
            if(wyniki[zapytania[indeks].numer].ilosc==-1e9-9){
                wyniki[zapytania[indeks].numer].ilosc=licznik_liczb[zapytania[indeks].liczba]*-1;
            }else{
                wyniki[zapytania[indeks].numer].ilosc+=licznik_liczb[zapytania[indeks].liczba];
            }
            indeks++;
        }
    }

    for(int i=1;i<=m;i++){
        if(wyniki[i].ilosc*2>wyniki[i].dlugosc){
            cout<<wyniki[i].liczba<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}