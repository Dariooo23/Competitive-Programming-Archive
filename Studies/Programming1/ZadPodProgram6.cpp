//Karol Dziekan
#include <iostream>

using namespace std;

void kodowanie_uzupelnieniowe (int ile_znakow, char liczba []){
    if (liczba [0] == '-'){
        liczba [0] = '9';
        for (int i = 1; i < ile_znakow; i++){
            liczba [i] = '9' - liczba [i] + '0';
        }

        int indeks = ile_znakow - 1;
        while (indeks >= 0 && liczba [indeks] == '9'){
            liczba [indeks] = '0';
            indeks--;
        }
        if (indeks >= 0){
            liczba [indeks] += 1;
        }
    }else{
            liczba [0] = '0';
    }
}

void suma_liczb (int ile_znakow1, char liczba1 [], int ile_znakow2, char liczba2 [], int &ile_znakow3, char liczba3 []){
    //Dodanie znaku + w przypadku dodatnich
    if (liczba1 [0] != '-'){
        for (int i = ile_znakow1; i >= 1; i--){
                liczba1 [i] = liczba1 [i - 1];
            }
        liczba1 [0] = '+';
        ile_znakow1++;
    }
    if (liczba2 [0] != '-'){
        for (int i = ile_znakow2; i >= 1; i--){
                liczba2 [i] = liczba2 [i - 1];
            }
        liczba2 [0] = '+';
        ile_znakow2++;
    }

    if (ile_znakow1 > ile_znakow2){
        ile_znakow3 = ile_znakow1;
    }else{
        ile_znakow3 = ile_znakow2;
    }

    char liczba_uzupelnieniowa1 [ile_znakow3 + 1] = {};
    char liczba_uzupelnieniowa2 [ile_znakow3 + 1] = {};

    //Normalizacja dlugosci rejestru obu liczb
    if (ile_znakow1 > ile_znakow2){
        for(int i = 0; i <= ile_znakow1; i++){
            liczba_uzupelnieniowa1 [i] = liczba1 [i];
        }

        int poczatek = 0;
        liczba_uzupelnieniowa2 [0] = liczba2 [poczatek];
        poczatek++;

        int przesuniecie = ile_znakow1 - ile_znakow2;
        for (int i = poczatek; i <= ile_znakow3; i++){
            liczba_uzupelnieniowa2 [i] = '0';
        }
        for (int i = poczatek; i <= ile_znakow2; i++){
            liczba_uzupelnieniowa2 [i + przesuniecie] = liczba2 [i];
        }
    }else{
        for(int i = 0; i <= ile_znakow2; i++){
            liczba_uzupelnieniowa2 [i] = liczba2 [i];
        }

        int poczatek = 0;
        liczba_uzupelnieniowa1 [0] = liczba1 [poczatek];
        poczatek++;

        int przesuniecie = ile_znakow2 - ile_znakow1;
        for (int i = poczatek; i < ile_znakow3; i++){
            liczba_uzupelnieniowa1 [i] = '0';
        }
        for (int i = poczatek; i <= ile_znakow1; i++){
            liczba_uzupelnieniowa1 [i + przesuniecie] = liczba1 [i];
        }
    }

    //Kodowanie obu liczb
    kodowanie_uzupelnieniowe (ile_znakow3, liczba_uzupelnieniowa1);
    kodowanie_uzupelnieniowe (ile_znakow3, liczba_uzupelnieniowa2);

    //Dodanie kodow obu liczb
    int przesuniecie = 0;
    for (int i = ile_znakow3; i >= 0 ; i--){
        if (liczba_uzupelnieniowa1 [i] != 0 || liczba_uzupelnieniowa2 [i] != 0){
            liczba3 [i] = liczba_uzupelnieniowa1 [i] - '0' + liczba_uzupelnieniowa2 [i] - '0' + przesuniecie;
            if (liczba3 [i] >= 10){
                przesuniecie = 1;
                liczba3 [i] -= 10;
            }else{
                przesuniecie = 0;
            }
            liczba3 [i] += '0';
        }
    }

    //Dekodowanie liczby
    if (liczba3 [0] == '9'){
        liczba3 [0] = '-';
        int indeks = ile_znakow3 - 1;
        while (indeks >= 1 && liczba3 [indeks] == '0'){
            liczba3 [indeks] = '9';
            indeks--;
        }
        liczba3 [indeks] -= 1;

        for (int i = 1; i < ile_znakow3; i++){
            liczba3 [i] = '9' - liczba3 [i] + '0';
        }

    }else{
        for (int i = 0; i <= ile_znakow3; i++){
            liczba3 [i] = liczba3 [i + 1];
        }
    }
}

int main(){

    int ile_znakow1 = 0;

    cin >> ile_znakow1;

    char liczba1 [ile_znakow1 + 1] = {};

    cin >> liczba1;

    int ile_znakow2 = 0;
    
    cin >> ile_znakow2;

    char liczba2 [ile_znakow2 + 1] = {};

    cin >> liczba2;

    int ile_znakow3 = 0;

    if (ile_znakow1 > ile_znakow2){
        ile_znakow3 = ile_znakow1 + 1;
    }else{
        ile_znakow3 = ile_znakow2 + 1;
    }

    char liczba3 [ile_znakow3] = {};

    suma_liczb (ile_znakow1, liczba1, ile_znakow2, liczba2, ile_znakow3, liczba3);

    cout << ile_znakow3 << " " << liczba3;
    return 0;
}