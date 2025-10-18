//Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int ilosc_wsp = 0;
    float argument = 0;
    float wynik = 0;
    
    cin >> ilosc_wsp;

    float wielomian [100009] = {};
    int indeks = 0;
    
    while(indeks < ilosc_wsp){
        cin >> wielomian [indeks];
        indeks = indeks + 1;
    }

    cin >> argument;

    //WERSJA O(n*n)
    wynik=0;
    indeks=0;
    while(indeks < ilosc_wsp){
        int potega = indeks;
        int podstawa = argument;
        float wyraz = wielomian [indeks];
        
        while(potega > 0){
            wyraz = wyraz * podstawa;
            potega = potega - 1;
        }

        wynik = wynik + wyraz;
        indeks = indeks + 1;
    }
    cout << wynik << endl;

    //WERSJA O(n*log(n))
    wynik=0;
    indeks = 0;
    while(indeks < ilosc_wsp){
        int potega = indeks;
        float podstawa = argument;
        float wyraz = wielomian [indeks];

        while(potega > 0){
            if(potega % 2 != 0){
                wyraz = wyraz * podstawa;
                potega = potega - 1;
            }else{
                podstawa = podstawa * podstawa;
                potega = potega / 2;
            }
        }

        wynik = wynik + wyraz;
        indeks = indeks + 1;
    }
    cout << wynik << endl;

    //WERSJA O(n)
    wynik=0;
    indeks = ilosc_wsp-1;
    while(indeks >= 0){
        wynik = wynik * argument;
        wynik = wynik + wielomian [indeks];

        indeks = indeks - 1; 
    }
    cout << wynik << endl;

    return 0;
}