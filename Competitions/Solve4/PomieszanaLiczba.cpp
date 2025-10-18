//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> licznik(500,0);
vector<int> liczba;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    cin>>slowo;

    for(int i=0;i<slowo.size();i++){
        licznik[slowo[i]]++;
    }
    while(licznik['T']>=1 && licznik['W']>=1 && licznik['O']>=1){
        licznik['T']=licznik['T']-1;
        licznik['O']=licznik['O']-1;
        licznik['W']=licznik['W']-1;
        liczba.push_back(2);
    }
    while(licznik['F']>=1 && licznik['U']>=1 && licznik['R']>=1 && licznik['O']>=1){
        licznik['F']=licznik['F']-1;
        licznik['O']=licznik['O']-1;
        licznik['U']=licznik['U']-1;
        licznik['R']=licznik['R']-1;
        liczba.push_back(4);
    }
    while(licznik['F']>=1 && licznik['I']>=1 && licznik['V']>=1 && licznik['E']>=1){
        licznik['F']=licznik['F']-1;
        licznik['I']=licznik['I']-1;
        licznik['V']=licznik['V']-1;
        licznik['E']=licznik['E']-1;
        liczba.push_back(5);
    }
    while(licznik['E']>=2 && licznik['V']>=1 && licznik['S']>=1 && licznik['N']>=1){
        licznik['E']=licznik['E']-2;
        licznik['V']=licznik['V']-1;
        licznik['S']=licznik['S']-1;
        licznik['N']=licznik['N']-1;
        liczba.push_back(7);
    }
    while(licznik['S']>=1 && licznik['I']>=1 && licznik['X']>=1){
        licznik['S']=licznik['S']-1;
        licznik['I']=licznik['I']-1;
        licznik['X']=licznik['X']-1;
        liczba.push_back(6);
    }
    while(licznik['H']>=1 && licznik['I']>=1 && licznik['G']>=1 && licznik['E']>=1 && licznik['T']>=1){
        licznik['H']=licznik['H']-1;
        licznik['I']=licznik['I']-1;
        licznik['G']=licznik['G']-1;
        licznik['E']=licznik['E']-1;
        licznik['T']=licznik['T']-1;
        liczba.push_back(8);
    }
    while(licznik['E']>=2 && licznik['T']>=1 && licznik['H']>=1 && licznik['R']>=1){
        licznik['E']=licznik['E']-2;
        licznik['T']=licznik['T']-1;
        licznik['H']=licznik['H']-1;
        licznik['R']=licznik['R']-1;
        liczba.push_back(3);
    }
    while(licznik['E']>=1 && licznik['Z']>=1 && licznik['R']>=1 && licznik['O']>=1){
        licznik['E']=licznik['E']-1;
        licznik['O']=licznik['O']-1;
        licznik['Z']=licznik['Z']-1;
        licznik['R']=licznik['R']-1;
        liczba.push_back(0);
    }
    while(licznik['N']>=2 && licznik['I']>=1 && licznik['E']>=1){
        licznik['N']=licznik['N']-2;
        licznik['I']=licznik['I']-1;
        licznik['E']=licznik['E']-1;
        liczba.push_back(9);
    }
    while(licznik['E']>=1 && licznik['N']>=1 && licznik['O']>=1){
        licznik['E']=licznik['E']-1;
        licznik['O']=licznik['O']-1;
        licznik['N']=licznik['N']-1;
        liczba.push_back(1);
    }

    sort(liczba.begin(),liczba.end());
    int indeks=0;
    while(liczba[indeks]==0){
        indeks++;
    }

    if(indeks<liczba.size())cout<<liczba[indeks];
    int indeks2=0;
    while(liczba[indeks2]==0 && indeks2<liczba.size()){
        cout<<liczba[indeks2];
        indeks2++;
    }
    for(int i=indeks+1;i<liczba.size();i++){
        cout<<liczba[i];
    }
    return 0;
}