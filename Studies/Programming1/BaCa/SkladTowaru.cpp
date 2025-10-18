//Karol Dziekan
#include <iostream>

using namespace std;

//POCZATEK -- Operacja wyswietlajaca bledy zakresow/numerow
void ERROR(){
    cout << "error" << endl;
    return;
}
//KONIEC -- Operacja wyswietlajaca bledy zakresow/numerow

//POCZATEK -- Struktury obiektow obslugiwanych w zadaniu
struct towar{
    char etykieta1;
    char etykieta2;
    unsigned short int suma_towaru;
};

struct polka{
    towar towary [128];
    int suma_polki;
    int rozmiar_polki;
};

struct regal{
    polka polki [128];
    int suma_regalu;
    int rozmiar_regalu;
};

struct magazyn{
    regal regaly [128];
    polka podreczna_polka;
    int rozmiar_magazynu;
    long long int suma_magazynu;
};

struct sklad{
    magazyn magazyny [128];
    regal podreczny_regal;
    polka podreczna_polka;
    int rozmiar_skladu;
    long long int suma_skladu;
};
//KONIEC -- Struktury obiektow obslugiwanych w zadaniu



//POCZATEK -- Obiekt przechowujacy wszystkie dane w zadaniu
sklad glowny_sklad;
//KONIEC -- Obiekt przechowujacy wszystkie dane w zadaniu



//POCZATEK -- Operacja sprawdzajace poprawnosc zakresow
bool Czy_miedzy_0_128(long long int arg1, long long int arg2, long long int arg3, long long int arg4){
    if ((arg1 > 128 || arg2 > 128 || arg3 > 128 || arg4 > 128) || (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0)){
        return 0;
    }else{
        return 1;
    }
}
//KONIEC -- Operacja sprawdzajace poprawnosc zakresow



//POCZATEK -- Operacje dzialajace na ilosci towaru
int Dodaj_towar (towar* dany_towar, int ilosc_towaru){
    //W przypadku przepelnienia dodaj tyle ile sie zmiesci, w przeciwnym przypadku dodaj wszystko
    if ((*dany_towar).suma_towaru + ilosc_towaru >= 65535){
        ilosc_towaru = 65535 - (*dany_towar).suma_towaru;
        (*dany_towar).suma_towaru = 65535;
    }else{
        (*dany_towar).suma_towaru += ilosc_towaru;
    }

    return ilosc_towaru;
}
int Odejmij_towar (towar* dany_towar, int ilosc_towaru){
    //W przypadku braku odejmij tyle ile zostalo, w przeciwnym przypadku odejmij wszystko
    if ((*dany_towar).suma_towaru - ilosc_towaru <= 0){
        ilosc_towaru = (*dany_towar).suma_towaru;
        (*dany_towar).suma_towaru = 0;
    }else{
        (*dany_towar).suma_towaru -= ilosc_towaru;
    }

    return ilosc_towaru;
}
long long int Zsumuj_towary_polka (polka* dana_polka){
    long long int suma = 0;
    for (int i = 0; i < (*dana_polka).rozmiar_polki; i++){
        suma += (*dana_polka).towary[i].suma_towaru;
    }

    (*dana_polka).suma_polki = suma;

    return suma;
}
long long int Zsumuj_towary_regal (regal* dany_regal){
    long long int suma = 0;
    for (int i = 0; i < (*dany_regal).rozmiar_regalu; i++){
        suma += Zsumuj_towary_polka(&(*dany_regal).polki[i]);
    }

    (*dany_regal).suma_regalu = suma;

    return suma;
}
long long int Zsumuj_towary_magazyn (magazyn* dany_magazyn){
    long long int suma = 0;
    for (int i = 0; i < (*dany_magazyn).rozmiar_magazynu; i++){
        suma += Zsumuj_towary_regal(&(*dany_magazyn).regaly[i]);
    }

    suma += Zsumuj_towary_polka (&(*dany_magazyn).podreczna_polka);

    (*dany_magazyn).suma_magazynu = suma;

    return suma;
}
long long int Zsumuj_towary_sklad (sklad* dany_sklad){
    long long int suma = 0;
    for (int i = 0; i < (*dany_sklad).rozmiar_skladu; i++){
        suma += Zsumuj_towary_magazyn(&(*dany_sklad).magazyny[i]);
    }

    suma += Zsumuj_towary_regal (&(*dany_sklad).podreczny_regal);
    suma += Zsumuj_towary_polka (&(*dany_sklad).podreczna_polka);

    (*dany_sklad).suma_skladu = suma;
    
    return suma;
}
//KONIEC -- Operacje dzialajace na ilosci towaru

int licznik = 0;

