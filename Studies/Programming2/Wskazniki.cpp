//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void funkcja1(){
    const int rozmiar = 4;
    int tab_int [rozmiar] = {4,5,0,13};

    int* tab_wskaznikow [rozmiar];

    for (int i = 0; i < rozmiar; i++){
        tab_wskaznikow[i] = &tab_int[i];
    }

    for (int i = 0; i < rozmiar; i++){
        cout << *tab_wskaznikow[i];
    }

    return;
}

void funkcja2(){
    int tab[] = {1,2,3};
    int ile = 0;
    
    for(int x : tab)ile++;

    cout << ile;
    
    return;
}

int funkcja3(int* tab, int rozmiar){
    int suma = 0;
    while(rozmiar--)suma += *(tab+rozmiar);
    return suma;
}
int funkcja3_rek(int* tab, int rozmiar){
    return (rozmiar == 0) ? (funkcja3_rek(tab, rozmiar - 1) + *(tab + rozmiar)) : 0;
}

double tab_trzy_funk[3];
double* trzy_elementy_globalnie(double tab[], unsigned int rozmiar){
    if (3 > rozmiar){
        cout << "Tablica ma mniej niz trzy elementy" << endl;
        return nullptr;
    }

    tab_trzy_funk[0] = tab[0];
    tab_trzy_funk[1] = tab[1];
    tab_trzy_funk[2] = tab[2];
    return tab_trzy_funk;
}

double tab_trzy[3];
void trzy_elementy_dodatkowy_parametr(double tab[], unsigned int rozmiar, double tab_trzy[3]){
    if (3 > rozmiar){
        cout << "Tablica ma mniej niz trzy elementy" << endl;
    }

    tab_trzy[0] = tab[0];
    tab_trzy[1] = tab[1];
    tab_trzy[2] = tab[2];
}

double* trzy_elementy_new(double tab[], unsigned int rozmiar){
    if (3 > rozmiar){
        cout << "Tablica ma mniej niz trzy elementy" << endl;
        return nullptr;
    }

    double* tab_trzy_wsk = new double[3];
    *(tab_trzy_wsk + 0) = tab[0];
    *(tab_trzy_wsk + 1) = tab[1];
    *(tab_trzy_wsk + 2) = tab[2];
    return tab_trzy_wsk;
}

void wypisz_dwuwymiarowa(float tab[][3], int rozmiar1){
    for (int i = 0; i < rozmiar1; i++){
        float* j = tab[i];
        while (j != end(tab[i])){
            cout << *j << " ";
            j++;
        }cout << endl;
    }

    return;
}

// void wypelnij_ref(){
//     const int rozmiar = 4;
//     int tab_int[rozmiar] = {4,5,0,13};
//     int& tab_ref[rozmiar];
// }

int main(){

    float tab[3][3] = {{1,2,3},{1,2,3},{1,2,3}};

    wypisz_dwuwymiarowa(tab,3);
    return 0;
}


//00FBF910
//10.0
//00FBF920
//00FBF920
//20.0

//3 3 1 3 adres(m)
