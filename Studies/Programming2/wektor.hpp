//Karol Dziekan

#include <cmath>
#include <iostream>

using namespace std;

template<typename T, size_t N>
class Wektor {
private:
    T* dane;
public:
    Wektor();
    Wektor(const T tab[N]);
    Wektor(const T dana);
    Wektor(const Wektor<T, N>& inny);
    ~Wektor();



    void kopiuj(const Wektor<T, N>& inny);
    void dodaj(const Wektor<T, N>& inny);
    void odejmij(const Wektor<T, N>& inny);
    void pomnoz(T skalar);



    T dlugosc() const;
    T iloczynSkalarny(const Wektor<T, N>& inny) const;
    Wektor<T, N> iloczynWektorowy(const Wektor<T, N>& inny) const;



    void wypisz() const;



    void set(size_t i, T wartosc);
    T get(size_t i) const;
    T* getDane();



    template<typename U, size_t M>
    friend ostream& operator<<(ostream& os, const Wektor<U, M>& wektor);
    template<typename U, size_t M>
    friend istream& operator>>(istream& is, Wektor<U, M>& wektor);

    template<typename U, size_t M>
    friend Wektor<U, M>& operator++(Wektor<U, M>& wektor);
    template<typename U, size_t M>
    friend Wektor<U, M> operator++(Wektor<U, M>& wektor, int);
    template<typename U, size_t M>
    friend Wektor<U, M>& operator--(Wektor<U, M>& wektor);
    template<typename U, size_t M>
    friend Wektor<U, M> operator--(Wektor<U, M>& wektor, int);

    Wektor<T, N>& operator=(const Wektor<T, N>& inny);
    Wektor<T, N>& operator+=(const Wektor<T, N>& inny);
    Wektor<T, N> operator+(const Wektor<T, N>& inny) const;
    Wektor<T, N>& operator-=(const Wektor<T, N>& inny);
    Wektor<T, N> operator-(const Wektor<T, N>& inny) const;
    Wektor<T, N>& operator*=(const T& skalar);
    Wektor<T, N> operator*(const T& skalar) const;

    bool operator<(const Wektor<T, N>& inny) const;
    bool operator>(const Wektor<T, N>& inny) const;
};

template<typename T, size_t N>
Wektor<T, N>::Wektor() : dane(new T[N]) {
    for (size_t i = 0; i < N; ++i)
        dane[i] = T(0);
}

template<typename T, size_t N>
Wektor<T, N>::Wektor(const T tab[N]) : dane(new T[N]) {
    for (size_t i = 0; i < N; ++i)
        dane[i] = tab[i];
}

template<typename T, size_t N>
Wektor<T, N>::Wektor(const T dana) : dane(new T[N]) {
    for (size_t i = 0; i < N; ++i)
        dane[i] = dana;
}

template<typename T, size_t N>
Wektor<T, N>::Wektor(const Wektor<T, N>& inny) : dane(new T[N]) {
    for (size_t i = 0; i < N; ++i)
        dane[i] = inny.dane[i];
}

template<typename T, size_t N>
Wektor<T, N>::~Wektor(){
    delete[] dane;
}

template<typename T, size_t N>
void Wektor<T, N>::kopiuj(const Wektor<T, N>& inny) {
    for (size_t i = 0; i < N; ++i)
        dane[i] = inny.dane[i];
}

template<typename T, size_t N>
void Wektor<T, N>::dodaj(const Wektor<T, N>& inny) {
    for (size_t i = 0; i < N; ++i)
        dane[i] += inny.dane[i];
}

template<typename T, size_t N>
void Wektor<T, N>::odejmij(const Wektor<T, N>& inny) {
    for (size_t i = 0; i < N; ++i)
        dane[i] -= inny.dane[i];
}

template<typename T, size_t N>
void Wektor<T, N>::pomnoz(T skalar) {
    for (size_t i = 0; i < N; ++i)
        dane[i] *= skalar;
}

template<typename T, size_t N>
T Wektor<T, N>::dlugosc() const {
    T suma = T(0);
    for (size_t i = 0; i < N; ++i)
        suma += dane[i] * dane[i];
    return sqrt(suma);
}

template<typename T, size_t N>
T Wektor<T, N>::iloczynSkalarny(const Wektor<T, N>& inny) const {
    T suma = T(0);
    for (size_t i = 0; i < N; ++i)
        suma += dane[i] * inny.dane[i];
    return suma;
}

