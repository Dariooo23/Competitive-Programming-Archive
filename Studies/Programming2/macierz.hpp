//Karol Dziekan
using namespace std;

template<typename T, size_t N>
class Macierz {
private:
    T dane[N][N];
public:
    Macierz();
    Macierz(T wartosc);
    Macierz(const T tab[N][N]);



    void kopiuj(Macierz<T, N>& inna) const;



    void dodaj(const Macierz<T, N>& inna);
    void odejmij(const Macierz<T, N>& inna);
    void pomnoz(T liczba);
    Macierz<T, N> pomnoz(const Macierz<T, N>& inna) const;



    void wypisz() const;
    void setij(int i, int j, T wartosc);



    T getij(int i, int j) const;
    T* getDane();



    static Macierz<T, N> jednostkowa();
    Macierz<T, N> transponowana() const;



    template<typename U, size_t M>
    friend ostream& operator<<(ostream& os, const Macierz<U, M>& macierz);
    template<typename U, size_t M>
    friend istream& operator>>(istream& is, Macierz<U, M>& macierz);

    template<typename U, size_t M>
    friend Macierz<U, M>& operator++(Macierz<U, M>& macierz);
    template<typename U, size_t M>
    friend Macierz<U, M> operator++(Macierz<U, M>& macierz, int);
    template<typename U, size_t M>
    friend Macierz<U, M>& operator--(Macierz<U, M>& macierz);
    template<typename U, size_t M>
    friend Macierz<U, M> operator--(Macierz<U, M>& macierz, int);

    Macierz<T, N>& operator=(const Macierz<T, N>& macierz);
    Macierz<T, N>& operator+=(const Macierz<T, N>& macierz);
    Macierz<T, N> operator+(const Macierz<T, N>& macierz) const;
    Macierz<T, N>& operator-=(const Macierz<T, N>& macierz);
    Macierz<T, N> operator-(const Macierz<T, N>& macierz) const;
    Macierz<T, N>& operator*=(const T& liczba);
    Macierz<T, N> operator*(const T& liczba) const;
    Macierz<T, N>& operator*=(const Macierz<T, N>& macierz);
    Macierz<T, N> operator*(const Macierz<T, N>& macierz) const;

    bool operator<(const Macierz<T, N>& inna) const;
    bool operator>(const Macierz<T, N>& inna) const;
};

template<typename T, size_t N>
Macierz<T, N>::Macierz() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] = T(0);
}

template<typename T, size_t N>
Macierz<T, N>::Macierz(T wartosc) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] = wartosc;
}

template<typename T, size_t N>
Macierz<T, N>::Macierz(const T tab[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] = tab[i][j];
}

template<typename T, size_t N>
void Macierz<T, N>::kopiuj(Macierz<T, N>& inna) const {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            inna.dane[i][j] = dane[i][j];
}

template<typename T, size_t N>
void Macierz<T, N>::dodaj(const Macierz<T, N>& inna) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] += inna.dane[i][j];
}

template<typename T, size_t N>
void Macierz<T, N>::odejmij(const Macierz<T, N>& inna) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] -= inna.dane[i][j];
}

template<typename T, size_t N>
void Macierz<T, N>::pomnoz(T liczba) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dane[i][j] *= liczba;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::pomnoz(const Macierz<T, N>& inna) const {
    Macierz<T, N> wynik;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            wynik.dane[i][j] = T(0);
            for (int k = 0; k < N; ++k)
                wynik.dane[i][j] += dane[i][k] * inna.dane[k][j];
        }
    return wynik;
}

template<typename T, size_t N>
void Macierz<T, N>::wypisz() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << dane[i][j] << ' ';
        cout << '\n';
    }
}

template<typename T, size_t N>
void Macierz<T, N>::setij(int i, int j, T wartosc) {
    dane[i][j] = wartosc;
}

template<typename T, size_t N>
T Macierz<T, N>::getij(int i, int j) const {
    return dane[i][j];
}

