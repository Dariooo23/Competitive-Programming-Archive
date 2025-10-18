// Karol Dziekan
#include <iostream>
#include <cstdarg>

using namespace std;

// Globalne funkcje pomocnicze do wyliczania NWD i NWW
int gcd(int a, int b){
    while (b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a < 0 ? -a : a;
}
int lcm(int a, int b){
    if (a == 0 || b == 0)
        return 0;
    return a / gcd(a, b) * b;
}


// Struktura pomocnicza przy / i % wielomianow
struct Fraction{
    int num, den;

    Fraction(int n = 0, int d = 1) : num(n), den(d){
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        int g = gcd(num, den);
        if (g > 1)
        {
            num /= g;
            den /= g;
        }
    }
    Fraction operator-(const Fraction &f) const{
        int lcm_den = lcm(den, f.den);
        int n1 = num * (lcm_den / den);
        int n2 = f.num * (lcm_den / f.den);
        return Fraction(n1 - n2, lcm_den);
    }
    Fraction operator*(const Fraction &f) const{
        return Fraction(num * f.num, den * f.den);
    }
    Fraction operator/(const Fraction &f) const{
        return Fraction(num * f.den, den * f.num);
    }
    bool is_zero() const { return num == 0; }
};


// Glowna klasa potrzebna w programie
class POLYNOMIAL{
private:
    int degree;
    int *coeffs;

    int gcd_all() const;
    void normalizeDegree();

public:
    static int overloaded;

    POLYNOMIAL();
    POLYNOMIAL(int deg, ...);
    POLYNOMIAL(const POLYNOMIAL &other);
    ~POLYNOMIAL();

    void *operator new(size_t size);
    void operator delete(void *ptr);

    int getDegree() const;
    int getCoeff(int i) const;
    void setDegree(int deg);
    void setCoeff(int i, int value);

    POLYNOMIAL &operator++();
    POLYNOMIAL operator++(int);
    POLYNOMIAL &operator--();
    POLYNOMIAL operator--(int);

    friend std::ostream &operator<<(std::ostream &os, const POLYNOMIAL &p);
    friend std::istream &operator>>(std::istream &is, POLYNOMIAL &p);

    POLYNOMIAL operator<<(int n) const;
    POLYNOMIAL operator>>(int n) const;

    POLYNOMIAL &operator=(const POLYNOMIAL &other);

    POLYNOMIAL operator+(const POLYNOMIAL &other) const;
    POLYNOMIAL operator-(const POLYNOMIAL &other) const;
    POLYNOMIAL operator*(const POLYNOMIAL &other) const;
    POLYNOMIAL operator/(const POLYNOMIAL &other) const;
    POLYNOMIAL operator%(const POLYNOMIAL &other) const;
    POLYNOMIAL operator-() const;

    POLYNOMIAL &operator+=(const POLYNOMIAL &other);
    POLYNOMIAL &operator-=(const POLYNOMIAL &other);
    POLYNOMIAL &operator*=(const POLYNOMIAL &other);
    POLYNOMIAL &operator/=(const POLYNOMIAL &other);
    POLYNOMIAL &operator%=(const POLYNOMIAL &other);
    POLYNOMIAL &operator<<=(int n);
    POLYNOMIAL &operator>>=(int n);
};


// Przeladowanie new i delete
void *POLYNOMIAL::operator new(size_t size) {++overloaded; return ::operator new(size);}
void POLYNOMIAL::operator delete(void *ptr) {--overloaded; ::operator delete(ptr);}


// Gettery i settery
int POLYNOMIAL::getDegree() const {return degree;}
int POLYNOMIAL::getCoeff(int i) const {return coeffs[i];}
void POLYNOMIAL::setDegree(int deg) {
    int *new_coeffs = new int[deg + 1];
    int min_deg = (deg < degree) ? deg : degree;

    for (int i = 0; i <= min_deg; ++i)
        new_coeffs[i] = coeffs[i];

    for (int i = min_deg + 1; i <= deg; ++i)
        new_coeffs[i] = 0;

    delete[] coeffs;
    coeffs = new_coeffs;
    degree = deg;
}
void POLYNOMIAL::setCoeff(int i, int value) {
    if (i >= 0 && i <= degree) 
        coeffs[i] = value;
}


// Metody pomocnicze
int POLYNOMIAL::gcd_all() const {
    int result = 0;

    for (int i = 0; i <= degree; ++i){
        if (coeffs[i] != 0){
            if (result == 0) result = coeffs[i];
            else result = gcd(result, coeffs[i]);
        }
    }

    if (result < 0) result *= -1;
    return result == 0 ? 1 : result;
}
void POLYNOMIAL::normalizeDegree() {
    int new_deg = degree;

    while (new_deg > 0 && coeffs[new_deg] == 0)
        --new_deg;

    if (new_deg != degree){
        degree = new_deg;
        int *new_coeffs = new int[degree + 1];

        for (int i = 0; i <= degree; ++i)
            new_coeffs[i] = coeffs[i];

        delete[] coeffs;
        coeffs = new_coeffs;
    }
}


// Konstruktor i destruktor klasy
POLYNOMIAL::POLYNOMIAL(int deg, ...) {
    degree = deg;
    coeffs = new int[degree + 1];

    va_list args;
    va_start(args, deg);
    for (int i = 0; i <= degree; ++i) 
        coeffs[i] = va_arg(args, int);
    va_end(args);

    int wsp_nwd = gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= degree; ++i) 
            coeffs[i] /= wsp_nwd;

    normalizeDegree();
}
POLYNOMIAL::POLYNOMIAL(const POLYNOMIAL &other) {
    degree = other.degree;
    coeffs = new int[degree + 1];

    for (int i = 0; i <= degree; ++i) 
        coeffs[i] = other.coeffs[i];
    
    normalizeDegree();
}
POLYNOMIAL::POLYNOMIAL() {
    degree = 0;
    coeffs = new int[1];
    coeffs[0] = 0;
}
POLYNOMIAL::~POLYNOMIAL() {delete[] coeffs;}


