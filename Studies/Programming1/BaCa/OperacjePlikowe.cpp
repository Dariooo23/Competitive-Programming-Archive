//Karol Dziekan
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Skladowa{
    bool wartosc_bool;
    unsigned int wartosc_char;
    float wartosc_float;
};
struct Dana{
    int wartosc_int;
    string napis;
    string znak;
    Skladowa skladowa1,skladowa2,skladowa3,skladowa4;
};



int Ile_zestawow(string nazwa_plik){
    fstream plik;
    plik.open(nazwa_plik.c_str(), fstream::in);

    string linia = "";
    int ilosc_lini = 0;

    while (getline(plik, linia)){
        ilosc_lini++;
    }

    plik.close();
    return ilosc_lini / 7;
}



bool Porownaj_skladowe (Skladowa skladowa1, Skladowa skladowa2){
    if (skladowa1.wartosc_bool == skladowa2.wartosc_bool && skladowa1.wartosc_char == skladowa2.wartosc_char && skladowa1.wartosc_float == skladowa2.wartosc_float){
        return 1;
    }else{
        return 0;
    }
}
bool Porownaj_dane (Dana zestaw1, Dana zestaw2){
    if (zestaw1.wartosc_int == zestaw2.wartosc_int && zestaw1.napis == zestaw2.napis && zestaw1.znak == zestaw2.znak && Porownaj_skladowe(zestaw1.skladowa1, zestaw2.skladowa1) && Porownaj_skladowe(zestaw1.skladowa2, zestaw2.skladowa2) && Porownaj_skladowe(zestaw1.skladowa3, zestaw2.skladowa3) && Porownaj_skladowe(zestaw1.skladowa4, zestaw2.skladowa4)){
        return 1;
    }else{
        return 0;
    }
}
bool Czy_wystepuje(Dana zestaw_g, string nazwa_plik){
    fstream plik;
    plik.open (nazwa_plik.c_str(), fstream::in);

    Dana zestaw;
    while (plik >> zestaw.wartosc_int){
        getline(plik, zestaw.napis);
        getline(plik, zestaw.napis);
        getline(plik, zestaw.znak);
        plik >> zestaw.skladowa1.wartosc_bool >> zestaw.skladowa1.wartosc_char >> zestaw.skladowa1.wartosc_float;
        plik >> zestaw.skladowa2.wartosc_bool >> zestaw.skladowa2.wartosc_char >> zestaw.skladowa2.wartosc_float;
        plik >> zestaw.skladowa3.wartosc_bool >> zestaw.skladowa3.wartosc_char >> zestaw.skladowa3.wartosc_float;
        plik >> zestaw.skladowa4.wartosc_bool >> zestaw.skladowa4.wartosc_char >> zestaw.skladowa4.wartosc_float;

        if (Porownaj_dane(zestaw_g,zestaw)){
            plik.close();
            return 1;
        }
    }

    plik.close();
    return 0;
}
int Zlicz_Int(string nazwa_plik,int wartosc_int){
    fstream plik;

    plik.open(nazwa_plik.c_str(),fstream::in);

    int liczba = 0;
    int licznik = 0;

    while(plik >> liczba){
        if(liczba == wartosc_int){
            licznik++;
        }
    }

    plik.close();
    return licznik;
}
void Licznosc_Intow(string nazwa_plik1, string nazwa_plik2, string nazwa_plik3){
    fstream plik1, plik2, plik3;

    int ilosc_zestawow = Ile_zestawow(nazwa_plik1);
    int wartosc_int = 0;
    int pozycja = 0;

    string linia = "";
    Dana zestaw;

    plik1.open(nazwa_plik1.c_str(), fstream::in);
    plik3.open(nazwa_plik3.c_str(), fstream::out);
    while(plik1 >> zestaw.wartosc_int){
        for (int  i = 0; i < 7; i++){
            getline(plik1, linia);
        }

        plik3 << zestaw.wartosc_int << endl;
    }
    plik1.close();
    plik3.close();

    plik1.open(nazwa_plik1.c_str(), fstream::in);
    plik2.open(nazwa_plik2.c_str(),fstream::out);
    for (int i = 0; i < ilosc_zestawow; i++){
        plik1 >> wartosc_int;
        plik2 << wartosc_int << " " << Zlicz_Int(nazwa_plik3, wartosc_int) << endl;

        getline(plik1, linia);
        for (int i = 0; i < 6; i++){
            getline(plik1, linia);
            plik2 << linia << endl;
        }
    }
    plik1.close();
    plik2.close();

    plik2.open(nazwa_plik2.c_str(), fstream::in);
    plik1.open(nazwa_plik1.c_str(), fstream::out);
    while (getline(plik2, linia)){
        plik1 << linia << endl;
    }
    plik1.close();
    plik2.close();

    plik2.open(nazwa_plik2.c_str(),fstream::out);
    plik3.open(nazwa_plik3.c_str(),fstream::out);
    plik2.close();
    plik3.close();
    return;
}



