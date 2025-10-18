//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    
    int ilosc_wsp1 = 0;
    cin >> ilosc_wsp1;
    float wielomian1 [ilosc_wsp1];

    int indeks = 0;
    while(indeks < ilosc_wsp1){
        cin>>wielomian1 [indeks];
        indeks = indeks + 1;
    }

    int ilosc_wsp2 = 0;
    cin >> ilosc_wsp2;
    int wielomian2 [ilosc_wsp2];

    indeks = 0;
    while(indeks < ilosc_wsp2){
        cin>>wielomian2 [indeks];
        indeks = indeks + 1;
    }

    if(ilosc_wsp2 > ilosc_wsp1){
        cout << "0" << endl;

        indeks = 0;
        while(indeks < ilosc_wsp1){
            cout << wielomian1 [indeks] << " ";
            indeks = indeks +1;
        }
    }else{
        float wielomian3 [ilosc_wsp1 - ilosc_wsp2 + 1];

        indeks = ilosc_wsp1;
        while(indeks >= ilosc_wsp2){
            float iloraz = wielomian1 [indeks - 1] / wielomian2 [ilosc_wsp2 - 1];
            wielomian3 [indeks - ilosc_wsp2] = iloraz;

            int indeks_pom1 = ilosc_wsp2;
            int indeks_pom2 = 0;

            while(indeks_pom1 >= 0){
                indeks_pom2 = indeks - (ilosc_wsp2 - indeks_pom1);
                wielomian1 [indeks_pom2] = wielomian1 [indeks_pom2] - iloraz * wielomian2 [indeks_pom1];

                indeks_pom1 = indeks_pom1 - 1;
            }

            indeks = indeks -1;
        }

        indeks = 0;
        while(indeks <= ilosc_wsp1 - ilosc_wsp2){
            cout<< wielomian3 [indeks] << " ";
            indeks = indeks + 1;
        }
        cout<<endl;

        indeks = ilosc_wsp2 - 1;
        while(indeks >= 0 && wielomian1 [indeks] == 0){
            indeks = indeks - 1;
        }

        if(indeks < 0){
            cout << "0";
        }else{
            int indeks_pom = 0;
            while(indeks_pom <= indeks){
                cout << wielomian1 [indeks_pom] << " ";
                indeks_pom = indeks_pom + 1;
            }
        }
    }
    return 0;
}