// Przeladowane operatory relacyjne
bool operator<(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if (a.getDegree() != b.getDegree()) 
        return a.getDegree() < b.getDegree();

    for (int i = a.getDegree(); i >= 0; --i) 
        if (a.getCoeff(i) != b.getCoeff(i)) 
            return a.getCoeff(i) < b.getCoeff(i);

    return false;
}
bool operator==(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if (a.getDegree() != b.getDegree())
        return false;

    for (int i = 0; i <= a.getDegree(); ++i) 
        if (a.getCoeff(i) != b.getCoeff(i))
            return false;

    return true;
}
bool operator>(const POLYNOMIAL &a, const POLYNOMIAL &b) {return b < a;}
bool operator<=(const POLYNOMIAL &a, const POLYNOMIAL &b) {return !(b < a);}
bool operator>=(const POLYNOMIAL &a, const POLYNOMIAL &b) {return !(a < b);}
bool operator!=(const POLYNOMIAL &a, const POLYNOMIAL &b) {return !(a == b);}


// Przeladowane operatory inkrementacji i dekrementacji
POLYNOMIAL &POLYNOMIAL::operator++() {
    for (int i = 0; i <= degree; ++i)
        ++coeffs[i];

    int wsp_nwd = gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= degree; ++i)
            coeffs[i] /= wsp_nwd;
    
    normalizeDegree();
    return *this;
}
POLYNOMIAL POLYNOMIAL::operator++(int) {
    POLYNOMIAL temp = *this;
    ++(*this);
    return temp;
}
POLYNOMIAL &POLYNOMIAL::operator--() {
    for (int i = 0; i <= degree; ++i)
        --coeffs[i];

    int wsp_nwd = gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= degree; ++i)
            coeffs[i] /= wsp_nwd;
    

    normalizeDegree();
    return *this;
}
POLYNOMIAL POLYNOMIAL::operator--(int) {
    POLYNOMIAL temp = *this;
    --(*this);
    return temp;
}


// Przeladowane operatory wejscia/wyjscia
ostream &operator<<(ostream &os, const POLYNOMIAL &p) {
    os << "( ";
    for (int i = 0; i <= p.getDegree(); ++i) 
        os << p.getCoeff(i) << (i < p.getDegree() ? ", " : " ");
    os << ")";

    return os;
}
istream &operator>>(istream &is, POLYNOMIAL &p) {
    int deg;
    is >> deg;
    p.setDegree(deg);

    for (int i = 0; i <= deg; ++i){
        int val;
        is >> val;
        p.setCoeff(i, val);
    }

    int wsp_nwd = p.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= p.getDegree(); ++i)
            p.setCoeff(i, p.getCoeff(i) / wsp_nwd);
    

    p.normalizeDegree();
    return is;
}


