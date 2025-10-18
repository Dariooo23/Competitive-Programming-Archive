//Karol Dziekan
#include <iostream>

using namespace std;

int rozmiar_szescianu = 0;
int tablica_szescianu [32][32][32] = {};
int centrum_szescianu = 0;

void Przeciecie (int l, int v, int p, int dl1, int dl2, int dl3, int operacja){
    int suma = 0;
    int flaga_poziom = 0;
    int flaga_pion = 0;
    int flaga_panel = 0;
    int flaga_glowna = 0;

    int dlugosc_poziom = 0;
    int dlugosc_pion = 0;
    int dlugosc_panel = 0;

    for (int d_s = 0; d_s < rozmiar_szescianu; d_s++){
        for (int h_s = 0; h_s < rozmiar_szescianu; h_s++){
            for (int w_s = 0; w_s < rozmiar_szescianu; w_s++){
                flaga_poziom = 0;
                flaga_pion = 0;
                flaga_panel = 0;
                flaga_glowna = 0;

                if (l >= centrum_szescianu){
                    if (h_s <= l && h_s >= (l - dl1))
                        flaga_poziom = 1;
                }else{
                    if (h_s <= (l + dl1) && h_s >= l)
                        flaga_poziom = 1;
                }
                if (v >= centrum_szescianu){
                    if (w_s <= v && w_s >= (v - dl2))
                        flaga_pion = 1;
                }else{
                    if (w_s <= (v + dl2) && w_s >= v)
                        flaga_pion = 1;
                }
                if (p >= centrum_szescianu){
                    if (d_s <= p && d_s >= (p - dl3))
                        flaga_panel = 1;
                }else{
                    if (d_s <= (p + dl3) && d_s >= p)
                        flaga_panel = 1;
                }

                if (operacja != 'C'){
                    dlugosc_poziom = h_s - l;
                    if (dlugosc_poziom < 0) dlugosc_poziom *= -1;
                    dlugosc_pion = w_s - v;
                    if (dlugosc_pion < 0) dlugosc_pion *= -1;
                    dlugosc_panel = d_s - p;
                    if (dlugosc_panel < 0) dlugosc_panel *= -1;
                }

                if (operacja == 'C'){
                    flaga_glowna = 1;
                }
                if ((dlugosc_poziom + dlugosc_pion + dlugosc_panel <= dl1) && (operacja == 'T')){
                    flaga_glowna = 1;
                }
                if ((dlugosc_poziom * dlugosc_poziom + dlugosc_pion * dlugosc_pion + dlugosc_panel * dlugosc_panel <= dl1 * dl1) && (operacja == 'O')){
                    flaga_glowna = 1;
                }

                if (flaga_poziom == 1 && flaga_pion == 1 && flaga_panel == 1 && flaga_glowna == 1){
                    suma = suma + tablica_szescianu [h_s][w_s][d_s];
                }
            }
        }
    }

    cout << suma << endl;
    return;
}