//POCZATEK -- Operacje tworzace obiekty
void Stworz_towary_na_polce (polka* dana_polka, int ile_towarow){
    //Jezeli miejsc na towary ma byc teraz wiecej to nalezy dolozyc nowe, nie ruszac starych miejsc, w przeciwnym wypadku wyzerowac nadmiarowe miejsca
    if (ile_towarow > (*dana_polka).rozmiar_polki){
        for (int i = (*dana_polka).rozmiar_polki; i < ile_towarow; i++){
            (*dana_polka).towary[i].suma_towaru = 0;
            (*dana_polka).towary[i].etykieta1 = 0;
            (*dana_polka).towary[i].etykieta2 = 0;
        }
    }
    if (ile_towarow < (*dana_polka).rozmiar_polki){
        for (int i = ile_towarow; i < (*dana_polka).rozmiar_polki; i++){
            (*dana_polka).towary[i].suma_towaru = 0;
            (*dana_polka).towary[i].etykieta1 = 0;
            (*dana_polka).towary[i].etykieta2 = 0;
        }
    }

    (*dana_polka).rozmiar_polki = ile_towarow;
    
    return;
}
void Stworz_polki_na_regale (regal* dany_regal, int ile_polek, int ile_towarow){
    //Jezeli miejsc na polki ma byc teraz wiecej to nalezy dolozyc nowe, nie ruszac starych miejsc, w przeciwnym wypadku wyzerowac nadmiarowe miejsca
    if (ile_polek > (*dany_regal).rozmiar_regalu){
        for (int i = (*dany_regal).rozmiar_regalu; i < ile_polek; i++){
            Stworz_towary_na_polce (&(*dany_regal).polki[i],ile_towarow);
        }
    }

    if (ile_polek < (*dany_regal).rozmiar_regalu){
        for (int i = ile_polek; i < (*dany_regal).rozmiar_regalu; i++){
            Stworz_towary_na_polce (&(*dany_regal).polki[i],0);
            (*dany_regal).polki[i].suma_polki = 0;
        }
    }

    //Po usunieciu nadmiarowych, lub dodaniu brakujacych, nalezy zaktualizowac jeszcze istniejace juz struktury nizej
    for (int i = 0; i < ile_polek; i++){
        Stworz_towary_na_polce (&(*dany_regal).polki[i],ile_towarow);
    }

    (*dany_regal).rozmiar_regalu = ile_polek;
    
    return;
}
void Stworz_regaly_na_magazynie (magazyn* dany_magazyn, int ile_regalow, int ile_polek, int ile_towarow){
    //Jezeli miejsc na regaly ma byc teraz wiecej to nalezy dolozyc nowe, nie ruszac starych miejsc, w przeciwnym wypadku wyzerowac nadmiarowe miejsca

    if (ile_regalow > (*dany_magazyn).rozmiar_magazynu){
        for (int i = (*dany_magazyn).rozmiar_magazynu; i < ile_regalow; i++){
            Stworz_polki_na_regale (&(*dany_magazyn).regaly[i],ile_polek,ile_towarow);
        }
    }


    if (ile_regalow < (*dany_magazyn).rozmiar_magazynu){
        for (int i = ile_regalow; i < (*dany_magazyn).rozmiar_magazynu; i++){
            Stworz_polki_na_regale (&(*dany_magazyn).regaly[i],0,0);
            (*dany_magazyn).regaly[i].suma_regalu = 0;
        }
    }

    //Po usunieciu nadmiarowych, lub dodaniu brakujacych, nalezy zaktualizowac jeszcze istniejace juz struktury nizej
    for (int i = 0; i < ile_regalow; i++){
        Stworz_polki_na_regale (&(*dany_magazyn).regaly[i],ile_polek,ile_towarow);
    }

    (*dany_magazyn).rozmiar_magazynu = ile_regalow;
    
    return;
}
void Stworz_magazyny_na_skladzie (sklad* dany_sklad, int ile_magazynow, int ile_regalow, int ile_polek, int ile_towarow){
    //Jezeli miejsc na magazyny ma byc teraz wiecej to nalezy dolozyc nowe, nie ruszac starych miejsc, w przeciwnym wypadku wyzerowac nadmiarowe miejsca
    if (ile_magazynow > (*dany_sklad).rozmiar_skladu){
        for (int i = (*dany_sklad).rozmiar_skladu; i < ile_magazynow; i++){
            Stworz_regaly_na_magazynie (&(*dany_sklad).magazyny[i],ile_regalow,ile_polek,ile_towarow);
        }
    }
    if (ile_magazynow < (*dany_sklad).rozmiar_skladu){
        for (int i = ile_magazynow; i < (*dany_sklad).rozmiar_skladu; i++){
            Stworz_towary_na_polce (&(*dany_sklad).magazyny[i].podreczna_polka,0);
            Stworz_regaly_na_magazynie (&(*dany_sklad).magazyny[i],0,0,0);
            (*dany_sklad).magazyny[i].suma_magazynu = 0;
        }
    }

    //Po usunieciu nadmiarowych, lub dodaniu brakujacych, nalezy zaktualizowac jeszcze istniejace juz struktury nizej
    for (int i = 0; i < ile_magazynow; i++){
        Stworz_regaly_na_magazynie (&(*dany_sklad).magazyny[i],ile_regalow,ile_polek,ile_towarow);
    }

    (*dany_sklad).rozmiar_skladu = ile_magazynow;
    
    return;
}
//KONIEC -- Operacje tworzace obiekty



