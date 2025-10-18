// Karol Dziekan
#include <string>

using namespace std;

string NajwiekszeSlowo(string napis){
    string slowo, najwieksze;
    int start = 0;
    int koniec = 0;
    
    while (start < napis.size()){
        while (start < napis.size() && napis[start] == ' '){
            start++;
        }
        koniec = start;
        
        slowo.resize(0);

        while (koniec < napis.size() && napis[koniec] != ' '){
            slowo += napis[koniec];
            koniec++;
        }
        if (najwieksze.size() == 0){
            najwieksze = slowo;
        }
        if (slowo > najwieksze) {
            najwieksze = slowo;
        }
        start = koniec;
    }
    
    return najwieksze;
}

string NormalizujNapis(string napis){
    string wynik = napis;
    int dlugosc = napis.size();

    // Usuwanie spacji z przodu
    int poczatek = 0;
    while (wynik[poczatek] == ' '){
        poczatek++;
    }
    for (int i = 0; i < dlugosc - poczatek; i++){
        wynik[i] = wynik[i + poczatek];
    }
    dlugosc -= poczatek;
    wynik.resize(dlugosc);

    // Usuwanie spacji z tylu
    while (wynik[dlugosc - 1] == ' '){
        dlugosc--;
    }
    wynik.resize(dlugosc);

    // Usuwanie powtarzajacych sie spacji
    for (int i = 0; i < dlugosc; i++){
        if (wynik[i] == ' '){
            int indeks = i + 1;
            while (wynik[indeks] == ' '){
                wynik[indeks] = '#';
                indeks++;
            }
            // Przypadek usuwania spacji przed kropka i przecinkiem
            if (wynik[indeks] == '.' || wynik[indeks] == ','){
                wynik[i] = '#';
            }
            i = indeks;
        }
    }
    int indeks = 0;
    for (int i = 0; i < dlugosc; i++){
        if (wynik[i] == '#'){
            indeks++;
        }else{
            wynik[i - indeks] = wynik[i];
        }
    }
    dlugosc -= indeks;
    wynik.resize(dlugosc);

    // Dodawanie spacji po kropce i przecinku
    int przesuniecie = 0;
    for (int i = 0; i < dlugosc - 1; i++){
        if (wynik[i] == '.' || wynik[i] == ','){
            if (i + 1 != dlugosc){
                if (wynik[i + 1] != ' '){
                    przesuniecie++;
                }
            }
        }
    }
    dlugosc += przesuniecie;
    wynik.resize(dlugosc);

    indeks = 0;
    for (int i = dlugosc - 1; i >= przesuniecie; i--){
        wynik[i - indeks] = wynik[i - przesuniecie];

        if ((wynik[i - przesuniecie] == '.' || wynik[i - przesuniecie] == ',') && i != dlugosc - 1){
            if (wynik [i - przesuniecie + 1] != ' '){
                wynik[i - indeks] = ' ';
                indeks++;
                wynik[i - indeks] = wynik [i - przesuniecie];
            }
        }
    }

    return wynik;
}

string UsunSlowo(string napis, int numer){
    string wynik = napis;
    int dlugosc = wynik.size();
    int licznik = 0;
    int flaga = 0;
    int indeks = -1;

    for (int i = 0; i < dlugosc; i++){
        if (wynik[i] != ' '){
            if (flaga == 0){
                licznik++;
                flaga = 1;
            }
        }else{
            flaga = 0;
        }

        if (licznik == numer){
            indeks = i;
            break;
        }
    }

    if (indeks == -1){
        return wynik;
    }
    
    while (wynik[indeks] != ' '  && indeks < dlugosc){
        wynik[indeks] = '#';
        indeks++;
    }

    int przesuniecie = 0;
    for (int i = 0; i < dlugosc; i++){
        if (wynik[i] == '#'){
            przesuniecie++;
        }else{
            wynik[i - przesuniecie] = wynik[i];
        }
    }

    dlugosc -= przesuniecie;
    wynik.resize(dlugosc);

    return wynik;
}

