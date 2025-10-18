//Karol Dziekan
#include <iostream>

using namespace std;

int main(){

    int rozmiar_zbior1 = 0;
    cin >> rozmiar_zbior1;
    int zbior1 [rozmiar_zbior1];

    int zbior3 [100009];
    int zliczanie_liczb [100009];

    int indeks_wej = 0;
    int indeks_pom = 0;
    int indeks_maks = 0;
    int indeks_wyj = 0;

    while(indeks_wej < rozmiar_zbior1){
        cin >> zbior1 [indeks_wej];

        if(zbior1 [indeks_wej] >= 0){
            indeks_pom = zbior1 [indeks_wej] * 2;
            zliczanie_liczb [indeks_pom] = zliczanie_liczb [indeks_pom] + 1;

            if(indeks_pom > indeks_maks)
                indeks_maks = indeks_pom;
        }else{
            indeks_pom = zbior1 [indeks_wej] * -1 * 2 - 1;
            zliczanie_liczb [indeks_pom] = zliczanie_liczb [indeks_pom] + 1;

            if(indeks_pom > indeks_maks)
                indeks_maks = indeks_pom;
        }

        indeks_wej = indeks_wej + 1;
    }

    int rozmiar_zbior2 = 0;
    cin >> rozmiar_zbior2;
    int zbior2 [rozmiar_zbior2];

    indeks_wej = 0;
    while(indeks_wej < rozmiar_zbior2){
        cin >> zbior2 [indeks_wej];

        if(zbior2 [indeks_wej] >= 0){
            indeks_pom = zbior2 [indeks_wej] * 2;
            zliczanie_liczb [indeks_pom] = zliczanie_liczb [indeks_pom] + 1;
        }else{

            indeks_pom = zbior2 [indeks_wej] * -1 * 2 - 1;
            zliczanie_liczb [indeks_pom] = zliczanie_liczb [indeks_pom] + 1;
        }

        indeks_wej = indeks_wej + 1;
    }

    indeks_pom = 0;
    while(indeks_pom <= indeks_maks){
        if(zliczanie_liczb [indeks_pom] == 1){
            if(indeks_pom % 2 == 0){
                zbior3 [indeks_wyj] = indeks_pom / 2;
                indeks_wyj = indeks_wyj + 1;
            }else{
                zbior3 [indeks_wyj] = (indeks_pom + 1) / 2 * -1;
                indeks_wyj = indeks_wyj +  1;
            }
        }

        indeks_pom = indeks_pom + 1;
    }

    if(indeks_wyj == 0){
        cout << "Zbior pusty";
    }else{
        indeks_pom = 0;
        while(indeks_pom < indeks_wyj){
            cout << zbior3[indeks_pom] << " ";
            indeks_pom = indeks_pom + 1;
        }
    }

    return 0;
}