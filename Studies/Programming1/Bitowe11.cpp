//Karol Dziekan
#include <iostream>

using namespace std;

short int Dodawanie_bitowe (short int liczba1, short int liczba2) {
    while (liczba2 != 0) {
        short int przeniesienie = liczba1 & liczba2;

        liczba1 = liczba1 ^ liczba2;

        liczba2 = przeniesienie << 1;
    }

    return liczba1;
}

void Dodaj_statek (unsigned long long int* plansza_gracza, short int x, short int y){
    long long int bit = 1;
    *plansza_gracza |= (bit << Dodawanie_bitowe((x << 3),y));

    return;
}

void Zniszcz_statek (unsigned long long int* plansza_gracza, short int x, short int y, short int* ilosc_statkow){
    long long int bit = 1;
    short int minus_punkt = -1;
    short int przesuniecie = Dodawanie_bitowe((x << 3),y);

    if (*plansza_gracza & (bit << przesuniecie)){
        *plansza_gracza ^= (bit << przesuniecie);
        *ilosc_statkow = Dodawanie_bitowe(*ilosc_statkow,minus_punkt);
    }

    return;
}

void Wyswietl_plansze (unsigned long long int plansza_gracza){
    long long int bit = 1;
    for (short int i = 0; i < 8; i++){
        for (short int j = 0; j < 8; j++){
            short int przesuniecie = Dodawanie_bitowe((i << 3),j);
            cout << ((plansza_gracza & (bit << przesuniecie)) >> przesuniecie)<< " ";
        }
        cout << endl;
    }

    return;
}

int main(){

    short int ilosc_statkow = 2;
    unsigned long long int plansza_gracz1 = 0;
    unsigned long long int plansza_gracz2 = 0;
    short int x = 0;
    short int y = 0;

    //Ustawianie statkow 1 gracza
    cout << "Wczytywanie pozycji statkow gracza 1" << endl;
    for (int i = 0; i < ilosc_statkow; i++){
        cin >> x >> y;
        Dodaj_statek (&plansza_gracz1,x,y);
    }
    //Ustawianie statkow 2 gracza
    cout << "Wczytywanie pozycji statkow gracza 2" << endl;
    for (int i = 0; i < ilosc_statkow; i++){
        cin >> x >> y;
        Dodaj_statek (&plansza_gracz2,x,y);
    }

    //Faktyczna rozgrywka
    short int statki_gracza1 = ilosc_statkow;
    short int statki_gracza2 = ilosc_statkow;


    //Wyswietlenie plansz obu graczy przed rozpoczeciem rozgrywki
    cout << "Plansza gracza 1: " << endl;
    Wyswietl_plansze (plansza_gracz1);
    cout << endl;

    cout << "Plansza gracza 2: " << endl;
    Wyswietl_plansze (plansza_gracz2);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    while (statki_gracza1 != 0 && statki_gracza2 != 0){
        //Ruchy graczy

        //Ruch gracza 1
        cin >> x >> y;
        Zniszcz_statek (&plansza_gracz2,x,y,&statki_gracza2);

        //Ruch gracza 2
        cin >> x >> y;
        Zniszcz_statek (&plansza_gracz1,x,y,&statki_gracza1);

        //Wyswietlenie plansz obu graczy po wykonaniu swoich ruchow
        cout << "Plansza gracza 1: " << endl;
        Wyswietl_plansze (plansza_gracz1);
        cout << endl;

        cout << "Plansza gracza 2: " << endl;
        Wyswietl_plansze (plansza_gracz2);
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    }

    if (statki_gracza1 == 0 && statki_gracza2 == 0){
        cout << "Remis";
    }
    if (statki_gracza1 != 0 && statki_gracza2 == 0){
        cout << "Wygrywa gracz 1";
    }
    if (statki_gracza1 == 0 && statki_gracza2 != 0){
        cout << "Wygrywa gracz 2";
    }

    return 0;
}