string FormatujNapis(string napis_g, string napis_1, string napis_2, string napis_3){
    string wynik = napis_g;
    int dlugosc = wynik.size();

    for (int i = 0; i < dlugosc; i++){
        if (wynik[i] == '{'){
            char typ_polecenia = wynik[i + 1];
            int arg1 = 0;
            int arg2 = 0;

            string lewo = "";
            string prawo = "";

            if (typ_polecenia == 'p'){
                arg1 = wynik[i + 3] - '0';
                arg2 = wynik[i + 5];
            }
            else{
                if (typ_polecenia == 'W'){
                    arg1 = wynik[i + 3] - '0';
                    arg2 = wynik[i + 5] - '0';
                }
                else{
                    arg1 = wynik[i + 3] - '0';
                }
            }

            if (typ_polecenia == 'p'){
                for (int j = 0; j < i; j++){
                    lewo += wynik[j];
                }
                for (int j = i + 7; j < dlugosc; j++){
                    prawo += wynik[j];
                }

                string sekwencja = "";
                for (int j = 0; j < arg1; j++){
                    sekwencja += (char)arg2;
                }

                int zmiana_dlugosci = arg1 - 7;
                dlugosc += zmiana_dlugosci;
                wynik.resize(dlugosc);

                wynik = lewo + sekwencja + prawo;
            }
            if (typ_polecenia == 'u'){
                for (int j = 0; j < i; j++){
                    lewo += wynik[j];
                }
                for (int j = i + 5 + arg1; j < dlugosc; j++){
                    prawo += wynik[j];
                }

                int zmiana_dlugosc = dlugosc - lewo.size() - prawo.size();
                dlugosc -= zmiana_dlugosc;
                wynik.resize(dlugosc);

                wynik = lewo + prawo;
                i = i - 1;
            }
            if (typ_polecenia == 'U'){
                for (int j = 0; j < i - arg1; j++){
                    lewo += wynik[j];
                }
                for (int j = i + 5; j < dlugosc; j++){
                    prawo += wynik[j];
                }

                int zmiana_dlugosc = dlugosc - lewo.size() - prawo.size();
                dlugosc -= zmiana_dlugosc;
                wynik.resize(dlugosc);

                wynik = lewo + prawo;
                i = i - arg1 - 1;
            }
            if (typ_polecenia == 'w'){
                for (int j = 0; j < i; j++){
                    lewo += wynik[j];
                }
                for (int j = i + 5; j < dlugosc; j++){
                    prawo += wynik[j];
                }

                string napis = "";
                if (arg1 == 1){
                    napis = napis_1;
                }
                if (arg1 == 2){
                    napis = napis_2;
                }
                if (arg1 == 3){
                    napis = napis_3;
                }

                int zmiana_dlugosc = napis.size() - 5;
                dlugosc += zmiana_dlugosc;
                wynik.resize(dlugosc);

                wynik = lewo + napis + prawo;
                i = i - 1;
            }
            if (typ_polecenia == 'W'){
                for (int j = 0; j < i; j++){
                    lewo += wynik[j];
                }
                for (int j = i + 7; j < dlugosc; j++){
                    prawo += wynik[j];
                }

                string napis = "";
                if (arg1 == 1){
                    napis = napis_1;
                }
                if (arg1 == 2){
                    napis = napis_2;
                }
                if (arg1 == 3){
                    napis = napis_3;
                }

                if (napis.size() >= arg2){
                    napis.resize(arg2);
                }else{
                    int rozmiar = napis.size();
                    napis.resize(arg2);
                    for (int j = rozmiar; j < arg2; j++){
                        napis[j] = ' ';
                    }
                }

                int zmiana_dlugosc = napis.size() - 7;
                dlugosc += zmiana_dlugosc;
                wynik.resize(dlugosc);

                wynik = lewo + napis + prawo;
                i = i - 1;
            }
        }
    }

    return wynik;
}

