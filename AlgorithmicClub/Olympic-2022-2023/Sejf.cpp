//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> pozycje;
vector<long long int> obroty;
vector<long long int> pi;

long long int pierwiastek,wynikg=1e18;

void kmp(string slowo){
    pi.resize(slowo.size());
    pi[0]=0;

    for(int i=1;i<slowo.size();i++){
        int prefiks=pi[i-1];
        while(prefiks>0 && slowo[prefiks]!=slowo[i]){
            prefiks=pi[prefiks-1];
        }
        if(slowo[prefiks]==slowo[i])prefiks++;
        pi[i]=prefiks;
    }

    if(slowo.size()%(slowo.size()-pi[slowo.size()-1])==0){
        pierwiastek=slowo.size()-pi[slowo.size()-1];
    }else{
        pierwiastek=slowo.size();
    }

    return;
}

void podzial_pozostale(int n,long long int suma1,long long int suma2,long long int ilosc1,long long int ilosc2,int podzial){
    long long int koszt=suma1+suma2;
    for(int i=1;i<n;i++){

        ilosc2++;
        ilosc1--;

        koszt=koszt+ilosc2*(pozycje[i]-pozycje[i-1]);
        koszt=koszt-ilosc1*(pozycje[i]-pozycje[i-1]);

     
        while(true){
            int liczba1=0,liczba2=0;
            if(podzial>i){
                liczba1=pozycje[podzial]-pozycje[i];
                liczba2=pierwiastek-pozycje[podzial]+pozycje[i];
            }else{
                liczba1=pierwiastek-pozycje[i]+pozycje[podzial];
                liczba2=pozycje[i]-pozycje[podzial];
            }
            if(liczba1<liczba2){
                ilosc2--;
                ilosc1++;
                koszt=koszt-liczba2+liczba1;
                podzial=(podzial+1)%n;
            }else{
                break;
            }
        }

        wynikg=min(wynikg,koszt);
    }

    return;
}
void podzial_zero(int n){
    long long int wsk1=1,suma1=0,suma2=0,podzial=0;
    while(wsk1<n){
        if(pozycje[wsk1]-pozycje[0]<=pierwiastek+pozycje[0]-pozycje[wsk1]){
            suma1=suma1+(pozycje[wsk1]-pozycje[0]);
        }else{
            if(podzial==0)podzial=wsk1;
            suma2=suma2+(pierwiastek+pozycje[0]-pozycje[wsk1]);
        }
        wsk1++;
    }

    wynikg=min(wynikg,suma1+suma2);
    podzial_pozostale(n,suma1,suma2,podzial,n-podzial,podzial);
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    string slowo;
    cin>>slowo;
    kmp(slowo);

    pozycje.resize(n);

    for(int i=0;i<n;i++){
        cin>>pozycje[i];
        pozycje[i]=pozycje[i]%pierwiastek;
    }

    sort(pozycje.begin(),pozycje.end());

    podzial_zero(n);
    cout<<wynikg;


    


    return 0;
}
 