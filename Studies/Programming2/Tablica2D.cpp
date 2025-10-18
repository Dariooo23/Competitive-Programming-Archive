//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

void wypelnij_tab_2D(int** tablica, int rozmiar1, int rozmiar2){
    for (int i = 0; i < rozmiar1; i++){
        int* tablica_wsk = *(tablica + i);
        for (int j = 0; j < rozmiar2; j++){
            *(tablica_wsk + j) = i * rozmiar2 + j;
        }
    }
    /*for (int i = 0; i < rozmiar1; i++){
        for (int j = 0; j < rozmiar2; j++){
            tablica[i][j] = i * rozmiar2 + j;
        }
    }*/

    return;
}

void wypisz_tab_2D(int** tablica, int rozmiar1, int rozmiar2){
    for (int i = 0; i < rozmiar1; i++){
        int* tablica_wsk = *(tablica + i);
        for (int j = 0; j < rozmiar2; j++){
            cout << *(tablica_wsk + j) << " ";
        }
        cout << endl;
    }
    /*for (int i = 0; i < rozmiar1; i++){
        for (int j = 0; j < rozmiar2; j++){
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }*/
    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int rozmiar1 = 0;
    int rozmiar2 = 0;

    cin >> rozmiar1 >> rozmiar2;

    int** tab = new int*[rozmiar1];

    for(int i = 0; i < rozmiar1; i++){
        tab[i] = new int[rozmiar2];
    }

    wypelnij_tab_2D(tab, rozmiar1, rozmiar2);
    wypisz_tab_2D(tab, rozmiar1, rozmiar2);


    for(int i = 0; i < rozmiar1; i++){
        delete[] tab[i];
    }
    delete[] tab;
    tab = nullptr;

    return 0;
}
