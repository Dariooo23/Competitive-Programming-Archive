//Karol Dziekan
#include <iostream>

using namespace std;

void Cardinality (int zbior [], int *rozmiar){
    int indeks = 0;
    while(zbior [indeks] != -1){
        indeks++;
    }

    *rozmiar = indeks;
    return;
}

void sortuj (int zbior []){
    if(zbior [0] == -1){
        return;
    }

    int rozmiar = 0;
    Cardinality (zbior, &rozmiar);
    rozmiar--;

    int indeks1 = 0;
    int indeks2 = 0;
    int zamiana = 0;

    while(indeks1 < rozmiar){
        indeks2 = 0;
        while(indeks2 < rozmiar - indeks1){
            if(zbior [indeks2] > zbior [indeks2 + 1]){
                zamiana = zbior [indeks2];
                zbior [indeks2] = zbior [indeks2 + 1];
                zbior [indeks2 + 1] = zamiana;
            }
            indeks2++;
        }
        indeks1++;
    }

    return;
}

bool Element (int liczba, int zbior []){
    if(liczba <= 4095 && liczba >= 1 && zbior [0] != -1){
        int indeks1 = 0;

        while(zbior [indeks1] != liczba && zbior [indeks1] != -1){
            indeks1++;
        }

        if(zbior [indeks1] == liczba){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Add (int liczba, int zbior []){
    if(liczba <= 4095 && liczba >= 1){
        int indeks1 = 0;

        while(zbior [indeks1] != liczba && zbior [indeks1] != -1){
            indeks1++;
        }

        if (zbior [indeks1] != liczba && !Element(liczba, zbior)){
            zbior [indeks1] = liczba;
            zbior [indeks1 + 1] = -1;
        }
    }

    sortuj(zbior);
    return;
}

void Create (int rozmiar, int elementy [], int zbior []){
    int indeks1 = 0;
    int indeks2 = 0;

    while(indeks1 < rozmiar){
        zbior [indeks2] = -1;
        if(elementy [indeks1] <= 4095 && elementy[indeks1] >= 1 && Element(elementy [indeks1],zbior) == 0){
            zbior [indeks2] = elementy [indeks1];
            indeks2++;
        }

        indeks1++;
    }

    zbior [indeks2] = -1;
    sortuj(zbior);
    return;
}

void Complement (int zbior1 [], int zbior_wynik []){
    int indeks1 = 1;
    int indeks2 = 0;

    while(indeks1 <= 4095){
        if(Element(indeks1, zbior1) == 0){
            zbior_wynik [indeks2] = indeks1;
            indeks2++;
        }
        indeks1++;
    }

    zbior_wynik [indeks2] = -1;
    sortuj(zbior_wynik);
    return;
}

void Union (int zbior1 [], int zbior2 [], int zbior_wynik []){
    zbior_wynik [0] = -1;
    if(zbior1 [0] == -1 && zbior2 [0] == -1){
        return;
    }

    int indeks1 = 0;
    int indeks2 = 0;
    while(zbior1 [indeks1] != -1){
        if(zbior1 [indeks1] <= 4095 && zbior1 [indeks1] >= 1){
            if(Element(zbior1 [indeks1], zbior_wynik) == 0){
                zbior_wynik [indeks2] = zbior1 [indeks1];
                indeks2++;
                zbior_wynik [indeks2] = -1;
            }
        }
        indeks1++;
    }

    indeks1 = 0;
    while(zbior2 [indeks1] != -1){
        if(zbior2 [indeks1] <= 4095 && zbior2 [indeks1] >= 1){
            if(Element(zbior2 [indeks1], zbior_wynik) == 0){
                zbior_wynik [indeks2] = zbior2 [indeks1];
                indeks2++;
                zbior_wynik [indeks2] = -1;
            }
        }
        indeks1++;
    }

    sortuj(zbior_wynik);
    return;
}

void Intersection (int zbior1 [], int zbior2 [], int zbior_wynik []){
    int indeks1 = 0;
    int indeks2 = 0;

    while(zbior1 [indeks1] != -1){
        if(Element(zbior1 [indeks1], zbior2) == 1){
            zbior_wynik [indeks2] = zbior1 [indeks1];
            indeks2++;
        }
        indeks1++;
    }

    zbior_wynik [indeks2] = -1;
    sortuj(zbior_wynik);
    return;
}

void Difference (int zbior1 [], int zbior2 [], int zbior_wynik []){
    int indeks1 = 0;
    int indeks2 = 0;

    while(zbior1 [indeks1] != -1){
        if(Element(zbior1 [indeks1], zbior2) == 0){
            zbior_wynik [indeks2] = zbior1 [indeks1];
            indeks2++;
        }
        indeks1++;
    }

    zbior_wynik [indeks2] = -1;
    sortuj(zbior_wynik);
    return;
}

void Symmetric (int zbior1 [], int zbior2 [], int zbior_wynik []){
    int indeks1 = 0;
    int indeks2 = 0;

    while(zbior1 [indeks1] != -1){
        if(Element(zbior1 [indeks1], zbior2) == 0){
            zbior_wynik [indeks2] = zbior1 [indeks1];
            indeks2++;
        }
        indeks1++;
    }

    indeks1 = 0;
    while(zbior2 [indeks1] != -1){
        if(Element(zbior2 [indeks1], zbior1) == 0){
            zbior_wynik [indeks2] = zbior2 [indeks1];
            indeks2++;
        }
        indeks1++;
    }

    zbior_wynik [indeks2] = -1;
    sortuj(zbior_wynik);
    return;
}

bool Subset (int zbior1 [], int zbior2 []){
    int indeks = 0;
    while(zbior1 [indeks] != -1){
        if(Element(zbior1 [indeks], zbior2) == 0){
            return false;
        }
        indeks++;
    }

    return true;
}

bool Equal (int zbior1 [], int zbior2 []){
    if(Subset(zbior1, zbior2) == 1 && Subset(zbior2, zbior1) == 1){
        return true;
    }else{
        return false;
    }
}

bool Empty (int zbior []){
    if(zbior [0] == -1){
        return true;
    }else{
        return false;
    }
}

bool Nonempty (int zbior []){
    if(zbior [0] != -1){
        return true;
    }else{
        return false;
    }
}

double Arithmetic (int zbior []){
    if(zbior [0] == -1){
        return 0;
    }

    double srednia_aryt = 0;
    int indeks = 0;
    while(zbior [indeks] != -1){
        srednia_aryt = srednia_aryt + zbior [indeks];
        indeks++;
    }

    return (srednia_aryt / indeks);
}

double Harmonic (int zbior []){
    if(zbior [0] == -1){
        return 1;
    }

    double srednia_harm = 0;
    int indeks = 0;
    while(zbior [indeks] != -1){
        double liczba = zbior [indeks];
        srednia_harm = srednia_harm + (1 / liczba);
        indeks++;
    }

    double rozmiar = indeks;
    return (rozmiar / srednia_harm);
}

void MinMax (int zbior[], int *min, int &max){
    if(zbior [0] == -1){
        return;
    }

    int indeks = 1;

    *min = zbior [0];
    max = zbior [0];

    while(zbior [indeks] != -1){
        if(zbior [indeks] > max){
            max = zbior [indeks];
        }
        if(zbior [indeks] < *min){
            *min = zbior [indeks];
        }
        indeks++;
    }

    return;
}

void Properties (int zbior [], char operacje [], double &srednia_aryt, double *srednia_harm, int &min, int *max, int &rozmiar){
    int indeks = 0;
    while(operacje [indeks] != '\0'){
        if(operacje [indeks] == 'a'){
            srednia_aryt = Arithmetic(zbior);
        }
        if(operacje [indeks] == 'h'){
            *srednia_harm = Harmonic(zbior);
        }
        if(operacje [indeks] == 'm'){
            MinMax(zbior, &min, *max);
        }
        if(operacje [indeks] == 'c'){
            Cardinality(zbior, &rozmiar);
        }
        indeks++;
    }

    return;
}