void SymmetricDifference(string nazwa_plik1, string nazwa_plik2, string nazwa_plik3){
    fstream plik1;
    fstream plik2;
    fstream plik3;

    int ilosc_zestawow = Ile_zestawow(nazwa_plik2);

    plik2.open(nazwa_plik2.c_str(), fstream::in);
    plik3.open(nazwa_plik3.c_str(), fstream::out);

    Dana zestaw;

    
    for (int i = 0; i < ilosc_zestawow; i++){
        plik2 >> zestaw.wartosc_int;
        getline(plik2, zestaw.napis);
        getline(plik2, zestaw.napis);
        getline(plik2, zestaw.znak);
        plik2 >> zestaw.skladowa1.wartosc_bool >> zestaw.skladowa1.wartosc_char >> zestaw.skladowa1.wartosc_float;
        plik2 >> zestaw.skladowa2.wartosc_bool >> zestaw.skladowa2.wartosc_char >> zestaw.skladowa2.wartosc_float;
        plik2 >> zestaw.skladowa3.wartosc_bool >> zestaw.skladowa3.wartosc_char >> zestaw.skladowa3.wartosc_float;
        plik2 >> zestaw.skladowa4.wartosc_bool >> zestaw.skladowa4.wartosc_char >> zestaw.skladowa4.wartosc_float;
        if (Czy_wystepuje(zestaw,nazwa_plik1)){
            plik3 << zestaw.wartosc_int << endl;
            plik3 << zestaw.napis << endl;
            plik3 << zestaw.znak << endl;
            plik3 << zestaw.skladowa1.wartosc_bool << " " << zestaw.skladowa1.wartosc_char << " " << zestaw.skladowa1.wartosc_float << endl;
            plik3 << zestaw.skladowa2.wartosc_bool << " " << zestaw.skladowa2.wartosc_char << " " << zestaw.skladowa2.wartosc_float << endl;
            plik3 << zestaw.skladowa3.wartosc_bool << " " << zestaw.skladowa3.wartosc_char << " " << zestaw.skladowa3.wartosc_float << endl;
            plik3 << zestaw.skladowa4.wartosc_bool << " " << zestaw.skladowa4.wartosc_char << " " << zestaw.skladowa4.wartosc_float << endl;
        }else{
            plik1.open(nazwa_plik1.c_str(), fstream::app|fstream::out);
            plik1 << zestaw.wartosc_int << endl;
            plik1 << zestaw.napis << endl;
            plik1 << zestaw.znak << endl;
            plik1 << zestaw.skladowa1.wartosc_bool << " " << zestaw.skladowa1.wartosc_char << " " << zestaw.skladowa1.wartosc_float << endl;
            plik1 << zestaw.skladowa2.wartosc_bool << " " << zestaw.skladowa2.wartosc_char << " " << zestaw.skladowa2.wartosc_float << endl;
            plik1 << zestaw.skladowa3.wartosc_bool << " " << zestaw.skladowa3.wartosc_char << " " << zestaw.skladowa3.wartosc_float << endl;
            plik1 << zestaw.skladowa4.wartosc_bool << " " << zestaw.skladowa4.wartosc_char << " " << zestaw.skladowa4.wartosc_float << endl;
            plik1.close();
        }
    }

    plik2.close();
    plik3.close();

    plik3.open(nazwa_plik3.c_str(), fstream::in);
    plik2.open(nazwa_plik2.c_str(), fstream::out);

    string linia;

    while (getline(plik3, linia)){
        plik2 << linia << endl;
    }

    plik2.close();
    plik3.close();
    return;
}



