//Karol Dziekan
#include <iostream>

using namespace std;

void wartosc_wielomianu(int ilosc_wsp, float wielomian[], float argument, float* wynik){
    int indeks = ilosc_wsp-1;

    while(indeks >= 0){
        *wynik = *wynik * argument;
        *wynik = *wynik + wielomian [indeks];

        indeks = indeks - 1; 
    }

    return;
}

int main(){

    int ilosc_wsp = 0;
    float argument = 0;
    float wynik = 0;
    
    cin >> ilosc_wsp;

    float wielomian [ilosc_wsp] = {};

    int indeks = 0;
    while(indeks < ilosc_wsp){
        cin >> wielomian [indeks];
        indeks = indeks + 1;
    }

    cin >> argument;
    
    wartosc_wielomianu (ilosc_wsp, wielomian, argument, &wynik);

    cout << wynik;
    return 0;
}