//POCZATEK -- Operacje nadajace parametry
void SET_AP (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s){
        ERROR();
    }else{
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych te polke w sobie przed zmiana rozmiarow
        int suma_polki = glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki;
        glowny_sklad.suma_skladu -= suma_polki;
        glowny_sklad.magazyny[w].suma_magazynu -= suma_polki;
        glowny_sklad.magazyny[w].regaly[r].suma_regalu -= suma_polki;

        //Zmiana rozmiaru polki 
        Stworz_towary_na_polce(&glowny_sklad.magazyny[w].regaly[r].polki[s],p);
        //Poprawa sum towarow na strukturze polki i nizej
        Zsumuj_towary_polka(&glowny_sklad.magazyny[w].regaly[r].polki[s]);
        
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych te polke w sobie po zmianie rozmiarow
        suma_polki = glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki;
        glowny_sklad.suma_skladu += suma_polki;
        glowny_sklad.magazyny[w].suma_magazynu += suma_polki;
        glowny_sklad.magazyny[w].regaly[r].suma_regalu += suma_polki;
    }

    return;
}
void SET_AS (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r){
        ERROR();
    }else{
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten regal w sobie przed zmiana rozmiarow
        int suma_regalu = glowny_sklad.magazyny[w].regaly[r].suma_regalu;
        glowny_sklad.suma_skladu -= suma_regalu;
        glowny_sklad.magazyny[w].suma_magazynu -= suma_regalu;

        //Zmiana rozmiaru regalu
        Stworz_polki_na_regale(&glowny_sklad.magazyny[w].regaly[r],s,p);
        //Poprawa sum towarow na strukturze regalu i nizej
        Zsumuj_towary_regal(&glowny_sklad.magazyny[w].regaly[r]);

        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten regal w sobie po zmianie rozmiarow
        suma_regalu = glowny_sklad.magazyny[w].regaly[r].suma_regalu;
        glowny_sklad.suma_skladu += suma_regalu;
        glowny_sklad.magazyny[w].suma_magazynu += suma_regalu;
    }
    return;
}
void SET_AR (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w){
        ERROR();
    }else{
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten magazyn w sobie przed zmiana rozmiarow
        int suma_magazynu = glowny_sklad.magazyny[w].suma_magazynu;
        glowny_sklad.suma_skladu -= suma_magazynu;

        //Zmiana rozmiaru magazynu
        Stworz_regaly_na_magazynie(&glowny_sklad.magazyny[w],r,s,p);
        //Poprawa sum towarow na strukturze magazynu i nizej
        Zsumuj_towary_magazyn(&glowny_sklad.magazyny[w]);
        
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten magazyn w sobie po zmianie rozmiarow
        suma_magazynu = glowny_sklad.magazyny[w].suma_magazynu;
        glowny_sklad.suma_skladu += suma_magazynu;
    }
    return;
}
void SET_AW (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p){
    //Zmiana rozmiaru skladu
    Stworz_magazyny_na_skladzie(&glowny_sklad,w,r,s,p);
    //Poprawa sum towarow na strukturze sklad i nizej
    Zsumuj_towary_sklad(&glowny_sklad);
        
    return;
}
void SET_HW (unsigned short int w, unsigned short int p){
    if (glowny_sklad.rozmiar_skladu <= w){
        ERROR();
    }else{
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ta podreczna polke w sobie przed zmiana rozmiarow
        int suma_podrecznej_polki = glowny_sklad.magazyny[w].podreczna_polka.suma_polki;
        glowny_sklad.suma_skladu -= suma_podrecznej_polki;
        glowny_sklad.magazyny[w].suma_magazynu -= suma_podrecznej_polki;

        //Zmiana rozmiaru podrecznej polki
        Stworz_towary_na_polce(&glowny_sklad.magazyny[w].podreczna_polka,p);
        //Poprawa sum towarow na strukturze podrecznej polki i nizej
        Zsumuj_towary_polka(&glowny_sklad.magazyny[w].podreczna_polka);
        
        //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ta podreczna polke w sobie po zmianie rozmiarow
        suma_podrecznej_polki = glowny_sklad.magazyny[w].podreczna_polka.suma_polki;
        glowny_sklad.suma_skladu += suma_podrecznej_polki;
        glowny_sklad.magazyny[w].suma_magazynu += suma_podrecznej_polki;
    }
    return;
}
void SET_HR (unsigned short int s, unsigned short int p){
    //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten podreczny regal w sobie przed zmiana rozmiarow
    int suma_podrecznego_regalu = glowny_sklad.podreczny_regal.suma_regalu;
    glowny_sklad.suma_skladu -= suma_podrecznego_regalu;

    //Zmiana rozmiaru podrecznego regalu
    Stworz_polki_na_regale(&glowny_sklad.podreczny_regal,s,p);
    //Poprawa sum towarow na strukturze sklad i nizej
    Zsumuj_towary_regal(&glowny_sklad.podreczny_regal);

    //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ten podreczny regal w sobie po zmianie rozmiarow
    suma_podrecznego_regalu = glowny_sklad.podreczny_regal.suma_regalu;
    glowny_sklad.suma_skladu += suma_podrecznego_regalu;

    return;
}
void SET_HS (unsigned short int p){
    //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ta podreczna polke w sobie przed zmiana rozmiarow
    int suma_podrecznej_polki = glowny_sklad.podreczna_polka.suma_polki;
    glowny_sklad.suma_skladu -= suma_podrecznej_polki;

    //Zmiana rozmiaru podrecznej polki
    Stworz_towary_na_polce(&glowny_sklad.podreczna_polka,p);
    //Poprawa sum towarow na strukturze podrecznej polki i nizej
    Zsumuj_towary_polka(&glowny_sklad.podreczna_polka);
    
    //Aktualizacja sumy na wszystkich wyzszych strukturach zawierajacych ta podreczna polke w sobie po zmianie rozmiarow
    suma_podrecznej_polki = glowny_sklad.podreczna_polka.suma_polki;
    glowny_sklad.suma_skladu += suma_podrecznej_polki;

    return;
}
//KONIEC -- Operacje nadajace parametry



