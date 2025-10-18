//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct dane{
    long long int dlugosc,poczatek,koniec,numer;
};

vector<vector<char>> wejscie;

long long int przeciecie(dane wiersz,dane kolumna){
    if(!(wiersz.numer>=kolumna.poczatek && wiersz.numer<=kolumna.koniec)){
        return min(wiersz.dlugosc,kolumna.dlugosc);
    }
    if(!(kolumna.numer>=wiersz.poczatek && kolumna.numer<=wiersz.koniec)){
        return min(wiersz.dlugosc,kolumna.dlugosc);
    }

    long long int wynik1=min(kolumna.dlugosc,max(kolumna.numer-wiersz.poczatek,wiersz.koniec-kolumna.numer));
    long long int wynik2=min(wiersz.dlugosc,max(wiersz.numer-kolumna.poczatek,kolumna.koniec-wiersz.numer));
    return max(wynik1,wynik2);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    wejscie.resize(n+1,vector<char> (n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>wejscie[i][j];
        }
    }


    dane wiersz_maks1={-1,-1,-1,-1},wiersz_maks2={-1,-1,-1,-1};
    for(int i=1;i<=n;i++){
        int dlugosc=0,poczatek=1;
        for(int j=1;j<=n;j++){
            if(wejscie[i][j]=='X'){
                if(dlugosc>wiersz_maks1.dlugosc){
                    wiersz_maks2=wiersz_maks1;
                    wiersz_maks1.numer=i;
                    wiersz_maks1.dlugosc=dlugosc;
                    wiersz_maks1.poczatek=poczatek;
                    wiersz_maks1.koniec=dlugosc+poczatek-1;
                }else{
                    if(dlugosc>wiersz_maks2.dlugosc){
                        wiersz_maks2.numer=i;
                        wiersz_maks2.dlugosc=dlugosc;
                        wiersz_maks2.poczatek=poczatek;
                        wiersz_maks2.koniec=dlugosc+poczatek-1;
                    }
                }
                poczatek=j+1;
                dlugosc=0;
            }else{
                dlugosc++;
            }
        }
        if(dlugosc>wiersz_maks1.dlugosc){
            wiersz_maks2=wiersz_maks1;
            wiersz_maks1.numer=i;
            wiersz_maks1.dlugosc=dlugosc;
            wiersz_maks1.poczatek=poczatek;
            wiersz_maks1.koniec=dlugosc+poczatek-1;
        }else{
            if(dlugosc>wiersz_maks2.dlugosc){
                wiersz_maks2.numer=i;
                wiersz_maks2.dlugosc=dlugosc;
                wiersz_maks2.poczatek=poczatek;
                wiersz_maks2.koniec=dlugosc+poczatek-1;
            }
        }
    }

    dane kolumna_maks1={-1,-1,-1,-1},kolumna_maks2={-1,-1,-1,-1};
    for(int i=1;i<=n;i++){
        int dlugosc=0,poczatek=1;
        for(int j=1;j<=n;j++){
            if(wejscie[j][i]=='X'){
                if(dlugosc>kolumna_maks1.dlugosc){
                    kolumna_maks2=kolumna_maks1;
                    kolumna_maks1.numer=i;
                    kolumna_maks1.dlugosc=dlugosc;
                    kolumna_maks1.poczatek=poczatek;
                    kolumna_maks1.koniec=dlugosc+poczatek-1;
                }else{
                    if(dlugosc>kolumna_maks2.dlugosc){
                        kolumna_maks2.numer=i;
                        kolumna_maks2.dlugosc=dlugosc;
                        kolumna_maks2.poczatek=poczatek;
                        kolumna_maks2.koniec=dlugosc+poczatek-1;
                    }
                }
                poczatek=j+1;
                dlugosc=0;
            }else{
                dlugosc++;
            }
        }

        if(dlugosc>kolumna_maks1.dlugosc){
            kolumna_maks2=kolumna_maks1;
            kolumna_maks1.numer=i;
            kolumna_maks1.dlugosc=dlugosc;
            kolumna_maks1.poczatek=poczatek;
            kolumna_maks1.koniec=dlugosc+poczatek-1;
        }else{
            if(dlugosc>kolumna_maks2.dlugosc){
                kolumna_maks2.numer=i;
                kolumna_maks2.dlugosc=dlugosc;
                kolumna_maks2.poczatek=poczatek;
                kolumna_maks2.koniec=dlugosc+poczatek-1;
            }
        }
    }

    long long int wynik=0;
    if(m==1){
        wynik=max(wiersz_maks1.dlugosc,kolumna_maks1.dlugosc);
        cout<<wynik;  
    }else{
        wynik=max(wiersz_maks1.dlugosc/2,kolumna_maks1.dlugosc/2);

        if(wiersz_maks2.dlugosc!=-1)wynik=max(wynik,min(wiersz_maks1.dlugosc,wiersz_maks2.dlugosc));
        if(kolumna_maks2.dlugosc!=-1)wynik=max(wynik,min(kolumna_maks1.dlugosc,kolumna_maks2.dlugosc));

        wynik=max(wynik,przeciecie(wiersz_maks1,kolumna_maks1));
        wynik=max(wynik,przeciecie(wiersz_maks2,kolumna_maks2));
        wynik=max(wynik,przeciecie(wiersz_maks1,kolumna_maks2));
        wynik=max(wynik,przeciecie(wiersz_maks2,kolumna_maks1));

        cout<<wynik;
    }

    return 0;
}