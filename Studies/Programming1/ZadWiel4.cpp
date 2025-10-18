// Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int ilosc_wsp1 = 0;
    int ilosc_wsp2 = 0;
    int ilosc_wsp3 = 0;

    cin >> ilosc_wsp1 >> ilosc_wsp2;

    if(ilosc_wsp1 < ilosc_wsp2){
        ilosc_wsp3 = ilosc_wsp2;
    }else{
        ilosc_wsp3 = ilosc_wsp1;
    }

    float wielomian1 [100009] = {};
    float wielomian2 [100009] = {};
    float wielomian3 [100009] = {};

    int indeks = 0;
    while(indeks < ilosc_wsp1){
        cin >> wielomian1 [indeks];
        indeks = indeks + 1;
    }

    indeks = 0;
    while(indeks < ilosc_wsp2){
        cin >> wielomian2 [indeks];
        indeks = indeks + 1;
    }

    while(ilosc_wsp3 > 0 && wielomian1 [ilosc_wsp3 - 1] + wielomian2 [ilosc_wsp3 - 1] == 0)
        ilosc_wsp3 = ilosc_wsp3 - 1;

    indeks = 0;
    while(indeks < ilosc_wsp3){
        if(indeks < ilosc_wsp1){
            wielomian3 [indeks] = wielomian1 [indeks];
        }
        if(indeks < ilosc_wsp2){
            wielomian3 [indeks] = wielomian3 [indeks] + wielomian2 [indeks];
        }

        cout << wielomian3 [indeks] << " ";
        indeks = indeks + 1;
    }

    if(indeks == 0 && (ilosc_wsp1 != 0 || ilosc_wsp2 != 0))
        cout<<0;
        
    return 0;
}