//POCZATEK -- Operacje dodajace towary
void PUT_W (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s || glowny_sklad.magazyny[w].regaly[r].polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu 65535
        a = Dodaj_towar (&glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki += a;
        glowny_sklad.magazyny[w].regaly[r].suma_regalu +=a;
        glowny_sklad.magazyny[w].suma_magazynu += a;
        glowny_sklad.suma_skladu += a;
    }

    return;
}
void PUT_H (unsigned short int w, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu 65535
        a = Dodaj_towar (&glowny_sklad.magazyny[w].podreczna_polka.towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.magazyny[w].podreczna_polka.suma_polki += a;
        glowny_sklad.magazyny[w].suma_magazynu += a;
        glowny_sklad.suma_skladu += a;
    }
    return;
}
void PUT_R (unsigned short int s, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s || glowny_sklad.podreczny_regal.polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu 65535
        a = Dodaj_towar (&glowny_sklad.podreczny_regal.polki[s].towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.podreczny_regal.polki[s].suma_polki += a;
        glowny_sklad.podreczny_regal.suma_regalu += a;
        glowny_sklad.suma_skladu += a;
    }

    return;
}
void PUT_S (unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu 65535
        a = Dodaj_towar (&glowny_sklad.podreczna_polka.towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.podreczna_polka.suma_polki += a;
        glowny_sklad.suma_skladu += a;
    }

    return;
}
//KONIEC -- Operacje dodajace towary



//POCZATEK -- Operacje nadajace strukture oraz ilosc towaru
void FILL (long long int w, long long int r, long long int s, long long int p, long long int a){
    //Wyczyszczenie calej struktury
    //Czyszczenie czesci podrecznych
    for (int i = 0; i < glowny_sklad.podreczna_polka.rozmiar_polki; i++){
        glowny_sklad.podreczna_polka.towary[i].suma_towaru = 0;
        glowny_sklad.podreczna_polka.towary[i].etykieta1 = 0;
        glowny_sklad.podreczna_polka.towary[i].etykieta2 = 0;
    }
    glowny_sklad.podreczna_polka.rozmiar_polki = 0;
    glowny_sklad.podreczna_polka.suma_polki = 0;

    for (int i = 0; i < glowny_sklad.podreczny_regal.rozmiar_regalu; i++){
        for (int j = 0; j < glowny_sklad.podreczny_regal.polki[i].rozmiar_polki; j++){
            glowny_sklad.podreczny_regal.polki[i].towary[j].suma_towaru = 0;
            glowny_sklad.podreczny_regal.polki[i].towary[j].etykieta1 = 0;
            glowny_sklad.podreczny_regal.polki[i].towary[j].etykieta2 = 0;
        }
        glowny_sklad.podreczny_regal.polki[i].rozmiar_polki = 0;
        glowny_sklad.podreczny_regal.polki[i].suma_polki = 0;
    }
    glowny_sklad.podreczny_regal.suma_regalu = 0;
    glowny_sklad.podreczny_regal.rozmiar_regalu = 0;

    for (int i = 0; i < glowny_sklad.rozmiar_skladu; i++){
        for (int j = 0; j < glowny_sklad.magazyny[i].podreczna_polka.rozmiar_polki; j++){
            glowny_sklad.magazyny[i].podreczna_polka.towary[j].suma_towaru = 0;
            glowny_sklad.magazyny[i].podreczna_polka.towary[j].etykieta1 = 0;
            glowny_sklad.magazyny[i].podreczna_polka.towary[j].etykieta2 = 0;
        }
        glowny_sklad.magazyny[i].podreczna_polka.rozmiar_polki = 0;
        glowny_sklad.magazyny[i].podreczna_polka.suma_polki = 0;
    }
    //Czyszczenie spojnej struktury 
    for (int i = 0; i < glowny_sklad.rozmiar_skladu; i++){
        for (int j = 0; j < glowny_sklad.magazyny[i].rozmiar_magazynu; j++){
            for (int k = 0; k < glowny_sklad.magazyny[i].regaly[j].rozmiar_regalu; k++){
                for (int l = 0; l < glowny_sklad.magazyny[i].regaly[j].polki[k].rozmiar_polki; l++){
                    glowny_sklad.magazyny[i].regaly[j].polki[k].towary[l].suma_towaru = 0;
                    glowny_sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta1 = 0;
                    glowny_sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta2 = 0;
                }
                glowny_sklad.magazyny[i].regaly[j].polki[k].rozmiar_polki = 0;
                glowny_sklad.magazyny[i].regaly[j].polki[k].suma_polki = 0;
            }
            glowny_sklad.magazyny[i].regaly[j].rozmiar_regalu = 0;
            glowny_sklad.magazyny[i].regaly[j].suma_regalu = 0;
        }
        glowny_sklad.magazyny[i].rozmiar_magazynu = 0;
        glowny_sklad.magazyny[i].suma_magazynu = 0;
    }
    glowny_sklad.rozmiar_skladu = 0;
    glowny_sklad.suma_skladu = 0;

    

    //Ustawienie danej wartosci w calej strukturze i aktualizacja sum
    if (a > 65535){
        a = 65535;
    }
    
    //Ustawienie wartosci na podrecznej polce skladu
    for (int i = 0; i < p; i++){
        glowny_sklad.podreczna_polka.towary[i].suma_towaru = a;
    }
    glowny_sklad.podreczna_polka.rozmiar_polki = p;
    glowny_sklad.podreczna_polka.suma_polki = a * p;
    glowny_sklad.suma_skladu += a * p;

    //Ustawienie wartosci na podrecznym regale skladu
    for (int i = 0; i < s; i++){
        for (int j = 0; j < p; j++){
            glowny_sklad.podreczny_regal.polki[i].towary[j].suma_towaru = a;
        }
        glowny_sklad.podreczny_regal.polki[i].rozmiar_polki = p;
        glowny_sklad.podreczny_regal.polki[i].suma_polki = a * p;
    }
    glowny_sklad.podreczny_regal.rozmiar_regalu = s;
    glowny_sklad.podreczny_regal.suma_regalu = a * p * s;
    glowny_sklad.suma_skladu += a * p * s;
    
    //Ustawienie wartosci na podrecznej polce magazynow
    for (int i = 0; i < w; i++){
        for (int j = 0; j < p; j++){
            glowny_sklad.magazyny[i].podreczna_polka.towary[j].suma_towaru = a;
        }
        glowny_sklad.magazyny[i].podreczna_polka.rozmiar_polki = p;
        glowny_sklad.magazyny[i].podreczna_polka.suma_polki = a * p;
        glowny_sklad.magazyny[i].suma_magazynu += a * p;
        glowny_sklad.suma_skladu += a * p;
    }
    
    //Ustawienie wartosci na spojnej czesci struktury
    for (int i = 0; i < w; i++){
        for (int j = 0; j < r; j++){
            for (int k = 0; k < s; k++){
                for (int l = 0; l < p; l++){
                    glowny_sklad.magazyny[i].regaly[j].polki[k].towary[l].suma_towaru = a;
                }
                glowny_sklad.magazyny[i].regaly[j].polki[k].rozmiar_polki = p;
                glowny_sklad.magazyny[i].regaly[j].polki[k].suma_polki = a * p;
            }
            glowny_sklad.magazyny[i].regaly[j].rozmiar_regalu = s;
            glowny_sklad.magazyny[i].regaly[j].suma_regalu = a * p * s;
        }
        glowny_sklad.magazyny[i].rozmiar_magazynu = r;
        glowny_sklad.magazyny[i].suma_magazynu += a * p * s * r;
    }
    glowny_sklad.rozmiar_skladu = w;
    glowny_sklad.suma_skladu += a * p * s * r * w;
    
    return;
}
//KONIEC -- Operacje nadajace strukture oraz ilosc towaru



