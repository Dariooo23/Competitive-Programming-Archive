//Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int stopien = 0;
    int ilosc_wsp = 0;
    
    cin >> ilosc_wsp;

    float wielomian [100009] = {};
    int indeks = 1;

    indeks = 0;
    while(indeks < ilosc_wsp){
        cin >> wielomian [indeks];
        indeks = indeks + 1;
    }

    cin >> stopien;

    if(ilosc_wsp <= stopien){
        cout << "0";
        return 0;
    }

    int silnia1 = 1;
    int silnia2 = 1;

    indeks = 2;
    while(indeks <= stopien){
        silnia1 = silnia1 * indeks;
        indeks = indeks + 1;
    }

    indeks = stopien + 1;
    wielomian [0] = wielomian [stopien] * silnia1;
    cout<< wielomian [0] << " ";

    while(indeks < ilosc_wsp){
        int nowy_indeks = indeks - stopien;

        silnia1 = silnia1 * indeks;
        silnia2 = silnia2 * nowy_indeks;

        wielomian [nowy_indeks] = wielomian [indeks] * silnia1 / silnia2;

        cout << wielomian [nowy_indeks] << " ";
        indeks = indeks + 1;
    }


    return 0;
}