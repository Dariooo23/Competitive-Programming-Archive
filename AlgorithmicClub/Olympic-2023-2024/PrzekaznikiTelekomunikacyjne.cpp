//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int n,m;
long long int podstawa=(1<<22);

struct punkt{
    long long int suma=0;
    long long int lazy_s=0,lazy_a=0;
};

vector<punkt> drzewo;
vector<pair<long long int,long long int>> przekazniki;

void dodaj(punkt &wierzcholek,long long int suma,long long int a,long long int dlugosc){
    wierzcholek.suma=wierzcholek.suma+dlugosc*suma+((dlugosc*(dlugosc-1))/2)*a;
    wierzcholek.lazy_s=wierzcholek.lazy_s+suma;
    wierzcholek.lazy_a=wierzcholek.lazy_a+a;
    return;
}
void przepchaj(int nr_wierzcholka,punkt &wierzcholek,long long int dlugosc1,long long int dlugosc2){
    dodaj(drzewo[nr_wierzcholka*2],wierzcholek.lazy_s,wierzcholek.lazy_a,dlugosc1);
    dodaj(drzewo[nr_wierzcholka*2+1],wierzcholek.lazy_s+dlugosc1*wierzcholek.lazy_a,wierzcholek.lazy_a,dlugosc2);

    wierzcholek.lazy_s=0;
    wierzcholek.lazy_a=0;
    return;
}

long long int suma(int wierzcholek,int lewo,int prawo,int poczatek,int koniec){
    if(poczatek<=lewo && koniec>=prawo){
        return drzewo[wierzcholek].suma;
    }

    long long int srodek=(lewo+prawo)/2,wynik=0;
    przepchaj(wierzcholek,drzewo[wierzcholek],srodek-lewo+1,prawo-srodek);

    if(poczatek<=srodek){
        wynik=wynik+suma(2*wierzcholek,lewo,srodek,poczatek,koniec);
    }
    if(koniec>srodek){
        wynik=wynik+suma(2*wierzcholek+1,srodek+1,prawo,poczatek,koniec);
    }

    return wynik;
}

void aktualizuj(int wierzcholek,int lewo,int prawo,int poczatek,long long int koniec,long long int wartosc,long long int wspolczynnik){
    if(poczatek<=lewo && koniec>=prawo){
        dodaj(drzewo[wierzcholek],wartosc,wspolczynnik,prawo-lewo+1);
        return;
    }

    int srodek=(lewo+prawo)/2;
    przepchaj(wierzcholek,drzewo[wierzcholek],srodek-lewo+1,prawo-srodek);

    if(poczatek<=srodek){
        aktualizuj(2*wierzcholek,lewo,srodek,poczatek,koniec,wartosc,wspolczynnik);
    }
    if(koniec>srodek){
        long long int przesuwnik;
        if(poczatek>=lewo){
            przesuwnik=srodek-poczatek+1;
        }else{
            przesuwnik=srodek-lewo+1;
        }
        aktualizuj(2*wierzcholek+1,srodek+1,prawo,poczatek,koniec,wartosc+wspolczynnik*max((LL)0,przesuwnik),wspolczynnik);
    }

    drzewo[wierzcholek].suma=drzewo[wierzcholek*2].suma+drzewo[wierzcholek*2+1].suma;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    przekazniki.resize(400000);
    drzewo.resize(podstawa*2+n+10);

    for(int i=1;i<=m;i++){
        char operacja;
        cin>>operacja;
        if(operacja=='P'){
            long long int miejsce,start,wsp;
            cin>>miejsce>>start>>wsp;
            przekazniki[miejsce]={start,wsp};

            //Ciag po prawej
            int poczatek=miejsce,koniec=miejsce+start/wsp;
            aktualizuj(1,1,podstawa,poczatek,min(koniec,n),start,-wsp);
            

            //Ciag po lewej
            poczatek=miejsce-start/wsp;koniec=miejsce-1;
            if(poczatek<=koniec && koniec>=1){
                long long int dodajnik=0;
                if(poczatek<=0){
                    dodajnik=wsp*(poczatek-1)*-1;
                    poczatek=1;
                }
                aktualizuj(1,1,podstawa,poczatek,min(koniec,n),start-(start/wsp)*wsp+dodajnik,wsp);
            }
        }

        if(operacja=='U'){
            long long int miejsce,start,wsp;
            cin>>miejsce;
            wsp=przekazniki[miejsce].second;
            start=przekazniki[miejsce].first;
            przekazniki[miejsce]={0,0};

            //Ciag po prawej
            int poczatek=miejsce,koniec=miejsce+start/wsp;
            aktualizuj(1,1,podstawa,poczatek,min(koniec,n),-start,wsp);

            //Ciag po lewej
            poczatek=miejsce-start/wsp;koniec=miejsce-1;
            if(poczatek<=koniec && koniec>=1){
                long long int dodajnik=0;
                if(poczatek<=0){
                    dodajnik=wsp*(poczatek-1)*-1;
                    poczatek=1;
                }
                aktualizuj(1,1,podstawa,poczatek,min(koniec,n),-(start-(start/wsp)*wsp+dodajnik),-wsp);
            }
        }

        if(operacja=='Z'){
            long long int poczatek,koniec;
            cin>>poczatek>>koniec;
            cout<<(suma(1,1,podstawa,poczatek,koniec))/(koniec-poczatek+1)<<endl;
        }
    }

    return 0;
}