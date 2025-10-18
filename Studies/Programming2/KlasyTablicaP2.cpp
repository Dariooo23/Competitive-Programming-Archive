//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

class Tablica{
    private:
        int m_tab_i[3];

    public:
        Tablica() : m_tab_i{1,2,3}{
            return;
        }
        
        //Gettery
        int get_tab_i(int i) const;
        void get_tab_i(int* i) const;
};

int Tablica::get_tab_i(int i) const{
    return m_tab_i[i];
}

void Tablica::get_tab_i(int* i) const{
    *i = m_tab_i[*i];
    return;
}

int main(){
    Tablica zmienna;
    for (int i = 0; i < 3; i++){
        cout << zmienna.get_tab_i(i) << " ";
    }cout << endl;

    for (int i = 0; i < 3; i++){
        int j = i;
        zmienna.get_tab_i(&j);
        cout << j << " ";
    }cout << endl;



    return 0;
}