template<typename T, size_t N>
T* Macierz<T, N>::getDane() {
    return &dane[0][0];
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::jednostkowa() {
    Macierz<T, N> wynik;
    for (int i = 0; i < N; ++i)
        wynik.dane[i][i] = T(1);
    return wynik;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::transponowana() const {
    Macierz<T, N> wynik;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            wynik.dane[j][i] = dane[i][j];
    return wynik;
}

template<typename T, size_t N>
ostream& operator<<(ostream& out, const Macierz<T, N>& macierz) {
    size_t col_widths[N] = {0};
    for (size_t j = 0; j < N; ++j) {
        for (size_t i = 0; i < N; ++i) {
            ostringstream oss;
            oss << macierz.dane[i][j];
            col_widths[j] = max(col_widths[j], oss.str().length());
        }
    }

    for (size_t i = 0; i < N; ++i) {
        out << "[";
        for (size_t j = 0; j < N; ++j) {
            ostringstream oss;
            oss << macierz.dane[i][j];
            string str = oss.str();
            size_t spaces = col_widths[j] > str.length() ? col_widths[j] - str.length() : 0;
            out << string(spaces, ' ') << str;
            if (j < N - 1) out << ", ";
        }
        out << "]" << endl;
    }
    return out;
}

template<typename T, size_t N>
istream& operator>>(istream& in, Macierz<T, N>& macierz) {
    cout << "Podaj dane macierzy" << endl;
    for (size_t i = 0; i < N; ++i){
        for (size_t j = 0; j < N; ++j) {
            in >> macierz.dane[i][j];
        }
    }
    return in;
}

template<typename T, size_t N>
bool Macierz<T, N>::operator<(const Macierz<T, N>& inna) const {
    T suma1 = T(0), suma2 = T(0);
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            suma1 += dane[i][j];
            suma2 += inna.dane[i][j];
        }
    return suma1 < suma2;
}

template<typename T, size_t N>
bool Macierz<T, N>::operator>(const Macierz<T, N>& inna) const {
    T suma1 = T(0), suma2 = T(0);
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            suma1 += dane[i][j];
            suma2 += inna.dane[i][j];
        }
    return suma1 > suma2;
}

template<typename T, size_t N>
Macierz<T, N>& Macierz<T, N>::operator=(const Macierz<T, N>& macierz){
    if (this != &macierz) {
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < N; ++j)
                dane[i][j] = macierz.dane[i][j];
    }
    return *this;
}

template<typename T, size_t N>
Macierz<T, N>& Macierz<T, N>::operator+=(const Macierz<T, N>& macierz) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            dane[i][j] += macierz.dane[i][j];
    return *this;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::operator+(const Macierz<T, N>& macierz) const {
    Macierz<T, N> wynik = *this;
    wynik += macierz;
    return wynik;
}

template<typename T, size_t N>
Macierz<T, N>& Macierz<T, N>::operator-=(const Macierz<T, N>& macierz) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            dane[i][j] -= macierz.dane[i][j];
    return *this;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::operator-(const Macierz<T, N>& macierz) const {
    Macierz<T, N> wynik = *this;
    wynik -= macierz;
    return wynik;
}

template<typename T, size_t N>
Macierz<T, N>& Macierz<T, N>::operator*=(const T& liczba) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            dane[i][j] *= liczba;
    return *this;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::operator*(const T& liczba) const {
    Macierz<T, N> wynik = *this;
    wynik *= liczba;
    return wynik;
}

template<typename T, size_t N>
Macierz<T, N>& operator++(Macierz<T, N>& macierz) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            macierz.dane[i][j] += 1;
    return macierz;
}

template<typename T, size_t N>
Macierz<T, N> operator++(Macierz<T, N>& macierz, int) {
    Macierz<T, N> temp = macierz;
    ++macierz;
    return temp;
}

template<typename T, size_t N>
Macierz<T, N>& operator--(Macierz<T, N>& macierz) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            macierz.dane[i][j] -= 1;
    return macierz;
}

template<typename T, size_t N>
Macierz<T, N> operator--(Macierz<T, N>& macierz, int) {
    Macierz<T, N> temp = macierz;
    --macierz;
    return temp;
}


template<typename T, size_t N>
Macierz<T, N>& Macierz<T, N>::operator*=(const Macierz<T, N>& macierz) {
    Macierz<T, N> wynik;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            wynik.dane[i][j] = T(0);
            for (size_t k = 0; k < N; ++k)
                wynik.dane[i][j] += dane[i][k] * macierz.dane[k][j];
        }
    *this = wynik;
    return *this;
}

template<typename T, size_t N>
Macierz<T, N> Macierz<T, N>::operator*(const Macierz<T, N>& macierz) const {
    Macierz<T, N> wynik;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            wynik.dane[i][j] = T(0);
            for (size_t k = 0; k < N; ++k)
                wynik.dane[i][j] += dane[i][k] * macierz.dane[k][j];
        }
    return wynik;
}