//POCZATEK -- Operacje usuwajace towary
void POP_W (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s || glowny_sklad.magazyny[w].regaly[r].polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu ponizej 0 
        a = Odejmij_towar (&glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki -= a;
        glowny_sklad.magazyny[w].regaly[r].suma_regalu -=a;
        glowny_sklad.magazyny[w].suma_magazynu -= a;
        glowny_sklad.suma_skladu -= a;
    }

    return;
}

void POP_H (unsigned short int w, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu ponizej 0
        a = Odejmij_towar (&glowny_sklad.magazyny[w].podreczna_polka.towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.magazyny[w].podreczna_polka.suma_polki -= a;
        glowny_sklad.magazyny[w].suma_magazynu -= a;
        glowny_sklad.suma_skladu -= a;
    }
    return;
}

void POP_R (unsigned short int s, unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s || glowny_sklad.podreczny_regal.polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu ponizej 0
        a = Odejmij_towar (&glowny_sklad.podreczny_regal.polki[s].towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.podreczny_regal.polki[s].suma_polki -= a;
        glowny_sklad.podreczny_regal.suma_regalu -= a;
        glowny_sklad.suma_skladu -= a;
    }

    return;
}

void POP_S (unsigned short int p, unsigned short int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        //Dodanie do odpowiedniego miejsca towaru z uwzglednieniem limitu ponizej 0
        a = Odejmij_towar (&glowny_sklad.podreczna_polka.towary[p],a);

        //Aktualizacja pozostalych struktur wyzej nad tym towarem
        glowny_sklad.podreczna_polka.suma_polki -= a;
        glowny_sklad.suma_skladu -= a;
    }

    return;
}
//KONIEC -- Operacje usuwajace towary



//POCZATEK -- Operacje przenoszace towary
void MOW_W (unsigned short int w1, unsigned short int r1, unsigned short int s1, unsigned short int w2, unsigned short int r2, unsigned short int s2, unsigned short int p, long long int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w1 || glowny_sklad.magazyny[w1].rozmiar_magazynu <= r1 || glowny_sklad.magazyny[w1].regaly[r1].rozmiar_regalu <= s1 || glowny_sklad.magazyny[w1].regaly[r1].polki[s1].rozmiar_polki <= p){
        ERROR();
        return;
    }
    if (glowny_sklad.rozmiar_skladu <= w2 || glowny_sklad.magazyny[w2].rozmiar_magazynu <= r2 || glowny_sklad.magazyny[w2].regaly[r2].rozmiar_regalu <= s2 || glowny_sklad.magazyny[w2].regaly[r2].polki[s2].rozmiar_polki <= p){
        ERROR();
        return;
    }

    //Sprawdzenie czy z poczatkowego miejsca mozna wziac "a" towaru, i czy w docelowym miejscu zmiesci sie "a" towaru
    long long int ilosc_1miejsce = glowny_sklad.magazyny[w1].regaly[r1].polki[s1].towary[p].suma_towaru;
    long long int ilosc_2miejsce = 65535 - glowny_sklad.magazyny[w2].regaly[r2].polki[s2].towary[p].suma_towaru;

    if (ilosc_1miejsce < a){
        a = ilosc_1miejsce;
    }
    if (ilosc_2miejsce < a){
        a = ilosc_2miejsce;
    }

    //Odjecie z pierwszego miejsca przenoszonego towaru
    glowny_sklad.magazyny[w1].suma_magazynu -= a;
    glowny_sklad.magazyny[w1].regaly[r1].suma_regalu -= a;
    glowny_sklad.magazyny[w1].regaly[r1].polki[s1].suma_polki -= a;
    glowny_sklad.magazyny[w1].regaly[r1].polki[s1].towary[p].suma_towaru -= a;

    //Dodanie do pierwszego miejsca przenoszonego towaru
    glowny_sklad.magazyny[w2].suma_magazynu += a;
    glowny_sklad.magazyny[w2].regaly[r2].suma_regalu += a;
    glowny_sklad.magazyny[w2].regaly[r2].polki[s2].suma_polki += a;
    glowny_sklad.magazyny[w2].regaly[r2].polki[s2].towary[p].suma_towaru += a;

    return;
}