long long int Wyznacznik_Rek (long long int macierz [32][32], int rozmiar){
    if (rozmiar == 1){
        return macierz [0][0];
    }else{
        //Opt zeby nie schodzic az do rozmiaru 1
        if (rozmiar == 2){
            return macierz [0][0] * macierz [1][1] - macierz [0][1] * macierz [1][0];
        }

        //Sprawdzenie czy sa trojkatne
        bool flaga1 = 1;
        bool flaga2 = 1;
        for (int i = 0; i < rozmiar; i++){
            for (int j = i + 1; j < rozmiar; j++){
                if (macierz [i][j] != 0)
                    flaga1 = 0;
            }
        }
        for (int i = 0; i < rozmiar; i++){
            for (int j = i - 1; j >= 0; j--){
                if (macierz [i][j] != 0){
                    flaga2 = 0;
                }
            }
        }

        if (flaga1 || flaga2){
            int wyznacznik = 1;
            for (int i = 0; i < rozmiar; i++){
                wyznacznik *= macierz [i][i];
            }

            return wyznacznik;
        }

        //Sprawdzenie czy sa dwie takie same kolumny/wiersze
        for (int i = 0; i < rozmiar; i++){
            for (int j = i + 1; j < rozmiar; j++){
                //Wiersze
                flaga1 = 1;
                for (int k = 0; k < rozmiar; k++){
                    if (macierz [i][k] != macierz [j][k]){
                        flaga1 = 0;
                    }
                }
                if (flaga1 == 1){
                    return 0;
                }

                //Kolumny
                flaga1 = 1;
                for (int k = 0; k < rozmiar; k++){
                    if (macierz [k][i] != macierz [k][j]){
                        flaga1 = 0;
                    }
                }
                if (flaga1 == 1){
                    return 0;
                }
            }
        }

        //Nie sa trojkatne i nie ma dwoch takich samych wierszy/kolumn, liczenie z Laplace'a

        long long int suma_glowna = 0;
        long long int suma_poboczna = 0;

        int indeks1 = 0;
        int indeks2 = 0;
        long long int podmacierz [32][32] = {};

        for (int k = 0; k < rozmiar; k++){
            if(macierz [0][k] != 0){
                suma_poboczna = 0;
                indeks1 = 0;
                for (int i = 1; i < rozmiar; i++){
                    indeks2 = 0;
                    for (int j = 0; j < rozmiar; j++){
                        if (j != k){
                            podmacierz [indeks1][indeks2] = macierz [i][j];
                            indeks2++;
                        }
                    }
                    indeks1++;
                }
                suma_poboczna = macierz [0][k] * Wyznacznik_Rek (podmacierz, rozmiar - 1);
                if(k % 2 == 1){
                    suma_poboczna *= -1;
                }
                suma_glowna += suma_poboczna;
            }
        }
        return suma_glowna;
    }
}

void Wyznacznik (char k, int indeks){
    long long int macierz [32][32];

    if (k == 'l'){
        for (int i = 0; i < rozmiar_szescianu; i++){
            for (int j = 0; j < rozmiar_szescianu; j++){
                macierz [i][j] = tablica_szescianu [indeks][i][j];
            }
        }
    }else{
        if (k == 'v'){
            for (int i = 0; i < rozmiar_szescianu; i++){
                for (int j = 0; j < rozmiar_szescianu; j++){
                    macierz [i][j] = tablica_szescianu [i][indeks][j];
                }
            }
        }else{
            for (int i = 0; i < rozmiar_szescianu; i++){
                for (int j = 0; j < rozmiar_szescianu; j++){
                    macierz [i][j] = tablica_szescianu [i][j][indeks];
                }
            }
        }
    }


    cout << Wyznacznik_Rek (macierz, rozmiar_szescianu) << endl;
}

int main(){
    
    cin >> rozmiar_szescianu;

    centrum_szescianu = rozmiar_szescianu / 2;

    for (int d = 0; d < rozmiar_szescianu; d++){
        for (int h = 0; h < rozmiar_szescianu; h++){
            for (int w = 0; w < rozmiar_szescianu; w++){
                cin >> tablica_szescianu [h][w][d];
            }
        }
    }

    int arg1 = 0;
    int arg2 = 0;
    int arg3 = 0;
    int arg4 = 0;
    int arg5 = 0;
    int arg6 = 0;
    char arg7 = 0;
    char operacja = 'A';

    while (operacja != 'E'){
        cin >> operacja;

        if (operacja == 'C'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5 >> arg6;
            Przeciecie (arg1,arg2,arg3,arg4,arg5,arg6,operacja);
        }else{
            if (operacja == 'T'){
                cin >> arg1 >> arg2 >> arg3 >> arg4;
                Przeciecie (arg1,arg2,arg3,arg4,arg4,arg4,operacja);
            }else{
                if (operacja == 'O'){
                    cin >> arg1 >> arg2 >> arg3 >> arg4;
                    Przeciecie (arg1,arg2,arg3,arg4,arg4,arg4,operacja);
                }else{
                    if (operacja == 'D'){
                        cin >> arg7 >> arg1;
                        Wyznacznik (arg7,arg1);
                    }
                }
            }
        }
    }


    return 0;
}