void SortInt(string nazwa_plik1, string nazwa_plik2, string nazwa_plik3){
    fstream plik1, plik2, plik3;
    string linia;

    int ilosc_zestawow = Ile_zestawow(nazwa_plik1);
    int minimum = 2147483647;
    int wartosc_int = 0;
    int pozycja = 0;


    for (int i = 0; i < ilosc_zestawow; i++){
        plik1.open(nazwa_plik1.c_str(), fstream::in);
        for (int j = 0; j < ilosc_zestawow - i; j++){
            plik1 >> wartosc_int;
            for (int k = 0; k < 7; k++){
                getline(plik1, linia);
            }

            if (wartosc_int < minimum){
                minimum = wartosc_int;
                pozycja = j;
            }
        }
        plik1.close();

        plik1.open(nazwa_plik1.c_str(), fstream::in);
        plik2.open(nazwa_plik2.c_str(), fstream::out);
        plik3.open(nazwa_plik3.c_str(), fstream::app|fstream::out);

        for (int j = 0; j < ilosc_zestawow - i; j++){
            if (j == pozycja){
                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik3 << linia << endl;
                }
            }
            else
            {
                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik2 << linia << endl;
                }
            }
        }
        plik1.close();
        plik2.close();
        plik3.close();

        plik1.open(nazwa_plik1.c_str(), fstream::out);
        plik2.open(nazwa_plik2.c_str(), fstream::in);

        while (getline(plik2, linia)){
            plik1 << linia << endl;
        }

        plik1.close();
        plik2.close();
        minimum = 2147483647;
    }

    plik1.open(nazwa_plik1.c_str(), fstream::out);
    plik3.open(nazwa_plik3.c_str(), fstream::in);

    while (getline(plik3, linia)){
        plik1 << linia << endl;
    }

    plik1.close();
    plik3.close();

    plik2.open(nazwa_plik2.c_str(), fstream::out);
    plik3.open(nazwa_plik3.c_str(), fstream::out);
    plik2.close();
    plik3.close();

    return;
}



void SortString(string nazwa_plik1, string nazwa_plik2, string nazwa_plik3){
    fstream plik1, plik2, plik3;

    string minimum = "";
    string linia,linia2;

    int ilosc_zestawow = Ile_zestawow(nazwa_plik1);
    int pozycja = 0;


    for (int i = 0; i < ilosc_zestawow; i++){
        minimum = "";
        plik1.open(nazwa_plik1.c_str(), fstream::in);
        for (int j = 0; j < ilosc_zestawow - i; j++){
            getline(plik1, linia2);
            getline(plik1, linia2);
            for (int k = 0; k < 5; k++){
                getline(plik1, linia);
            }

            if (linia2 < minimum || minimum.size() == 0){
                minimum = linia2;
                pozycja = j;
            }
        }
        plik1.close();

        plik1.open(nazwa_plik1.c_str(), fstream::in);
        plik2.open(nazwa_plik2.c_str(), fstream::out);
        plik3.open(nazwa_plik3.c_str(), fstream::app|fstream::out);

        for (int j = 0; j < ilosc_zestawow - i; j++){
            if (j == pozycja){
                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik3 << linia << endl;
                }
            }
            else
            {
                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik2 << linia << endl;
                }
            }
        }
        plik1.close();
        plik2.close();
        plik3.close();

        plik1.open(nazwa_plik1.c_str(), fstream::out);
        plik2.open(nazwa_plik2.c_str(), fstream::in);

        while (getline(plik2, linia)){
            plik1 << linia << endl;
        }

        plik1.close();
        plik2.close();
    }

    plik1.open(nazwa_plik1.c_str(), fstream::out);
    plik3.open(nazwa_plik3.c_str(), fstream::in);

    while (getline(plik3, linia)){
        plik1 << linia << endl;
    }

    plik1.close();
    plik3.close();

    plik2.open(nazwa_plik2.c_str(), fstream::out);
    plik3.open(nazwa_plik3.c_str(), fstream::out);
    plik2.close();
    plik3.close();

    return;
}