void MOW_H (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, long long int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s || glowny_sklad.magazyny[w].regaly[r].polki[s].rozmiar_polki <= p){
        ERROR();
        return;
    }
    if (glowny_sklad.magazyny[w].podreczna_polka.rozmiar_polki <= p){
        ERROR();
        return;
    }

    //Sprawdzenie czy z poczatkowego miejsca mozna wziac "a" towaru, i czy w docelowym miejscu zmiesci sie "a" towaru
    long long int ilosc_1miejsce = glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].suma_towaru;
    long long int ilosc_2miejsce = 65535 - glowny_sklad.magazyny[w].podreczna_polka.towary[p].suma_towaru;

    if (ilosc_1miejsce < a){
        a = ilosc_1miejsce;
    }
    if (ilosc_2miejsce < a){
        a = ilosc_2miejsce;
    }

    //Odjecie z pierwszego miejsca przenoszonego towaru
    glowny_sklad.magazyny[w].regaly[r].suma_regalu -= a;
    glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki -= a;
    glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].suma_towaru -= a;

    //Dodanie do pierwszego miejsca przenoszonego towaru
    glowny_sklad.magazyny[w].podreczna_polka.suma_polki += a;
    glowny_sklad.magazyny[w].podreczna_polka.towary[p].suma_towaru += a;

    return;
}

void MOW_R (unsigned short int w, unsigned short int r, unsigned short int s1, unsigned short int s2, unsigned short int p, long long int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s1 || glowny_sklad.magazyny[w].regaly[r].polki[s1].rozmiar_polki <= p){
        ERROR();
        return;
    }
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s2 || glowny_sklad.podreczny_regal.polki[s2].rozmiar_polki <= p){
        ERROR();
        return;
    }

    //Sprawdzenie czy z poczatkowego miejsca mozna wziac "a" towaru, i czy w docelowym miejscu zmiesci sie "a" towaru
    long long int ilosc_1miejsce = glowny_sklad.magazyny[w].regaly[r].polki[s1].towary[p].suma_towaru;
    long long int ilosc_2miejsce = 65535 - glowny_sklad.podreczny_regal.polki[s2].towary[p].suma_towaru;

    if (ilosc_1miejsce < a){
        a = ilosc_1miejsce;
    }
    if (ilosc_2miejsce < a){
        a = ilosc_2miejsce;
    }

    //Odjecie z pierwszego miejsca przenoszonego towaru
    glowny_sklad.magazyny[w].suma_magazynu -= a;
    glowny_sklad.magazyny[w].regaly[r].suma_regalu -= a;
    glowny_sklad.magazyny[w].regaly[r].polki[s1].suma_polki -= a;
    glowny_sklad.magazyny[w].regaly[r].polki[s1].towary[p].suma_towaru -= a;

    //Dodanie do pierwszego miejsca przenoszonego towaru
    glowny_sklad.podreczny_regal.suma_regalu += a;
    glowny_sklad.podreczny_regal.polki[s2].suma_polki += a;
    glowny_sklad.podreczny_regal.polki[s2].towary[p].suma_towaru += a;

    return;
}

void MOW_S (unsigned short int s, unsigned short int p, long long int a){
    //Sprawdzenie poprawnosci numerow obiektow
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s || glowny_sklad.podreczny_regal.polki[s].rozmiar_polki <= p){
        ERROR();
        return;
    }
    if (glowny_sklad.podreczna_polka.rozmiar_polki <= p){
        ERROR();
        return;
    }

    //Sprawdzenie czy z poczatkowego miejsca mozna wziac "a" towaru, i czy w docelowym miejscu zmiesci sie "a" towaru
    long long int ilosc_1miejsce = glowny_sklad.podreczny_regal.polki[s].towary[p].suma_towaru;
    long long int ilosc_2miejsce = 65535 - glowny_sklad.podreczna_polka.towary[p].suma_towaru;

    if (ilosc_1miejsce < a){
        a = ilosc_1miejsce;
    }
    if (ilosc_2miejsce < a){
        a = ilosc_2miejsce;
    }

    //Odjecie z pierwszego miejsca przenoszonego towaru
    glowny_sklad.podreczny_regal.suma_regalu -= a;
    glowny_sklad.podreczny_regal.polki[s].suma_polki -= a;
    glowny_sklad.podreczny_regal.polki[s].towary[p].suma_towaru -= a;

    //Dodanie do pierwszego miejsca przenoszonego towaru
    glowny_sklad.podreczna_polka.suma_polki += a;
    glowny_sklad.podreczna_polka.towary[p].suma_towaru += a;

    return;
}
//KONIEC -- Operacje przenoszace towary



