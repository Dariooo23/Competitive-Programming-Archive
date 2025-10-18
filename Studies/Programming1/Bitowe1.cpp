//Karol Dziekan
#include <iostream>

using namespace std;

void wypisywanie_bitowe (short int liczba){
    for (int i = 15; i >= 0; i--){
        cout << ((liczba & (1 << i)) >> i);
    }

    cout << endl;
    
    return;
}

short int Zlicz_1(short int liczba_g) {
    short int licznik = 0;

    for (short int liczba_p = liczba_g; liczba_p != 0; liczba_p >>= 1) {
        licznik += (liczba_p & 1);
    }

    return licznik;
}

int main(){

    short int liczba = 0;

    cin >> liczba;

    wypisywanie_bitowe (liczba);
    cout << Zlicz_1(liczba);

    return 0;
}