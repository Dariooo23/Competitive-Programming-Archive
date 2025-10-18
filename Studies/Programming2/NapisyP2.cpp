//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void Znajdz_Liczby_Char(const char* liczba_napis){
    size_t dlugosc_napisu{strlen(liczba_napis)};

    int liczba = 0;
    int indeks = 0;
    int ilosc_liczb = 0;
    while (*(liczba_napis + indeks) != 0){
        if (isdigit(*(liczba_napis + indeks))){
            ilosc_liczb++;
        }
        indeks++;
    }

    char cyfry[ilosc_liczb];

    indeks = 0;
    int indeks2 = 0;
    while (*(liczba_napis + indeks) != 0){
        if (isdigit(*(liczba_napis + indeks))){
            cyfry[indeks2] = *(liczba_napis + indeks);
            indeks2++;
        }
        indeks++;
    }
    
    liczba = atoi(cyfry);

    if (liczba){
        cout << liczba;
    }else{
        cout << "Konwersja niemozliwa.";
    }

    cout << endl;
    return;
}

void Znajdz_Liczby_String(string liczba_napis){   
    string liczba_napis_cyfry = "";

    int dlugosc = liczba_napis.size();
    string::iterator liczba_napis_wskaznik = liczba_napis.begin();

    while(liczba_napis_wskaznik != liczba_napis.end()){
        if(isdigit(*liczba_napis_wskaznik)){
            liczba_napis_cyfry += *liczba_napis_wskaznik;
        }
        liczba_napis_wskaznik++;
    }

    const char* liczba_napis_char = liczba_napis_cyfry.c_str();

    int liczba = atoi(liczba_napis_char);

    if (liczba){
        cout << liczba;
    }else{
        cout << "Konwersja niemozliwa.";
    }

    cout << endl;
    return;
}

void Znaki_Interpunkcji(string interpunkcja){
    for (string::iterator it = interpunkcja.begin(); it != interpunkcja.end(); ++it){
        if (ispunct(*it)){
            cout << *it << " ";
        }
    }

    return;
}

void Wypisz_Tab_Iterator(){
    int tab_it[]{8,9,13,-1};

    for (int* it = begin(tab_it); it != end(tab_it); ++it){
        cout << *it << " ";
    }cout << endl;

    return;
}


void Porownaj_String(string napis){
    string napis_ustalony = "ToJestNapis";

    cout << "Porownywane napisy: " << napis_ustalony << " " << napis << endl;

    cout << "Porownanie z uwzglednieniem wielkosci liter: ";
    if (napis_ustalony < napis){
        cout << "Napis wprowadzony jest wiekszy";
    }else{
        if (napis_ustalony > napis){
            cout << "Napis ustalony jest wiekszy";
        }else{
            cout << "Napisy sa takie same";
        }
    }cout << endl;

    for (int i = 0; i < napis_ustalony.size(); i++){
        napis_ustalony[i] = tolower(napis_ustalony[i]);
    }
    for (int i = 0; i < napis_ustalony.size(); i++){
        napis[i] = tolower(napis[i]);
    }
    
    cout << "Porownanie bez uwzglednienia wielkosci liter: ";
    if (napis_ustalony < napis){
        cout << "Napis wprowadzony jest wiekszy";
    }else{
        if (napis_ustalony > napis){
            cout << "Napis ustalony jest wiekszy";
        }else{
            cout << "Napisy sa takie same";
        }
    }cout << endl;

    return;
}
int main(){
    const char* napis;
    //Znajdz_Liczby_Char(napis);
    //Znajdz_Liczby_String(napis);
    //Znaki_Interpunkcji(napis);

    //Wypisz_Tab_Iterator();

    string napis_string;
    cin >> napis_string;
    Porownaj_String(napis_string);
    return 0;
}


//strcpy_s
//strcat_s
//strcmp, gdy takie same to zwraca 0
//w zaleznosci co sie rozni zwraca < 0 lub > 0



//D
//D
//d
//15
//-1
//testow metod
//d
//prawda