//POCZATEK -- Operacje wyswietlajace informacje
void GET_E (){
    cout << glowny_sklad.suma_skladu << endl;
    return;
}

void GET_W (unsigned short int w){
    if (glowny_sklad.rozmiar_skladu <= w){
        ERROR();
    }else{
        cout << glowny_sklad.magazyny[w].suma_magazynu << endl;
    }

    return;
}

void GET_RW (unsigned short int w, unsigned short int r){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r){
        ERROR();
    }else{
        cout << glowny_sklad.magazyny[w].regaly[r].suma_regalu << endl;
    }

    return;
}

void GET_RH (){
    cout << glowny_sklad.podreczny_regal.suma_regalu << endl;
}

void GET_SW (unsigned short int w, unsigned short int r, unsigned short int s){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s){
        ERROR();
    }else{
        cout << glowny_sklad.magazyny[w].regaly[r].polki[s].suma_polki << endl;
    }

    return;
}

void GET_SH (unsigned short int w){
    if (glowny_sklad.rozmiar_skladu <= w){
        ERROR();
    }else{
        cout << glowny_sklad.magazyny[w].podreczna_polka.suma_polki << endl;
    }

    return;
}

void GET_SR (unsigned short int s){
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s){
        ERROR();
    }else{
        cout << glowny_sklad.podreczny_regal.polki[s].suma_polki << endl;
    }

    return;
}

void GET_S (){
    cout << glowny_sklad.podreczna_polka.suma_polki << endl;

    return;
}
//KONIEC -- Operacje wyswietlajace informacje



//POCZATEK -- Operacje etykietowe
void SET_LW (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, char dd [3]){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s || glowny_sklad.magazyny[w].regaly[r].polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta1 = dd[0];
        glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta2 = dd[1];
    }

    return;
}

void SET_LH (unsigned short int w, unsigned short int p, char dd [3]){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta1 = dd[0];
        glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta2 = dd[1];
    }

    return;
}

void SET_LR (unsigned short int s, unsigned short int p, char dd [3]){
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s || glowny_sklad.podreczny_regal.polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta1 = dd[0];
        glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta2 = dd[1];
    }

    return;
}

void SET_LS (unsigned short int p, char dd [3]){
    if (glowny_sklad.podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        glowny_sklad.podreczna_polka.towary[p].etykieta1 = dd[0];
        glowny_sklad.podreczna_polka.towary[p].etykieta2 = dd[1];
    }

    return;
}

void GET_LW (unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].rozmiar_magazynu <= r || glowny_sklad.magazyny[w].regaly[r].rozmiar_regalu <= s || glowny_sklad.magazyny[w].regaly[r].polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        if (glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta1 == 0 && glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta1 == 0){
            cout << "--" << endl;
        }else{
            cout << glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta1 << glowny_sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta2 << endl;
        }
    }

    return;
}

void GET_LH (unsigned short int w, unsigned short int p){
    if (glowny_sklad.rozmiar_skladu <= w || glowny_sklad.magazyny[w].podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        if (glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta1 == 0 && glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta2 == 0){
            cout << "--" << endl;
        }else{
            cout << glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta1 << glowny_sklad.magazyny->podreczna_polka.towary[p].etykieta2 << endl;
        }
    }

    return;
}

void GET_LR (unsigned short int s, unsigned short int p){
    if (glowny_sklad.podreczny_regal.rozmiar_regalu <= s || glowny_sklad.podreczny_regal.polki[s].rozmiar_polki <= p){
        ERROR();
    }else{
        if (glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta1 == 0 && glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta2 == 0){
            cout << "--" << endl;
        }else{
            cout << glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta1 << glowny_sklad.podreczny_regal.polki[s].towary[p].etykieta2 << endl;
        }
    }

    return;
}

void GET_LS (unsigned short int p){
    if (glowny_sklad.podreczna_polka.rozmiar_polki <= p){
        ERROR();
    }else{
        if (glowny_sklad.podreczna_polka.towary[p].etykieta1 == 0 && glowny_sklad.podreczna_polka.towary[p].etykieta2 == 0){
            cout << "--" << endl;
        }else{
            cout << glowny_sklad.podreczna_polka.towary[p].etykieta1 << glowny_sklad.podreczna_polka.towary[p].etykieta2 << endl;
        }
    }

    return;
}
//KONIEC -- Operacje etykietowe



