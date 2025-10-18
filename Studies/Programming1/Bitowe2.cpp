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

void Parzystosc (short int* liczba_g) {
    short int licznik = 0;
    short int pozycja_zero = -1;

    for (short int pozycja = 0; pozycja < 16; pozycja++) {
        if (*liczba_g & (1 << pozycja)){
            licznik++;
        }else{
            if (pozycja_zero == -1){
                pozycja_zero = pozycja;
            }
        }
    }

    if (licznik % 2 == 1){
        *liczba_g ^= (1 << pozycja_zero);
    }

    return;
}

int main(){

    short int liczba = 0;


    cin >> liczba;

    wypisywanie_bitowe (liczba);
    Parzystosc (&liczba);
    wypisywanie_bitowe (liczba);

    

    return 0;
}