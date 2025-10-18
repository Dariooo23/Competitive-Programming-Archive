// Karol Dziekan
#include <iostream>

using namespace std;

void suma_wielomianow (int ilosc_wsp1, float wielomian1 [], int ilosc_wsp2, float wielomian2 [], int* ilosc_wsp3, float wielomian3 []){
    if(ilosc_wsp1 == ilosc_wsp2){
        while(*ilosc_wsp3 > 0 && wielomian1 [*ilosc_wsp3 - 1] + wielomian2 [*ilosc_wsp3 - 1] == 0){
            *ilosc_wsp3 = *ilosc_wsp3 - 1;
        }
    }

    int indeks = 0;
    while(indeks < *ilosc_wsp3){
        if(indeks < ilosc_wsp1){
            wielomian3 [indeks] = wielomian1 [indeks];
        }
        if(indeks < ilosc_wsp2){
            wielomian3 [indeks] = wielomian3 [indeks] + wielomian2 [indeks];
        }

        indeks = indeks + 1;
    }

    if(indeks == 0 && (ilosc_wsp1 != 0 || ilosc_wsp2 != 0)){
        *ilosc_wsp3 = 1;
        wielomian3 = {0};
    }

    return;
}
int main(){

    int ilosc_wsp1 = 0;
    int ilosc_wsp2 = 0;

    cin >> ilosc_wsp1;

    float wielomian1 [ilosc_wsp1] = {};

    int indeks = 0;
    while(indeks < ilosc_wsp1){
        cin >> wielomian1 [indeks];
        indeks = indeks + 1;
    }
    
    cin >> ilosc_wsp2;

    float wielomian2 [ilosc_wsp2] = {};

    indeks = 0;
    while(indeks < ilosc_wsp2){
        cin >> wielomian2 [indeks];
        indeks = indeks + 1;
    }

    int ilosc_wsp3 = 0;

    if(ilosc_wsp1 < ilosc_wsp2){
        ilosc_wsp3 = ilosc_wsp2;
    }else{
        ilosc_wsp3 = ilosc_wsp1;
    }

    float wielomian3 [ilosc_wsp3] = {};

    suma_wielomianow (ilosc_wsp1, wielomian1, ilosc_wsp2, wielomian2, &ilosc_wsp3, wielomian3);

    cout << ilosc_wsp3 << endl;

    indeks = 0;
    while(indeks < ilosc_wsp3){
        cout << wielomian3 [indeks] << " ";
        indeks++;
    }
    return 0;
}