//POCZATEK -- Glowna czesc kodu obslugujaca zapytania
int main(){
    //Zmienne przechowujace parametry kazdego polecenia
    char polecenie [7] = {'N','U','L','L','\0','\0','\0'};

    long long int arg1 = 0;
    long long int arg2 = 0;
    long long int arg3 = 0;
    long long int arg4 = 0;
    long long int arg5 = 0;
    long long int arg6 = 0;
    long long int arg7 = 0;
    long long int arg8 = 0;

    char etykiety [3];

    //Wykonywanie kolejnych polecen z konsoli
    
    while (!(polecenie[0] == 'E' && polecenie[1] == 'N' && polecenie[2] == 'D')){
        cin >> polecenie;
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'A' && polecenie[5] == 'P'){
            cin >> arg1 >> arg2 >> arg3 >> arg4;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                SET_AP (arg1,arg2,arg3,arg4);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'A' && polecenie[5] == 'S'){
            cin >> arg1 >> arg2 >> arg3 >> arg4;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                SET_AS (arg1,arg2,arg3,arg4);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'A' && polecenie[5] == 'R'){
            cin >> arg1 >> arg2 >> arg3 >> arg4;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                SET_AR (arg1,arg2,arg3,arg4);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'A' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                SET_AW (arg1,arg2,arg3,arg4);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'H' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                SET_HW(arg1,arg2);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'H' && polecenie[5] == 'R'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                SET_HR(arg1,arg2);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'H' && polecenie[5] == 'S'){
            cin >> arg1;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                SET_HS(arg1);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                if (arg5 < 0){
                    arg5 *= -1;
                    POP_W(arg1,arg2,arg3,arg4,arg5);
                }else{
                    PUT_W(arg1,arg2,arg3,arg4,arg5);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'H'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                if (arg3 < 0){
                    arg3 *= -1;
                    POP_H(arg1,arg2,arg3);
                }else{
                    PUT_H(arg1,arg2,arg3);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'R'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                if (arg3 < 0){
                    arg3 *= -1;
                    POP_R(arg1,arg2,arg3);
                }else{
                    PUT_R(arg1,arg2,arg3);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'S'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                if (arg2 < 0){
                    arg2 *= -1;
                    POP_S(arg1,arg2);
                }else{
                    PUT_S(arg1,arg2);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'F' && polecenie[1] == 'I' && polecenie[2] == 'L' && polecenie[3] == 'L'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                FILL(arg1,arg2,arg3,arg4,arg5);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[3] == '-' && polecenie[4] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                if (arg5 < 0){
                    arg5 *= -1;
                    PUT_W(arg1,arg2,arg3,arg4,arg5);
                }else{
                    POP_W(arg1,arg2,arg3,arg4,arg5);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[3] == '-' && polecenie[4] == 'H'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                if (arg3 < 0 ){
                    arg3 *= -1;
                    PUT_H(arg1,arg2,arg3);
                }else{
                    POP_H(arg1,arg2,arg3);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[3] == '-' && polecenie[4] == 'R'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                if (arg3 < 0){
                    arg3 *= -1;
                    PUT_R(arg1,arg2,arg3);
                }else{
                    POP_R(arg1,arg2,arg3);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[3] == '-' && polecenie[4] == 'S'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                if (arg2 < 0){
                    arg2 *= -1;
                    PUT_S(arg1,arg2);
                }else{
                    POP_S(arg1,arg2);
                }
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[3] == '-' && polecenie[4] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5 >> arg6 >> arg7 >> arg8;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg7) && Czy_miedzy_0_128(arg4,arg5,arg6,arg7)){
                MOW_W(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[3] == '-' && polecenie[4] == 'H'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                MOW_H(arg1,arg2,arg3,arg4,arg5);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[3] == '-' && polecenie[4] == 'R'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5 >> arg6;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg5) && Czy_miedzy_0_128(arg1,arg2,arg4,arg5)){
                MOW_R(arg1,arg2,arg3,arg4,arg5,arg6);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[3] == '-' && polecenie[4] == 'S'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                MOW_S(arg1,arg2,arg3);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'E'){
            GET_E();
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'W'){
            cin >> arg1;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                GET_W(arg1);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'R' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                GET_RW(arg1,arg2);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'R' && polecenie[5] == 'H'){
            GET_RH();
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'S' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2 >> arg3;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,0)){
                GET_SW(arg1,arg2,arg3);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'S' && polecenie[5] == 'H'){
            cin >> arg1;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                GET_SH(arg1);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'S' && polecenie[5] == 'R'){
            cin >> arg1;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                GET_SR(arg1);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'S'){
            GET_S();
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4 >> etykiety[0] >> etykiety[1];
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                SET_LW(arg1,arg2,arg3,arg4,etykiety);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'H'){
            cin >> arg1 >> arg2 >> etykiety[0] >> etykiety[1];
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                SET_LH(arg1,arg2,etykiety);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'R'){
            cin >> arg1 >> arg2 >> etykiety[0] >> etykiety[1];
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                SET_LR(arg1,arg2,etykiety);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'S'){
            cin >> arg1 >> etykiety[0] >> etykiety[1];
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                SET_LS(arg1,etykiety);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'W'){
            cin >> arg1 >> arg2 >> arg3 >> arg4;
            if (Czy_miedzy_0_128(arg1,arg2,arg3,arg4)){
                GET_LW(arg1,arg2,arg3,arg4);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'H'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                GET_LH(arg1,arg2);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'R'){
            cin >> arg1 >> arg2;
            if (Czy_miedzy_0_128(arg1,arg2,0,0)){
                GET_LR(arg1,arg2);
            }else{
                ERROR();
            }
        }
        else
        if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[3] == '-' && polecenie[4] == 'L' && polecenie[5] == 'S'){
            cin >> arg1;
            if (Czy_miedzy_0_128(arg1,0,0,0)){
                GET_LS(arg1);
            }else{
                ERROR();
            }
        }
    }
    
    return 0;
}
//KONIEC -- Glowna czesc kodu obslugujaca zapytania
//KONIEC -- Oraz koniec tego zadania, litosci