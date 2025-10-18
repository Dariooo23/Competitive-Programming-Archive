//Karol Dziekan
#include <bits/stdc++.h>
#include "cho.h"

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string imie="";
    for(int i=0;i<100;i++){
        imie=imie+'0';
    }

    int indeks=0,
        poprawnosc1=recytuj(imie),
        poprawnosc2=0;
        
    while(indeks<100){
        if(imie[indeks]=='1'){
            imie[indeks]='0';
        }else{
            imie[indeks]='1';
        }
        
        poprawnosc2=recytuj(imie);
        
        if(poprawnosc2<poprawnosc1){
            indeks++;
        }  
        
        poprawnosc1=poprawnosc2;
    }

    for(int i=0;i<100;i++){
        if(imie[i]=='1'){
            imie[i]='0';
        }else{
            imie[i]='1';
        }
    }

    recytuj(imie);

    return 0;
}