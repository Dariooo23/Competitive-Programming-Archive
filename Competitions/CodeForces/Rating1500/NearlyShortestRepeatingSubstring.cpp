//Rozwiazanie opiera sie bardziej na teorii liczb niz algorytmach tekstowych

//Wazne spostrzezenia:
//*Zauwazmy ze wszystkie slowa o dlugosci mniejszej badz rownej 10e5 maja malo dzielnikow (Mniej niz 150)
//*Zamiast szukac rozwiazania mozemy dzieki temu poprostu sprawdzic wszystkich kandydatow na nasz wynik

//Rozwiazanie
//*Sprawdzamy wszystkie dzielniki slowa
//*Patrzymy ile wystepuje roznic podczas nakladania prefiksu o dlugosci x na kolejne czesci slowa
//*Robimy to samo z sufiksem (Poniewaz to w prefiksie moze wystepowac ta jedna bledna litera)
//*Jezeli roznic jest mniej niz 2 to mamy wynik
//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int sprawdz(string slowo,int modulo){
    int roznice=0;

    for(int i=0;i<(int)(slowo.size());i++){
        if(slowo[i%modulo]!=slowo[i])roznice++;
    }
    if(roznice<2)return 1;

    roznice=0;
    for(int i=(int)(slowo.size())-1;i>=0;i--){
        if(slowo[(int)(slowo.size())-modulo+(i%modulo)]!=slowo[i])roznice++;
    }
    if(roznice<2)return 1;
    return 0;
}
void solve(){
    int n;
    string slowo;
    cin>>n>>slowo;

    for(int i=1;i<=(int)(slowo.size());i++){
        if((int)(slowo.size())%i==0){
            if(sprawdz(slowo,i)==1){
                cout<<i<<endl;
                return;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 