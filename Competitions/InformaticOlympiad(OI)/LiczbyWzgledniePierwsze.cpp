//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<long long int> czynniki_pierwsze;

long long int sprawdz_ktora(long long int liczba){
    long long int indeks=0;
    long long int maska=(1<<(int)(czynniki_pierwsze.size()));

    for(int i=1;i<maska;i++){
        long long int parzystosc=0;
        long long int mnoznik=1;
        for(int j=0;j<(int)(czynniki_pierwsze.size());j++){
            if(((i)&(1<<j))){
                parzystosc++;
                mnoznik*=czynniki_pierwsze[j];
            }
        }
         
        long long int dodajnik=liczba/mnoznik;

        if(parzystosc%2){
            indeks+=dodajnik;
        }else{
            indeks-=dodajnik;
        }
    }

    return liczba-indeks;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,k,c;
    cin>>n>>k>>c;

    long long int dzielnik=2,kopia_n=n;
    while(kopia_n>1 && dzielnik*dzielnik<=n){
        if(kopia_n%dzielnik==0){
            czynniki_pierwsze.push_back(dzielnik);
        }
        while(kopia_n%dzielnik==0){
            kopia_n/=dzielnik;
        }
        dzielnik++;
    }
    if(kopia_n>1)czynniki_pierwsze.push_back(kopia_n);

    long long int lewo=1,prawo=1e18+9,srodek;
    while(lewo<prawo){
        srodek=(lewo+prawo)/2;
        if(sprawdz_ktora(srodek)<k){
            lewo=srodek+1;
        }else{
            prawo=srodek;
        }
    }

    long long int licznik=0,indeks=lewo;
    while(licznik!=c){
        bool flaga=1;
        for(int i=0;i<czynniki_pierwsze.size();i++){
            if(indeks%czynniki_pierwsze[i]==0)flaga=0;
        }
        if(flaga){
            licznik++;
            cout<<indeks<<" ";
        }
        indeks++;
    }
    return 0;
}