//Karol Dziekan
#include <iostream>

using namespace std;


int main(){
    
    int rozmiar_tablicy = 0;
    cin >> rozmiar_tablicy;

    int tablica [rozmiar_tablicy]={};

    int indeks = 0;
    while(indeks < rozmiar_tablicy){
        cin >> tablica [indeks];
        indeks = indeks + 1;
    }

    int wynik = 0;
    int roznica = 0;
    int min_suma = 0;
    int ogolna_suma = 0;

    indeks = 0;
    while(indeks < rozmiar_tablicy){
        ogolna_suma = ogolna_suma + tablica [indeks];
        roznica = ogolna_suma - min_suma;

        if(roznica > wynik)
            wynik = roznica;
        if(ogolna_suma < min_suma)
            min_suma = ogolna_suma;

        indeks = indeks + 1;
    }

    cout << wynik;
    return 0;
}