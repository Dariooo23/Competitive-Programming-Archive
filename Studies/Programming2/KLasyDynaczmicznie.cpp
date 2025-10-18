//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

class Tablica{
    private:
        int* m_tab_i;

    public:
        
        //Gettery
        int get_tab_i(int i) const;
        void get_tab_i(int* i) const;

        //Konstruktory i Destruktor
        Tablica();
        Tablica(int n);
        ~Tablica();
};

Tablica::Tablica() : m_tab_i(new int[3]{1,2,3}){
    return;
}
Tablica::Tablica(int n) : m_tab_i(new int[n]){
    for (int i = 0; i < n; i++){
        m_tab_i[i] = i + 1;
    }
    return;
}
Tablica::~Tablica(){
    delete[] m_tab_i;
    return;
}

int Tablica::get_tab_i(int i) const{
    return m_tab_i[i];
}

void Tablica::get_tab_i(int* i) const{
    *i = m_tab_i[*i];
    return;
}+

int main(){
    Tablica* zmienna = new Tablica(3);

    for (int i = 0; i < 3; i++){
        cout << zmienna->get_tab_i(i) << " ";
    }cout << endl;

    for (int i = 0; i < 3; i++){
        int j = i;
        zmienna->get_tab_i(&j);
        cout << j << " ";
    }cout << endl;

    delete zmienna;



    return 0;
}