template<typename T, size_t N>
Wektor<T, N> Wektor<T, N>::iloczynWektorowy(const Wektor<T, N>& inny) const {
    Wektor<T, N> wynik;

    if (N != 3){
        cout << "Iloczyn wektorowy jest zdefiniowany tylko dla N==3" << endl;
        return wynik;
    }else{
        wynik.dane[0] = dane[1] * inny.dane[2] - dane[2] * inny.dane[1];
        wynik.dane[1] = dane[2] * inny.dane[0] - dane[0] * inny.dane[2];
        wynik.dane[2] = dane[0] * inny.dane[1] - dane[1] * inny.dane[0];
        return wynik;
    }
}

template<typename T, size_t N>
void Wektor<T, N>::wypisz() const {
    for (size_t i = 0; i < N; ++i)
        cout << dane[i] << ' ';
    cout << '\n';
}

template<typename T, size_t N>
void Wektor<T, N>::set(size_t i, T wartosc) {
    if (i < N)
        dane[i] = wartosc;
}

template<typename T, size_t N>
T Wektor<T, N>::get(size_t i) const {
    if (i < N)
        return dane[i];
    return T(0);
}

template<typename T, size_t N>
T* Wektor<T, N>::getDane() {
    return dane;
}

template<typename T, size_t N>
ostream& operator<<(ostream& out, const Wektor<T, N>& wektor) {
    out << "[";
    for (size_t i = 0; i < N; ++i) {
        out << wektor.dane[i];
        if (i < N - 1) out << ", ";
    }
    out << "]";
    return out;
}

template<typename T, size_t N>
istream& operator>>(istream& in, Wektor<T, N>& wektor) {
    cout << "Podaj dane wektora" << endl;
    for (size_t i = 0; i < N; ++i) {
        in >> wektor.dane[i];
    }
    return in;
}

template<typename T, size_t N>
bool Wektor<T, N>::operator<(const Wektor<T, N>& inny) const {
    return this->dlugosc() < inny.dlugosc();
}

template<typename T, size_t N>
bool Wektor<T, N>::operator>(const Wektor<T, N>& inny) const {
    return this->dlugosc() > inny.dlugosc();
}

template<typename T, size_t N>
Wektor<T, N>& Wektor<T, N>::operator=(const Wektor<T, N>& inny) {
    if (this != &inny) {
        for (size_t i = 0; i < N; ++i)
            dane[i] = inny.dane[i];
    }
    return *this;
}

template<typename T, size_t N>
Wektor<T, N>& operator++(Wektor<T, N>& wektor) {
    for (size_t i = 0; i < N; ++i)
        wektor.dane[i] += 1;
    return wektor;
}

template<typename T, size_t N>
Wektor<T, N> operator++(Wektor<T, N>& wektor, int) {
    Wektor<T, N> temp = wektor;
    ++wektor;
    return temp;
}

template<typename T, size_t N>
Wektor<T, N>& operator--(Wektor<T, N>& wektor) {
    for (size_t i = 0; i < N; ++i)
        wektor.dane[i] -= 1;
    return wektor;
}

template<typename T, size_t N>
Wektor<T, N> operator--(Wektor<T, N>& wektor, int) {
    Wektor<T, N> temp = wektor;
    --wektor;
    return temp;
}

template<typename T, size_t N>
Wektor<T, N>& Wektor<T, N>::operator+=(const Wektor<T, N>& inny) {
    for (size_t i = 0; i < N; ++i)
        dane[i] += inny.dane[i];
    return *this;
}

template<typename T, size_t N>
Wektor<T, N> Wektor<T, N>::operator+(const Wektor<T, N>& inny) const {
    Wektor<T, N> wynik = *this;
    wynik += inny;
    return wynik;
}

template<typename T, size_t N>
Wektor<T, N>& Wektor<T, N>::operator-=(const Wektor<T, N>& inny) {
    for (size_t i = 0; i < N; ++i)
        dane[i] -= inny.dane[i];
    return *this;
}

template<typename T, size_t N>
Wektor<T, N> Wektor<T, N>::operator-(const Wektor<T, N>& inny) const {
    Wektor<T, N> wynik = *this;
    wynik -= inny;
    return wynik;
}

template<typename T, size_t N>
Wektor<T, N>& Wektor<T, N>::operator*=(const T& skalar) {
    for (size_t i = 0; i < N; ++i)
        dane[i] *= skalar;
    return *this;
}

template<typename T, size_t N>
Wektor<T, N> Wektor<T, N>::operator*(const T& skalar) const {
    Wektor<T, N> wynik = *this;
    wynik *= skalar;
    return wynik;
}