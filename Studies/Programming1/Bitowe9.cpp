//Karol Dziekan
#include <iostream>

using namespace std;

void wypisywanie_bitowe (unsigned short int liczba){
    for (int i = 15; i >= 0; i--){
        cout << ((liczba & (1 << i)) >> i);
    }

    cout << endl;
    
    return;
}

bool Czy_ujemna (short int liczba1){
    return (liczba1 & (1 << 15));
}

int main(){

    short int liczba = 0;
    
    cin >> liczba;

    wypisywanie_bitowe (liczba);
    cout << Czy_ujemna (liczba);
    
    return 0;
}