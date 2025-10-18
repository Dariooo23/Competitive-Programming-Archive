//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;


class Kapitan{
    private:
        string m_imie;
        string m_nazwisko;
        int m_wiek;
        bool m_aktywnosc;

    public:
        static int m_licznik_kapitanow;

        //Gettery
        string getImie() const;
        string getNazwisko() const;
        int getWiek() const;
        bool getAktywnosc() const;
        int getLicznikKapitanow() const;
        //Settery
        void setImie(string imie);
        void setNazwisko(string nazwisko);
        void setWiek(int wiek);
        void setAktywnosc(bool aktywnosc);

        //Konstruktory i Destruktor
        Kapitan();
        Kapitan(string imie, string nazwisko, int wiek, bool aktywnosc);
        ~Kapitan();
};

int Kapitan::m_licznik_kapitanow = 0;

//Gettery implementacja
string Kapitan::getImie() const{
    return m_imie;
}
string Kapitan::getNazwisko() const{
    return m_nazwisko;
}
int Kapitan::getWiek() const{
    return m_wiek;
}
bool Kapitan::getAktywnosc() const{
    return m_aktywnosc;
}
int Kapitan::getLicznikKapitanow() const{
    return m_licznik_kapitanow;
}

//Settery implementacja
void Kapitan::setImie(string imie){
    m_imie = imie;
    return;
}
void Kapitan::setNazwisko(string nazwisko){
    m_nazwisko = nazwisko;
    return;
}
void Kapitan::setWiek(int wiek){
    m_wiek = wiek;
    return;
}
void Kapitan::setAktywnosc(bool aktywnosc){
    m_aktywnosc = aktywnosc;
    return;
}

//Konstruktory i Destruktor implementacja
Kapitan::Kapitan() : m_imie("Jan"), m_nazwisko("Kowalski"), m_wiek(30), m_aktywnosc(true){
    m_licznik_kapitanow++;
    return;
}
Kapitan::Kapitan(string imie, string nazwisko, int wiek, bool aktywnosc){
    m_licznik_kapitanow++;

    m_imie = imie;
    m_nazwisko = nazwisko;
    m_wiek = wiek;
    m_aktywnosc = aktywnosc;

    return;
}
Kapitan::~Kapitan(){
    m_licznik_kapitanow--;

    m_imie = "";
    m_nazwisko = "";
    m_wiek = 0;
    m_aktywnosc = false;

    return;
}

int main(){
    cout << Kapitan::m_licznik_kapitanow << endl;

    Kapitan* kapitan1 = new Kapitan("Adam", "Nowak", 35, true);
    Kapitan* kapitan2 = new Kapitan("Ewa", "Kowalczyk", 28, false);

    cout << Kapitan::m_licznik_kapitanow << endl;

    Kapitan* kapitan3 = new Kapitan("Marek", "Zielinski", 40, true);
    Kapitan* kapitan4 = new Kapitan;

    cout << Kapitan::m_licznik_kapitanow << endl;

    delete kapitan1;
    delete kapitan2;

    cout << Kapitan::m_licznik_kapitanow << endl;

    delete kapitan3;

    cout << Kapitan::m_licznik_kapitanow << endl;

    delete kapitan4;

    cout << Kapitan::m_licznik_kapitanow << endl;
    return 0;
}
