//Karol Dziekan
#include <iostream>

using namespace std;

void konwersja_liczby  (char liczba [], int ile_znakow,
                        int system_liczbowy1, int system_liczbowy2,
                        int* ile_znakow2, char liczba2 []){
    int wartosc_dziesietna = 0;
    int potega = 1;

    int czy_ujemna = 0;
    if(liczba [0] == '-'){
        czy_ujemna = 1;
    }

    int przesuniecie = 0;
    if(czy_ujemna == 1){
        przesuniecie = 1;
    }

    //Zamiana z system_liczbowy1 na system dziesietny
    int indeks = ile_znakow - 1;
    while (indeks >= przesuniecie){
        char cyfra = liczba [indeks];
        int wartosc = 0;

        if(cyfra >= '0' && cyfra <= '9'){
            wartosc = cyfra - '0';
        }else{
            if(cyfra >= 'A' && cyfra <= 'Z'){
                wartosc = cyfra - 'A' + 10;
            }
        }

        wartosc_dziesietna = wartosc_dziesietna + wartosc * potega;
        potega = potega * system_liczbowy1;
        indeks = indeks - 1;
    }

    if (wartosc_dziesietna == 0){
        *ile_znakow2 = 1;
        liczba2 [0] = '0';
        return;
    }

    int wartosc_dziesietna_kopia = wartosc_dziesietna;

    while (wartosc_dziesietna_kopia > 0){
        wartosc_dziesietna_kopia = wartosc_dziesietna_kopia / system_liczbowy2;
        (*ile_znakow2)++;
    }

    if(czy_ujemna == 1){
        (*ile_znakow2)++;
    }

    indeks = 0;
    while (wartosc_dziesietna > 0){
        int reszta = wartosc_dziesietna % system_liczbowy2;

        if(reszta < 10){
            liczba2 [*ile_znakow2 - indeks - 1] = '0' + reszta;
        }else{
            liczba2 [*ile_znakow2 - indeks - 1] = 'A' + reszta - 10;
        }

        indeks = indeks + 1;
        wartosc_dziesietna = wartosc_dziesietna / system_liczbowy2;
    }

    if(czy_ujemna == 1){
        liczba2 [0] = '-';
    }

    return;
}

int main(){
    int ile_znakow1 = 0;

    cin >> ile_znakow1;

    char liczba1 [ile_znakow1] = {};

    int indeks = 0;

    while (indeks < ile_znakow1){
        cin >> liczba1 [indeks];
        indeks = indeks + 1;
    }

    int system_liczbowy1 = 0;
    int system_liczbowy2 = 0;

    cin >> system_liczbowy1 >> system_liczbowy2;

    int ile_znakow2 = 0;
    char liczba2 [100009] = {};

    konwersja_liczby (liczba1, ile_znakow1, system_liczbowy1, system_liczbowy2, &ile_znakow2, liczba2);

    indeks = 0;
    while(indeks < ile_znakow2){
        cout << liczba2 [indeks];
        indeks++;
    }

    return 0;
}