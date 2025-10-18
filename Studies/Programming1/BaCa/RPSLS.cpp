//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    int ilosc_gier = 0;
    cin >> ilosc_gier;

    //Statystyki kazdego gracza
    int remisy_a = 0;
    int wygrane_a = 0;
    int przegrane_a = 0;

    int remisy_b = 0;
    int wygrane_b = 0;
    int przegrane_b = 0;

    int remisy_c = 0;
    int wygrane_c = 0;
    int przegrane_c = 0;

    int remisy_d = 0;
    int wygrane_d = 0;
    int przegrane_d = 0;
    

    //Zmienne do kazdej rozgrywki
    char gracz1;
    char gracz2;

    char wybor1;
    char wybor2;

    int moc1 = 0;
    int moc2 = 0;

    int strona_wygrana = 0;

    //Mozliwe wybory J - Jaszczurka, K - Kamien, N - Nozyce, P - Papier, S - Spock
    while(ilosc_gier > 0){
        cin >> gracz1 >> wybor1 >> moc1 >> gracz2 >> wybor2 >> moc2;

        //Rozstrzygniecie zwyciezcy 
        if(wybor1 == wybor2)
            if(moc1 > moc2)
                strona_wygrana = -1;
            else
                if(moc1 < moc2)
                    strona_wygrana = 1;
                else
                    strona_wygrana = 0;
        else
            if(wybor1 == 'J')
                if(wybor2 == 'P' || wybor2 == 'S')
                    strona_wygrana = -1;
                else
                    strona_wygrana = 1;
            else
                if(wybor1 == 'K')
                    if(wybor2 == 'J' || wybor2 == 'N')
                        strona_wygrana = -1;
                    else 
                        strona_wygrana = 1;
                else
                    if(wybor1 == 'N')
                        if(wybor2 == 'J' || wybor2 == 'P')
                            strona_wygrana = -1;
                        else
                            strona_wygrana = 1;
                    else
                        if(wybor1 == 'P')
                            if(wybor2 == 'K' || wybor2 == 'S')
                                strona_wygrana = -1;
                            else
                                strona_wygrana = 1;
                        else
                            if(wybor2 == 'K' || wybor2 == 'N')
                                strona_wygrana = -1;
                            else
                                strona_wygrana = 1;

        //Punktacja pierwszego gracza
        if(gracz1 == 'a')
            if(strona_wygrana == -1)
                wygrane_a = wygrane_a + 1;
            else
                if(strona_wygrana == 1)
                    przegrane_a = przegrane_a + 1;
                else
                    remisy_a = remisy_a + 1;
        else
            if(gracz1 == 'b')
                if(strona_wygrana == -1)
                    wygrane_b = wygrane_b + 1;
                else
                    if(strona_wygrana == 1)
                        przegrane_b = przegrane_b + 1;
                    else
                        remisy_b = remisy_b + 1;
            else
                if(gracz1 == 'c')
                    if(strona_wygrana == -1)
                        wygrane_c = wygrane_c + 1;
                    else
                        if(strona_wygrana == 1)
                            przegrane_c = przegrane_c + 1;
                        else
                            remisy_c = remisy_c + 1;
                else
                    if(strona_wygrana == -1)
                        wygrane_d = wygrane_d + 1;
                    else
                        if(strona_wygrana == 1)
                            przegrane_d = przegrane_d + 1;
                        else
                            remisy_d = remisy_d + 1;
                            
        //Punktacja drugiego gracza
        if(gracz2 == 'a')
            if(strona_wygrana == -1)
                przegrane_a = przegrane_a + 1;
            else
                if(strona_wygrana == 1)
                    wygrane_a = wygrane_a + 1;
                else
                    remisy_a = remisy_a + 1;
        else
            if(gracz2 == 'b')
                if(strona_wygrana == -1)
                    przegrane_b = przegrane_b + 1;
                else
                    if(strona_wygrana == 1)
                        wygrane_b = wygrane_b + 1;
                    else
                        remisy_b = remisy_b + 1;
            else
                if(gracz2 == 'c')
                    if(strona_wygrana == -1)
                        przegrane_c = przegrane_c + 1;
                    else
                        if(strona_wygrana == 1)
                            wygrane_c = wygrane_c + 1;
                        else
                            remisy_c = remisy_c + 1;
                else
                    if(strona_wygrana == -1)
                        przegrane_d = przegrane_d + 1;
                    else
                        if(strona_wygrana == 1)
                            wygrane_d = wygrane_d + 1;
                        else
                            remisy_d = remisy_d + 1;

        ilosc_gier = ilosc_gier - 1;
    }

    bool linia_odstepu = 0;

    //Wyniki gracza a
    if(wygrane_a != 0 || remisy_a != 0 || przegrane_a != 0){
        linia_odstepu = 1;

        int suma_gier_a = wygrane_a + remisy_a + przegrane_a;

        cout << "gracz a" << endl;
        if(wygrane_a != 0)
            cout << "    wygrane: " << ((1.0 * wygrane_a) / suma_gier_a) * 100 << '%' << endl;
        if(remisy_a != 0)
            cout << "    remisy: " << ((1.0 * remisy_a) / suma_gier_a) * 100 << '%' << endl;
        if(przegrane_a != 0)
            cout << "    przegrane: " << ((1.0 * przegrane_a) / suma_gier_a) * 100 << '%' << endl;
    }
    //Wyniki gracza b
    if(wygrane_b != 0 || remisy_b != 0 || przegrane_b != 0){
        if(linia_odstepu == 1)
            cout << endl;
        else
            linia_odstepu = 1;
        
        int suma_gier_b = wygrane_b + remisy_b + przegrane_b;

        cout << "gracz b" << endl;
        if(wygrane_b != 0)
            cout << "    wygrane: " << ((1.0 * wygrane_b) / suma_gier_b) * 100 << '%' << endl;
        if(remisy_b != 0)
            cout << "    remisy: " << ((1.0 * remisy_b) / suma_gier_b) * 100 << '%' << endl;
        if(przegrane_b != 0)
            cout << "    przegrane: " << ((1.0 * przegrane_b) / suma_gier_b) * 100 << '%' << endl;
    }
    //Wyniki gracza c
    if(wygrane_c != 0 || remisy_c != 0 || przegrane_c != 0){
        if(linia_odstepu == 1)
            cout << endl;
        else
            linia_odstepu = 1;

        int suma_gier_c = wygrane_c + remisy_c + przegrane_c;

        cout << "gracz c" << endl;
        if(wygrane_c != 0)
            cout << "    wygrane: " << ((1.0 * wygrane_c) / suma_gier_c) * 100 << '%' << endl;
        if(remisy_c != 0)
            cout << "    remisy: " << ((1.0 * remisy_c) / suma_gier_c) * 100 << '%' << endl;
        if(przegrane_c != 0)
            cout << "    przegrane: " << ((1.0 * przegrane_c) / suma_gier_c) * 100 << '%' << endl;
    }
    //Wyniki gracza d
    if(wygrane_d != 0 || remisy_d != 0 || przegrane_d != 0){
        if(linia_odstepu == 1)
            cout << endl;
        
        int suma_gier_d = wygrane_d + remisy_d + przegrane_d;

        cout << "gracz d" << endl;
        if(wygrane_d != 0)
            cout << "    wygrane: " << ((1.0 * wygrane_d) / suma_gier_d) * 100 << '%' << endl;
        if(remisy_d != 0)
            cout << "    remisy: " << ((1.0 * remisy_d) / suma_gier_d) * 100 << '%' << endl;
        if(przegrane_d != 0)
            cout << "    przegrane: " << ((1.0 * przegrane_d) / suma_gier_d) * 100 << '%' << endl;
    }
    return 0;
}