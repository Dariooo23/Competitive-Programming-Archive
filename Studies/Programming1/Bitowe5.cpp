//Karol Dziekan
#include <iostream>

using namespace std;

unsigned short int Dodawanie_bitowe (unsigned short int liczba1, unsigned short int liczba2) {
    while (liczba2 != 0) {
        unsigned short int przeniesienie = liczba1 & liczba2; //Na kazdym indeksie sprawdza czy nalezy dodac 1 do kolejnego indeksu

        liczba1 = liczba1 ^ liczba2; //Dodanie liczby bez uwzglednienia ewentualnego przeniesienia z poprzednich indeksow

        liczba2 = przeniesienie << 1; //W aktualnej sumie nie uzwglednilismy przeniesien teraz to one staja sie nowa liczba do dodania
    }

    return liczba1;
}

int main(){

    unsigned short int liczba1 = 0;
    unsigned short int liczba2 = 0;

    cin >> liczba1 >> liczba2;

    cout << Dodawanie_bitowe(liczba1,liczba2);

    return 0;
}