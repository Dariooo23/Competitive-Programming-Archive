//Karol Dziekan
#include <iostream>

using namespace std;

int main(){
    int dzielnik=0;
    int dzielna=0;
    int ilosc=0;

    cin>>dzielna>>ilosc;

    while(ilosc>0){
        ilosc=ilosc-1;

        cin>>dzielnik;

        if(((dzielna/dzielnik)*dzielnik)==dzielna){
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }

    return 0;
}