//Karol Dziekan
#include <iostream>

using namespace std;

short int Dodawanie_bitowe (short int liczba1,short int liczba2) {
    while (liczba2 != 0) {
        short int przeniesienie = liczba1 & liczba2; //Na kazdym indeksie sprawdza czy nalezy dodac 1 do kolejnego indeksu

        liczba1 = liczba1 ^ liczba2; //Dodanie liczby bez uwzglednienia ewentualnego przeniesienia z poprzednich indeksow

        liczba2 = przeniesienie << 1; //W aktualnej sumie nie uzwglednilismy przeniesien teraz to one staja sie nowa liczba do dodania
    }

    return liczba1;
}

void Mnozenie_3_5 (short int* liczba){
    *liczba = Dodawanie_bitowe((*liczba << 1),Dodawanie_bitowe(*liczba,(*liczba >> 1)));
}

int main(){
    
    short int liczba = 0;

    cin >> liczba;

    Mnozenie_3_5(&liczba);

    return 0;
}