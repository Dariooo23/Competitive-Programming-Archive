//Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int ilosc_wsp = 0;
    
    cin >> ilosc_wsp;

    if(ilosc_wsp == 1){
        cout << "0";
        return 0;
    }

    float wielomian [100009] = {};
    int indeks = 0;
    
    while(indeks < ilosc_wsp){
        cin >> wielomian [indeks];
        indeks = indeks + 1;
    }

    wielomian [0] = 0;
    indeks = 1;
    while(indeks < ilosc_wsp){
        int nowy_indeks = indeks - 1;
        wielomian [nowy_indeks] = wielomian [indeks] * indeks;

        cout << wielomian [nowy_indeks] << " ";
        indeks = indeks + 1;
    }

    return 0;
}