// Przeladowane operatory przesuniec bitowych
POLYNOMIAL POLYNOMIAL::operator<<(int n) const {
    if (n < 0) return POLYNOMIAL();
    if (n == 0) return *this;
    if (n > degree) return POLYNOMIAL();

    int new_deg = degree - n;
    POLYNOMIAL result;
    result.setDegree(new_deg);

    for (int i = 0; i <= new_deg; ++i)
        result.setCoeff(i, coeffs[i + n]);

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.getDegree(); ++i) 
            result.setCoeff(i, result.getCoeff(i) / wsp_nwd);

    result.normalizeDegree();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator>>(int n) const {
    if (n < 0) return POLYNOMIAL();
    if (n == 0) return *this;

    int new_deg = degree + n;
    POLYNOMIAL result;
    result.setDegree(new_deg);

    for (int i = 0; i < n; ++i)
        result.setCoeff(i, 0);

    for (int i = 0; i <= degree; ++i)
        result.setCoeff(i + n, coeffs[i]);

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.getDegree(); ++i) 
            result.setCoeff(i, result.getCoeff(i) / wsp_nwd);
    

    result.normalizeDegree();
    return result;
}


// Przeladowany operator przypisania
POLYNOMIAL &POLYNOMIAL::operator=(const POLYNOMIAL &other) {
    if (this == &other)
        return *this;

    delete[] coeffs;

    degree = other.degree;
    coeffs = new int[degree + 1];
    for (int i = 0; i <= degree; ++i)
        coeffs[i] = other.coeffs[i];

    int wsp_nwd = gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= degree; ++i)
            coeffs[i] /= wsp_nwd;
    
    normalizeDegree();
    return *this;
}


