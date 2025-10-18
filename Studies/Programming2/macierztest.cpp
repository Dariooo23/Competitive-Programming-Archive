//Karol Dziekan

#include <bits/stdc++.h>
#include "macierz.hpp"

using namespace std;


int main(){
    /*Macierz<double, 4> m1(10.5);
    Macierz<float, 3> m2(1.1);
    Macierz<int, 4> m3(5);
    Macierz<double, 4> m4(120.6);
    Macierz<float, 3> m5(11.111);
    Macierz<int, 4> m6(34);

    m1.wypisz();
    m2.wypisz();
    m3.wypisz();
    cout << endl;

    m4.dodaj(m1);
    m5.dodaj(m2);
    m6.dodaj(m3);

    m4.wypisz();
    m5.wypisz();
    m6.wypisz();
    cout << endl;*/
    
    Macierz<int, 3> m1;
    Macierz<int, 3> m2;

    cin >> m1 >> m2;

    cout << endl;

    cout << "Przeladowane operatory */+/-" << endl;
    cout << m1 * m2 << endl;
    cout << m1 + m2 << endl;
    cout << m1 - m2 << endl;

    cout << "Post-dekrementacja" << endl;
    cout << m1-- << endl;
    cout << m1 << endl;

    cout << "Pre-dekrementacja" << endl;
    cout << --m1 << endl;
    cout << m1 << endl;

    cout << "Post-inkrementacja" << endl;
    cout << m1++ << endl;
    cout << m1 << endl;

    cout << "Pre-inkrementacja" << endl;
    cout << ++m1 << endl;
    cout << m1 << endl;
    return 0;
}