//Karol Dziekan
#include <bits/stdc++.h>
#include <regex>

using namespace std;

bool Czy_IPv4_poprawne (string IPv4){
    regex IPv4_szablon(R"(^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");
    return regex_match(IPv4, IPv4_szablon);
}

bool Czy_maska_poprawna (string maska){
    int kropki = 0;
    string liczba_napis = "";
    string maska_binarna = "";

    for (int i = 0; i < maska.size(); i++){
        if (maska[i] == '.'){
            if (liczba_napis.size() == 0){
                return false;
            }else{
                int liczba = stoi(liczba_napis);
                if (liczba < 0 || liczba > 255){
                    return false;
                }else{
                    for (int j = 7; j >= 0; j--){
                        maska_binarna += (char)(((liczba >> i) & 1) + '0');
                    }

                    liczba_napis = "";
                    kropki++;
                }
            }
        }else{
            if ('0' <= maska[i] && maska[i] <= '9'){
                liczba_napis += maska[i];
            }else{
                return false;
            }
        }
    }

    if (kropki != 3){
        return false;
    }
    int liczba = stoi(liczba_napis);
    if (liczba < 0 || liczba > 255){
        return false;
    }else{
        for (int i = 7; i >= 0; i--){
            maska_binarna += (char)(((liczba >> i) & 1) + '0');
        }
        liczba_napis = "";
    }

    int flaga = 0;
    for (int i = 0; i < maska_binarna.size(); i++){
        if (maska_binarna[i] == '0'){
            flaga = 1;
        }else{
            if (flaga == 1 && maska_binarna[i] == '1'){
                return false;
            }
        }
    }

    return true;
}

string Oblicz_adres_podsieci (string IPv4, string Maska){
    int czesci_ip[4];
    int czesci_maska[4];

    int indeks_ip = 0;
    string pomocnicza_ip = "";
    for (int i = 0; i <= IPv4.size(); i++){
        if (IPv4[i] == '.'){
            czesci_ip[indeks_ip] = stoi(pomocnicza_ip);
            pomocnicza_ip = "";
            indeks_ip++;
        }else{
            pomocnicza_ip += IPv4[i];
        }
    }
    czesci_ip[indeks_ip] = stoi(pomocnicza_ip);


    int indeks_maska = 0;
    string pomocnicza_maska = "";
    for (int i = 0; i <= Maska.size(); i++){
        if (Maska[i] == '.'){
            czesci_maska[indeks_maska] = stoi(pomocnicza_maska);
            pomocnicza_maska = "";
            indeks_maska++;
        }else{
            pomocnicza_maska += Maska[i];
        }
    }
    czesci_maska[indeks_maska] = stoi(pomocnicza_maska);

    string czesci_adresu_podsieci[4];

    for (int i = 0; i < 4; i++){
        czesci_adresu_podsieci[i] = to_string(czesci_ip[i] & czesci_maska[i]);
    }

    string adres_podsieci = czesci_adresu_podsieci[0] + '.' + czesci_adresu_podsieci[1] + '.' + czesci_adresu_podsieci[2] + '.' + czesci_adresu_podsieci[3];
    return adres_podsieci;
}
int main(){
    

    string ip,maska;

    cout << "Podaj ip: ";
    cin >> ip;
    cout << "Podaj maske: ";
    cin >> maska;

    if (Czy_IPv4_poprawne(ip)){
        if (Czy_maska_poprawna(maska)){
            cout << "Adres podsieci to " << Oblicz_adres_podsieci(ip,maska);
        }else{
            cout << "Bledna maska";
        }
    }else{
        cout << "Bledne ip";
    }
    return 0;
}