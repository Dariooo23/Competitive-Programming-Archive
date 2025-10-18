//Karol Dziekan
#include <iostream>

using namespace std;

void n_pochodna_wielomianu (int ilosc_wsp1, float wielomian [], int stopien, int *ilosc_wsp2, float wielomian2 []){
    if(ilosc_wsp1 <= stopien){
        *ilosc_wsp2 = 1;
        wielomian2 [0] = 0;
        return;
    }

    *ilosc_wsp2 = ilosc_wsp1 - stopien;

    int silnia1 = 1;
    int silnia2 = 1;

    int indeks = 2;
    while(indeks <= stopien){
        silnia1 = silnia1 * indeks;
        indeks = indeks + 1;
    }

    indeks = stopien + 1;
    wielomian2 [0] = wielomian [stopien] * silnia1;

    while(indeks < ilosc_wsp1){
        int nowy_indeks = indeks - stopien;

        silnia1 = silnia1 * indeks;
        silnia2 = silnia2 * nowy_indeks;

        wielomian2 [nowy_indeks] = wielomian [indeks] * silnia1 / silnia2;

        indeks = indeks + 1;
    }

    return;
}

int main(){

    int stopien = 0;
    int ilosc_wsp1 = 0;
    
    cin >> ilosc_wsp1;

    float wielomian1 [ilosc_wsp1] = {};

    int indeks = 0;
    while(indeks < ilosc_wsp1){
        cin >> wielomian1 [indeks];
        indeks = indeks + 1;
    }

    cin >> stopien;  

    int ilosc_wsp2 = ilosc_wsp1;
    float wielomian2 [ilosc_wsp2] = {};

    n_pochodna_wielomianu (ilosc_wsp1, wielomian1, stopien, &ilosc_wsp2, wielomian2);

    cout << ilosc_wsp2 << endl;

    indeks = 0;
    while(indeks < ilosc_wsp2){
        cout << wielomian2 [indeks] << " ";
        indeks++;
    }

    return 0;
}