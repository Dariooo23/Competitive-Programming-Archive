// Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int ilosc_wsp1 = 0;
    int ilosc_wsp2 = 0;
    int ilosc_wsp3 = 0;

    cin >> ilosc_wsp1 >> ilosc_wsp2;

    if(ilosc_wsp1 == 0 || ilosc_wsp2 == 0){
        cout << "0";
        return 0;
    }

    ilosc_wsp3 = ilosc_wsp1 + ilosc_wsp2 - 1;

    float wielomian1 [100009] = {};
    float wielomian2 [100009] = {};
    float wielomian3 [100009] = {};
    int indeks1 = 0;
    
    while(indeks1 < ilosc_wsp1){
        cin >> wielomian1 [indeks1];
        indeks1 = indeks1 + 1;
    }
    indeks1 = 0;
    while(indeks1 < ilosc_wsp2){
        cin >> wielomian2 [indeks1];
        indeks1 = indeks1 + 1;
    }

    indeks1 = 0;
    int indeks2 = 0;
    while(indeks1 < ilosc_wsp1){
        while(indeks2 < ilosc_wsp2){
            int nowy_indeks = indeks1 + indeks2;
            wielomian3 [nowy_indeks] = wielomian3 [nowy_indeks] + wielomian1 [indeks1] * wielomian2 [indeks2];
            indeks2 = indeks2 + 1;
        }
        indeks1 = indeks1 + 1;
        indeks2 = 0;
    }

    indeks1 = 0;
    while(indeks1 < ilosc_wsp3){
        cout << wielomian3 [indeks1] << " ";
        indeks1 = indeks1 + 1;
    }
    return 0;
}