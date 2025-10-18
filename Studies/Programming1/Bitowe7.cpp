//Karol Dziekan
#include <iostream>

using namespace std;

short int Xor (short int liczba1,short int liczba2){
    return ((~(liczba1 & liczba2)) & (liczba1 | liczba2));
}

int main(){
    
    short int liczba1 = 0;
    short int liczba2 = 0;

    cin >> liczba1 >> liczba2;

    cout << Xor(liczba1,liczba2);
    return 0;
}