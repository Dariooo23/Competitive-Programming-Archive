//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int n,k,numer=1;
long long int wynik=0;

vector<int> uzyte;
vector<int> poddrzewa;
vector<vector<int>> graf;
vector<long long int> odleglosci;
vector<long long int> numery_poddrzew;
vector<long long int> odleglosci_poddrzewa;

void oblicz_odleglosci(int s,int p,long long int odleglosc){
    if(odleglosc>k)return;
    if(numery_poddrzew[k-odleglosc]!=numer){
        numery_poddrzew[k-odleglosc]=numer;
        odleglosci_poddrzewa[k-odleglosc]=0;
    }
    if(numery_poddrzew[odleglosc]!=numer){
        numery_poddrzew[odleglosc]=numer;
        odleglosci_poddrzewa[odleglosc]=0;
    }

    wynik+=odleglosci[k-odleglosc]-odleglosci_poddrzewa[k-odleglosc];

    odleglosci_poddrzewa[odleglosc]++;
    odleglosci[odleglosc]++;

    for(const int &v:graf[s]){
        if(uzyte[v])continue;
        if(v==p)continue;

        oblicz_odleglosci(v,s,odleglosc+1);
    }

    return;
}
void oblicz_poddrzewa(int s,int p){
    poddrzewa[s]=1;
    for(const int &v:graf[s]){
        if(v==p)continue;
        oblicz_poddrzewa(v,s);
        poddrzewa[s]+=poddrzewa[v];
    }

    return;
}
int znajdz_centr(int s){
    for(const int &v:graf[s]){
        if(uzyte[v])continue;
        if(poddrzewa[v]>n/2){
            poddrzewa[s]=n-poddrzewa[v];
            poddrzewa[v]=n;

            return znajdz_centr(v);
        }
    }

    return s;
}
void dekompozycja(int s){
    int centroid=znajdz_centr(s);
    uzyte[centroid]=1;

    odleglosci[0]=1;
    for(const int &v:graf[centroid]){
        if(uzyte[v])continue;
        oblicz_odleglosci(v,centroid,1);
        numer++;
    }

    odleglosci.clear();
    odleglosci.resize(k+1,0);

    for(const int &v:graf[centroid]){
        if(uzyte[v])continue;
        dekompozycja(v);
    }

    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>k;

    graf.resize(n+1);
    uzyte.resize(n+1,0);
    poddrzewa.resize(n+1);
    odleglosci.resize(k+1,0);
    numery_poddrzew.resize(k+1,0);
    odleglosci_poddrzewa.resize(k+1,0);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    oblicz_poddrzewa(1,0);
    dekompozycja(1);

    cout<<wynik;
    return 0;
}