void SortCount(string nazwa_plik1, string nazwa_plik2, string nazwa_plik3){
    fstream plik1, plik2, plik3;

    Licznosc_Intow(nazwa_plik1, nazwa_plik2, nazwa_plik3);

    int pozycja = 0;
    int licznosc_int = 0;
    int maksimum_char_suma = 0;
    int maksimum_wartosc = -2147483648;
    int maksimum_licznosc = -2147483648;
    int ilosc_zestawow = Ile_zestawow(nazwa_plik1);

    string linia = "";

    Dana zestaw;
    Skladowa skladowa1, skladowa2, skladowa3, skladowa4;

    for (int i = 0; i < ilosc_zestawow; i++){
        plik1.open(nazwa_plik1.c_str(), fstream::in);
        for (int j = 0; j < ilosc_zestawow - i; j++){
            plik1 >> zestaw.wartosc_int >> licznosc_int;                                            //Wartosc int, licznosc int
            getline(plik1, linia);                                                                  //Cos                                      
            getline(plik1, linia);                                                                  //Napis
            getline(plik1, linia);                                                                  //Znak   

            plik1 >> skladowa1.wartosc_bool >> skladowa1.wartosc_char >> skladowa1.wartosc_float;   //Skladowa 1
            plik1 >> skladowa2.wartosc_bool >> skladowa2.wartosc_char >> skladowa2.wartosc_float;   //Skladowa 2
            plik1 >> skladowa3.wartosc_bool >> skladowa3.wartosc_char >> skladowa3.wartosc_float;   //Skladowa 3
            plik1 >> skladowa4.wartosc_bool >> skladowa4.wartosc_char >> skladowa4.wartosc_float;   //Skladowa 4

            int wartosc_char = (skladowa1.wartosc_char + skladowa2.wartosc_char + skladowa3.wartosc_char + skladowa4.wartosc_char)%256;

            if (licznosc_int == maksimum_licznosc){
                if (zestaw.wartosc_int == maksimum_wartosc){
                    if (wartosc_char > maksimum_char_suma){
                        maksimum_char_suma = wartosc_char;
                        maksimum_wartosc = zestaw.wartosc_int;
                        maksimum_licznosc = licznosc_int;
                        pozycja = j;
                    }
                }else{
                    if (zestaw.wartosc_int > maksimum_wartosc){
                        maksimum_char_suma = wartosc_char;
                        maksimum_wartosc = zestaw.wartosc_int;
                        maksimum_licznosc = licznosc_int;
                        pozycja = j;
                    }
                }
            }else{
                if (licznosc_int > maksimum_licznosc){
                    maksimum_char_suma = wartosc_char;
                    maksimum_wartosc = zestaw.wartosc_int;
                    maksimum_licznosc = licznosc_int;
                    pozycja = j;
                }
            }
        }
        plik1.close();

        plik1.open(nazwa_plik1.c_str(), fstream::in);
        plik2.open(nazwa_plik2.c_str(), fstream::out);
        plik3.open(nazwa_plik3.c_str(), fstream::app | fstream::out);
        for (int j = 0; j < ilosc_zestawow - i; j++){
            if (j == pozycja){
                plik1 >> zestaw.wartosc_int >> licznosc_int;
                plik3 << zestaw.wartosc_int;

                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik3 << linia << endl;
                }
            }else{
                plik1 >> zestaw.wartosc_int >> licznosc_int;
                plik2 << zestaw.wartosc_int << " "<< licznosc_int;
                for (int k = 0; k < 7; k++){
                    getline(plik1, linia);
                    plik2 << linia << endl;
                }
            }
        }
        plik1.close();
        plik2.close();
        plik3.close();

        plik2.open(nazwa_plik2.c_str(), fstream::in);
        plik1.open(nazwa_plik1.c_str(), fstream::out);
        while (getline(plik2, linia)){
            plik1 << linia << endl;
        }
        plik1.close();
        plik2.close();

        maksimum_char_suma = 0;
        maksimum_wartosc = -2147483648;
        maksimum_licznosc = -2147483648;
    }

    plik3.open(nazwa_plik3.c_str(), fstream::in);
    plik1.open(nazwa_plik1.c_str(), fstream::out);
    while (getline(plik3, linia)){
        plik1 << linia << endl;
    }
    plik1.close();
    plik3.close();

    plik2.open(nazwa_plik2.c_str(),fstream::out);
    plik3.open(nazwa_plik3.c_str(),fstream::out);
    plik2.close();
    plik3.close();

    return;
}
