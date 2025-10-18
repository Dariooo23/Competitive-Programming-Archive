//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    //iostream::sync_with_stdio(0);
    //cin.tie(0);

    int testy = 0;
    cin >> testy;

    while(testy > 0){
        int rozmiar_tab = 0;
        cin >> rozmiar_tab;
        int tab [rozmiar_tab];

        int indeks = 0;
        while(indeks < rozmiar_tab){
            cin >> tab [indeks];
            cout << tab [indeks] << " ";

            indeks = indeks + 1;
        }
        cout << endl;

        int koniec_operacji = 0;
        while(koniec_operacji == 0){
            int dlugosc = 0;
            char operacja = 0;
            int pozycja_start = 0;

            cin >> operacja;

            //Zakonczenie wczytywania operacji
            if(operacja == 'F'){
                int indeks1 = 0;
                while(indeks1 < rozmiar_tab){
                    cout << tab [indeks1] << " ";
                    indeks1 = indeks1 + 1;
                }
                cout << endl;
                koniec_operacji = 1;
            }else{
                cin >> pozycja_start >> dlugosc;
            }

            pozycja_start = pozycja_start % rozmiar_tab;
            if(pozycja_start < 0)
                pozycja_start = pozycja_start + rozmiar_tab;

            //Operacja odwrocenia //Zlozonosc czasowa O(n)
            if(operacja == 'R' && dlugosc != 0){
                int wartosc = 0;
                int indeks_zamiany1 = 0;
                int indeks_zamiany2 = 0;
                int numer_fragmentu = 0;

                while(dlugosc * (numer_fragmentu + 1) <= rozmiar_tab){
                    indeks = 0;
                    while(indeks < (((dlugosc - 1) / 2) + 1)){
                        indeks_zamiany1 = (pozycja_start + dlugosc * numer_fragmentu + indeks) % rozmiar_tab;
                        indeks_zamiany2 = (pozycja_start + dlugosc * (numer_fragmentu + 1) - 1 - indeks) % rozmiar_tab;

                        wartosc =  tab [indeks_zamiany1];
                        tab [indeks_zamiany1] = tab [indeks_zamiany2];
                        tab [indeks_zamiany2] = wartosc;

                        indeks = indeks + 1;
                    }
                    numer_fragmentu = numer_fragmentu + 1;
                }
            }

            //Operacja przesuniecia //Zlozonosc czasowa O(n)
            if(operacja == 'M'){
                int przesuniecie = 0;
                int przesuniecie_kopia = 0;

                cin >> przesuniecie;
                if(dlugosc != 0){
                    przesuniecie_kopia = przesuniecie;
                    przesuniecie = przesuniecie_kopia % dlugosc;

                    int wartosc1 = 0;
                    int wartosc2 = 0;
                    int indeks_zamiany = 0;
                    int indeks_poczatek = 0;
                    int numer_fragmentu = 0;
                    int przesuniecie_startu = 0;
                    int ilosc_przesunietych = 0;
                    int przesuniecie_fragmentu = 0;

                    //Przesuniecie wszystkich pelnych fragmentow
                    while(dlugosc * (numer_fragmentu + 1) <= rozmiar_tab){
                        ilosc_przesunietych = 0;
                        przesuniecie_startu = 0;
                        przesuniecie_fragmentu = dlugosc * numer_fragmentu + pozycja_start;

                        while(ilosc_przesunietych < dlugosc){
                            indeks_poczatek = przesuniecie_startu % dlugosc;
                            indeks_zamiany = (indeks_poczatek + przesuniecie + dlugosc) % dlugosc;
                            wartosc1 = tab [(indeks_poczatek + przesuniecie_fragmentu) % rozmiar_tab];

                            while(indeks_poczatek != indeks_zamiany){
                                wartosc2 = tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab];
                                tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab] = wartosc1;
                                wartosc1 = wartosc2;

                                ilosc_przesunietych = ilosc_przesunietych + 1;
                                indeks_zamiany = (indeks_zamiany + przesuniecie + dlugosc) % dlugosc;
                            }
                            tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab] = wartosc1;

                            ilosc_przesunietych = ilosc_przesunietych + 1;
                            przesuniecie_startu = przesuniecie_startu + 1;
                        }
                        numer_fragmentu = numer_fragmentu + 1;
                    }

                    //Przesuniecie ewentualnie pozostalego fragmentu o mniejszej dlugosci
                    dlugosc = (pozycja_start - ((dlugosc * numer_fragmentu + pozycja_start) % rozmiar_tab) + rozmiar_tab) % rozmiar_tab;
                    if(dlugosc != 0){
                        przesuniecie = przesuniecie_kopia % dlugosc;

                        ilosc_przesunietych = 0;
                        przesuniecie_startu = 0;
                        przesuniecie_fragmentu = (pozycja_start - dlugosc + rozmiar_tab) % rozmiar_tab;

                        while(ilosc_przesunietych < dlugosc){
                            indeks_poczatek = przesuniecie_startu % dlugosc;
                            indeks_zamiany = (indeks_poczatek + przesuniecie + dlugosc) % dlugosc;
                            wartosc1 = tab [(indeks_poczatek + przesuniecie_fragmentu) % rozmiar_tab];

                            while(indeks_poczatek != indeks_zamiany){
                                wartosc2 = tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab];
                                tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab] = wartosc1;
                                wartosc1 = wartosc2;

                                ilosc_przesunietych = ilosc_przesunietych + 1;
                                indeks_zamiany = (indeks_zamiany + przesuniecie + dlugosc) % dlugosc;
                            }
                            tab [(indeks_zamiany + przesuniecie_fragmentu) % rozmiar_tab] = wartosc1;

                            ilosc_przesunietych = ilosc_przesunietych + 1;
                            przesuniecie_startu = przesuniecie_startu + 1;
                        }
                    }
                }
            }

            //Operacja zamiany parami //Zlozonosc czasowa O(n)
            if(operacja == 'C' && dlugosc != 0){
                int wartosc1 = 0;
                int indeks_zamiany = 0;
                int numer_fragmentu = 0;
                int indeks_przesuniecia = 0;

                while(dlugosc * (numer_fragmentu + 2) <= rozmiar_tab){
                    indeks_przesuniecia = 0;
                    while(indeks_przesuniecia < dlugosc){
                        indeks_zamiany = (dlugosc * numer_fragmentu + pozycja_start + indeks_przesuniecia) % rozmiar_tab;

                        wartosc1 = tab [indeks_zamiany];
                        tab [indeks_zamiany] = tab [(indeks_zamiany + dlugosc) % rozmiar_tab];
                        tab [(indeks_zamiany + dlugosc) % rozmiar_tab] = wartosc1;

                        indeks_przesuniecia = indeks_przesuniecia + 1;
                    }
                    numer_fragmentu = numer_fragmentu + 2;
                }
            }

            //Operacja sortowania //Zlozonosc czasowa O(n^2)
            if(operacja == 'S' && dlugosc != 0){
                
                int indeks1 = 0;
                int indeks2 = 0;
                int wartosc = 0;
                int numer_fragmentu = 0;
                int indeks_przesuniecia = 0;

                if(dlugosc > 0){
                    if(dlugosc > rozmiar_tab)
                        dlugosc = rozmiar_tab;
                    //Sortowanie wszystkich pelnych fragmentow rosnaco
                    while(dlugosc * (numer_fragmentu + 1) <= rozmiar_tab){
                        indeks1 = 1;
                        while(indeks1 < dlugosc){
                            indeks2 = 0;
                            while(indeks2 < dlugosc - indeks1){
                                indeks_przesuniecia = (indeks2 + pozycja_start + dlugosc * numer_fragmentu) % rozmiar_tab;

                                if(tab [indeks_przesuniecia] > tab [(indeks_przesuniecia + 1) % rozmiar_tab]){
                                    wartosc = tab [indeks_przesuniecia];
                                    tab [indeks_przesuniecia] = tab [(indeks_przesuniecia + 1) % rozmiar_tab];
                                    tab [(indeks_przesuniecia + 1) % rozmiar_tab] = wartosc;
                                }
                                indeks2 = indeks2 + 1;
                            }
                            indeks1 = indeks1 + 1;
                        }
                        numer_fragmentu = numer_fragmentu + 1;
                    }

                    //Ewentualne sortowanie mniejszego fragmentu rosnaco
                    int dlugosc_kopia = dlugosc;
                    dlugosc = (pozycja_start - ((dlugosc * numer_fragmentu + pozycja_start) % rozmiar_tab) + rozmiar_tab) % rozmiar_tab;
                    pozycja_start = (((dlugosc_kopia * numer_fragmentu + pozycja_start) % rozmiar_tab) + rozmiar_tab) % rozmiar_tab;
                    
                    if(dlugosc != 0){
                        indeks1 = 1;
                        while(indeks1 < dlugosc){
                            indeks2 = 0;
                            while(indeks2 < dlugosc - indeks1){
                                indeks_przesuniecia = (indeks2 + pozycja_start) % rozmiar_tab;

                                if(tab [indeks_przesuniecia] > tab [(indeks_przesuniecia + 1) % rozmiar_tab]){
                                    wartosc = tab [indeks_przesuniecia];
                                    tab [indeks_przesuniecia] = tab [(indeks_przesuniecia + 1) % rozmiar_tab];
                                    tab [(indeks_przesuniecia + 1) % rozmiar_tab] = wartosc;
                                }
                                indeks2 = indeks2 + 1;
                            }
                            indeks1 = indeks1 + 1;
                        }
                    }
                }else{
                    dlugosc = dlugosc * -1;
                    if(dlugosc > rozmiar_tab)
                        dlugosc = rozmiar_tab;
                    //Sortowanie wszystkich pelnych fragmentow malejaco
                    while(dlugosc * (numer_fragmentu + 1) <= rozmiar_tab){
                        indeks1 = 1;
                        while(indeks1 < dlugosc){
                            indeks2 = 0;
                            while(indeks2 < dlugosc - indeks1){
                                indeks_przesuniecia = (indeks2 + pozycja_start + dlugosc * numer_fragmentu) % rozmiar_tab;

                                if(tab [indeks_przesuniecia] < tab [(indeks_przesuniecia + 1) % rozmiar_tab]){
                                    wartosc = tab [indeks_przesuniecia];
                                    tab [indeks_przesuniecia] = tab [(indeks_przesuniecia + 1) % rozmiar_tab];
                                    tab [(indeks_przesuniecia + 1) % rozmiar_tab] = wartosc;
                                }
                                indeks2 = indeks2 + 1;
                            }
                            indeks1 = indeks1 + 1;
                        }
                        numer_fragmentu = numer_fragmentu + 1;
                    }

                    //Ewentualne sortowanie mniejszego fragmentu malejaco
                    int dlugosc_kopia = dlugosc;
                    dlugosc = (pozycja_start - ((dlugosc * numer_fragmentu + pozycja_start) % rozmiar_tab) + rozmiar_tab) % rozmiar_tab;
                    pozycja_start = (((dlugosc_kopia * numer_fragmentu + pozycja_start) % rozmiar_tab) + rozmiar_tab) % rozmiar_tab;
                    
                    if(dlugosc != 0){
                        indeks1 = 1;
                        while(indeks1 < dlugosc){
                            indeks2 = 0;
                            while(indeks2 < dlugosc - indeks1){
                                indeks_przesuniecia = (indeks2 + pozycja_start) % rozmiar_tab;

                                if(tab [indeks_przesuniecia] < tab [(indeks_przesuniecia + 1) % rozmiar_tab]){
                                    wartosc = tab [indeks_przesuniecia];
                                    tab [indeks_przesuniecia] = tab [(indeks_przesuniecia + 1) % rozmiar_tab];
                                    tab [(indeks_przesuniecia + 1) % rozmiar_tab] = wartosc;
                                }
                                indeks2 = indeks2 + 1;
                            }
                            indeks1 = indeks1 + 1;
                        }
                    }
                }
            }
        }
        testy = testy - 1;
    }

    return 0;
}