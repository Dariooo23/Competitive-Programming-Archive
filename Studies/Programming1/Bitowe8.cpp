//Karol Dziekan
#include <iostream>

using namespace std;

void Wlasny_swap (int* liczba1, int* liczba2){
    *liczba1 = *liczba1 ^ *liczba2;
    *liczba2 = *liczba1 ^ *liczba2;
    *liczba1 = *liczba1 ^ *liczba2;

    return;
}
int main(){

    int liczba1 = 0;
    int liczba2 = 0;

    cin >> liczba1 >> liczba2;

    cout << liczba1 << " " << liczba2 << endl;
    Wlasny_swap (&liczba1,&liczba2);
    cout << liczba1 << " " << liczba2 << endl;
    
    return 0;
}