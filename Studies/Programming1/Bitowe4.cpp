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

void Przesuniecie_lewo (short int* liczba, int przesuniecie) {
    przesuniecie %= 16;
    
    *liczba = (*liczba << przesuniecie) | (*liczba >> (16 - przesuniecie ));
    return;
}

int main(){

    short int liczba = 0;

    cin >> liczba;

    int przesuniecie = 0;

    cin >> przesuniecie;

    wypisywanie_bitowe (liczba);
    Przesuniecie_lewo (&liczba,przesuniecie);
    wypisywanie_bitowe (liczba);
    return 0;
}