// Przeladowane operatory arytmetyczne
POLYNOMIAL POLYNOMIAL::operator+(const POLYNOMIAL &other) const {
    int max_deg = (degree > other.degree) ? degree : other.degree;
    POLYNOMIAL result;
    result.setDegree(max_deg);

    for (int i = 0; i <= max_deg; ++i){
        int av = (i <= degree) ? coeffs[i] : 0;
        int bv = (i <= other.degree) ? other.coeffs[i] : 0;
        result.coeffs[i] = av + bv;
    }

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] /= wsp_nwd;

    result.normalizeDegree();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator-(const POLYNOMIAL &other) const {
    int max_deg = (degree > other.degree) ? degree : other.degree;
    POLYNOMIAL result;
    result.setDegree(max_deg);

    for (int i = 0; i <= max_deg; ++i){
        int av = (i <= degree) ? coeffs[i] : 0;
        int bv = (i <= other.degree) ? other.coeffs[i] : 0;
        result.coeffs[i] = av - bv;
    }

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] /= wsp_nwd;

    result.normalizeDegree();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator*(const POLYNOMIAL &other) const {
    int new_deg = degree + other.degree;
    POLYNOMIAL result;
    result.setDegree(new_deg);

    for (int i = 0; i <= new_deg; ++i)
        result.coeffs[i] = 0;

    for (int i = 0; i <= degree; ++i)
        for (int j = 0; j <= other.degree; ++j)
            result.coeffs[i + j] += coeffs[i] * other.coeffs[j];

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] /= wsp_nwd;

    result.normalizeDegree();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator-() const {
    POLYNOMIAL result;
    result.setDegree(degree);

    for (int i = 0; i <= degree; ++i)
        result.coeffs[i] = -coeffs[i];

    int wsp_nwd = result.gcd_all();
    if (wsp_nwd > 1)
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] /= wsp_nwd;

    result.normalizeDegree();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator/(const POLYNOMIAL &other) const {
    if (other.degree < 0 || (other.degree == 0 && other.coeffs[0] == 0))
        return POLYNOMIAL();

    int n = degree, m = other.degree;
    if (n < m)
        return POLYNOMIAL();

    Fraction *a = new Fraction[n + 1];
    Fraction *b = new Fraction[m + 1];
    for (int i = 0; i <= n; ++i)
        a[i] = Fraction(coeffs[i]);
    for (int i = 0; i <= m; ++i)
        b[i] = Fraction(other.coeffs[i]);

    int q_deg = n - m;
    Fraction *q = new Fraction[q_deg + 1];
    for (int i = 0; i <= q_deg; ++i)
        q[i] = Fraction(0);

    Fraction *r = new Fraction[n + 1];
    for (int i = 0; i <= n; ++i)
        r[i] = a[i];

    for (int k = n; k >= m; --k){
        if (r[k].is_zero())
            continue;
        Fraction coef = r[k] / b[m];
        q[k - m] = coef;
        for (int j = 0; j <= m; ++j)
            r[k - m + j] = r[k - m + j] - coef * b[j];
    }

    int wsp_mian = 1;
    for (int i = 0; i <= q_deg; ++i)
        wsp_mian = lcm(wsp_mian, q[i].den);

    int *result_coeffs = new int[q_deg + 1];
    for (int i = 0; i <= q_deg; ++i)
        result_coeffs[i] = q[i].num * (wsp_mian / q[i].den);

    int wsp_nwd = 0;
    for (int i = 0; i <= q_deg; ++i)
        wsp_nwd = gcd(wsp_nwd, result_coeffs[i]);
    if (wsp_nwd == 0)
        wsp_nwd = 1;
    for (int i = 0; i <= q_deg; ++i)
        result_coeffs[i] /= wsp_nwd;

    POLYNOMIAL result;
    result.setDegree(q_deg);

    for (int i = 0; i <= q_deg; ++i)
        result.coeffs[i] = result_coeffs[i];

    result.normalizeDegree();

    delete[] a;
    delete[] b;
    delete[] q;
    delete[] r;
    delete[] result_coeffs;
    return result;
}
POLYNOMIAL POLYNOMIAL::operator%(const POLYNOMIAL &other) const {
    if (degree == 0 && coeffs[0] == 0)
        return POLYNOMIAL();

    if (other.degree < 0 || (other.degree == 0 && other.coeffs[0] == 0))
        return *this;

    int n = degree, m = other.degree;
    if (n < m)
        return *this;

    Fraction *a = new Fraction[n + 1];
    Fraction *b = new Fraction[m + 1];
    for (int i = 0; i <= n; ++i)
        a[i] = Fraction(coeffs[i]);
    for (int i = 0; i <= m; ++i)
        b[i] = Fraction(other.coeffs[i]);

    Fraction *r = new Fraction[n + 1];
    for (int i = 0; i <= n; ++i)
        r[i] = a[i];

    for (int k = n; k >= m; --k) {
        if (r[k].is_zero())
            continue;
        Fraction coef = r[k] / b[m];
        for (int j = 0; j <= m; ++j)
            r[k - m + j] = r[k - m + j] - coef * b[j];
    }

    int wsp_mian = 1;
    for (int i = 0; i < m; ++i)
        wsp_mian = lcm(wsp_mian, r[i].den);

    int *result_coeffs = new int[m];
    for (int i = 0; i < m; ++i)
        result_coeffs[i] = r[i].num * (wsp_mian / r[i].den);

    int wsp_nwd = 0;
    for (int i = 0; i < m; ++i)
        wsp_nwd = gcd(wsp_nwd, result_coeffs[i]);
    if (wsp_nwd == 0)
        wsp_nwd = 1;
    for (int i = 0; i < m; ++i)
        result_coeffs[i] /= wsp_nwd;

    POLYNOMIAL result;
    if (m == 0) {
        result.setDegree(0);
        result.coeffs[0] = 0;
    } else {
        result.setDegree(m - 1);
        for (int i = 0; i < m; ++i)
            result.coeffs[i] = result_coeffs[i];
        result.normalizeDegree();
   
        bool all_zero = true;
        for (int i = 0; i <= result.degree; ++i)
            if (result.coeffs[i] != 0)
                all_zero = false;
        if (all_zero) {
            result.setDegree(0);
            result.coeffs[0] = 0;
        }
    }

    delete[] a;
    delete[] b;
    delete[] r;
    delete[] result_coeffs;
    return result;
}


// Przeladowane operatory kompozycyjne
POLYNOMIAL &POLYNOMIAL::operator+=(const POLYNOMIAL &other) {
    *this = *this + other;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator-=(const POLYNOMIAL &other) {
    *this = *this - other;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator*=(const POLYNOMIAL &other) {
    *this = *this * other;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator/=(const POLYNOMIAL &other) {
    *this = *this / other;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator%=(const POLYNOMIAL &other) {
    *this = *this % other;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator<<=(int n) {
    *this = *this << n;
    return *this;
}
POLYNOMIAL &POLYNOMIAL::operator>>=(int n) {
    *this = *this >> n;
    return *this;
}

int POLYNOMIAL::overloaded = 0;
int main() {
    POLYNOMIAL p(3, 1, 3, 4, -1);
    POLYNOMIAL q(2, 6, 8, -7);
    POLYNOMIAL r(3, -1, -3, 1, 2);
    
    r -= p++ += q-- += q -= ++p--;
    
    std::cout << p << std::endl;
    std::cout << q << std::endl;
    std::cout << r << std::endl;

    return 0;
}