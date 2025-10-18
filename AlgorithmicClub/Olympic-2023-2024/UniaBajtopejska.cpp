//Karol Dziekan
#include <iostream>
#include <map>

using namespace std;

long long int rek(long long int poczatek,long long int koniec,long long int potega,int stopien){
    //Warunek koncowy, niepoprawne przedzialy
    if(stopien==-1 || poczatek>=koniec)return 0;

    //Wszystkie liczby na przedziale maja ten bit zgaszony, schodzimy nizej
    if(potega>koniec){
        while(potega>koniec){
            potega>>=1;
            stopien--;
        }
        return rek(poczatek,koniec,potega,stopien);
    }

    //Wszystkie liczby na tym przedziale maja ten bit zapalony, usuwamy go i schodzimy nizej
    if(potega<=poczatek){
        while((poczatek&potega)==potega && (koniec&potega)==potega){
            poczatek-=potega;
            koniec-=potega;
            potega>>=1;
            stopien--;
        }
        return rek(poczatek,koniec,potega,stopien);
    }

    //Przedzial ktory patrzymy jest od 0 do potegi dwojki -1, jest na to gotowy wzor
    if((poczatek==0 && koniec+1==potega*2)){
        return potega*((long long int)(stopien+1));
    }

    //Laczymy obie grupy krawedzia o wadze aktualnej potegi
    return rek(poczatek,potega-1,potega>>1,stopien-1)+rek(0,koniec-potega,potega>>1,stopien-1)+potega;
}

void solve(){
    long long int poczatek,koniec;
    cin>>poczatek>>koniec;

    int stopien=(63-(__builtin_clzll(koniec)));
    long long int potega=(((long long int)(1))<<stopien);


    while(stopien>=0 && (poczatek&(potega))==(koniec&(potega))){
        if((poczatek&(potega))){
            poczatek-=potega;
            koniec-=potega;
        }

        potega>>=1;
        --stopien;
    }

    long long int polaczenie=potega;
    int indeks=stopien;
    while(indeks>=0){
        if((poczatek&(((long long int)1)<<indeks))){
            if((polaczenie+(((long long int)1)<<indeks))<=koniec){
                polaczenie+=(((long long int)1)<<indeks);
            }
        }
        --indeks;
    }

    cout<<rek(poczatek,potega-1,potega,stopien)+rek(0,koniec-potega,potega,stopien)+(poczatek^polaczenie)<<endl;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}