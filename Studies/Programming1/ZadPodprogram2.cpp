// Karol Dziekan
#include <iostream>

using namespace std;

void iloczyn_wielomianow (int ilosc_wsp1, float wielomian1 [], int ilosc_wsp2, float wielomian2 [], int* ilosc_wsp3, float wielomian3 []){
    if(ilosc_wsp1 == 0 || ilosc_wsp2 == 0){
        *ilosc_wsp3 = 1;
        wielomian3 [0] = 0;
        return;
    }

    int indeks1 = 0;
    int indeks2 = 0;
    while(indeks1 < ilosc_wsp1){
        while(indeks2 < ilosc_wsp2){
            int nowy_indeks = (indeks1 + indeks2);
            wielomian3 [nowy_indeks] = wielomian3 [nowy_indeks] + wielomian1 [indeks1] * wielomian2 [indeks2];
            indeks2 = indeks2 + 1;
        }
        indeks1 = indeks1 + 1;
        indeks2 = 0;
    }

    return;
}

int main(){

    int ilosc_wsp1 = 0;

    cin >> ilosc_wsp1;

    float wielomian1 [ilosc_wsp1] = {};

    int indeks = 0;
    while(indeks < ilosc_wsp1){
        cin >> wielomian1 [indeks];
        indeks++;
    }

    int ilosc_wsp2 = 0;

    cin >> ilosc_wsp2;

    float wielomian2 [ilosc_wsp2] = {};

    indeks = 0;
    while(indeks < ilosc_wsp2){
        cin >> wielomian2 [indeks];
        indeks++;
    }

    int ilosc_wsp3 = ilosc_wsp1 + ilosc_wsp2 - 1;

    float wielomian3 [ilosc_wsp3] = {};

    iloczyn_wielomianow (ilosc_wsp1, wielomian1, ilosc_wsp2, wielomian2, &ilosc_wsp3, wielomian3);

    cout << ilosc_wsp3 << endl;

    indeks = 0;
    while(indeks < ilosc_wsp3){
        cout << wielomian3 [indeks] << " ";
        indeks++;
    }

    return 0;
}